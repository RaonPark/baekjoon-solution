package fire

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.ArrayDeque
import kotlin.collections.MutableList
import kotlin.collections.component1
import kotlin.collections.component2
import kotlin.collections.forEach
import kotlin.collections.indices
import kotlin.collections.isNotEmpty
import kotlin.collections.map
import kotlin.collections.mutableListOf

data class Point(val x: Int, val y: Int)

data class Data(val j: Point, val counts: Int)

fun computeFirePoints(firePoints: MutableList<Point>, maze: Array<CharArray>): Array<IntArray> {
    val r = maze.size; val c = maze[0].size

    val q = ArrayDeque<Pair<Point, Int>>()

    val dx = arrayOf(1, 0, -1 ,0)
    val dy = arrayOf(0, 1, 0, -1)
    val visited = Array(r) { IntArray(c) { -1 } }

    firePoints.forEach {
        q.addLast(Pair(it, 0))
        visited[it.x][it.y] = 0
    }

    while(q.isNotEmpty()) {
        val (qFire, counts) = q.removeFirst()

        val fireX = qFire.x
        val fireY = qFire.y

        for (j in dx.indices) {
            val nextFireX = fireX + dx[j]
            val nextFireY = fireY + dy[j]

            if (nextFireX in 0..<r && nextFireY in 0..<c && visited[nextFireX][nextFireY] == -1 && maze[nextFireX][nextFireY] != '#') {
                visited[nextFireX][nextFireY] = counts + 1
                q.addLast(Pair(Point(nextFireX, nextFireY), counts + 1))
            }
        }
    }

    return visited
}

fun bfs(maze: Array<CharArray>, ji: Point, firePoints: MutableList<Point>): Int {
    val r = maze.size; val c = maze[0].size
    val q = PriorityQueue<Data> { lp, rp -> if (lp.counts < rp.counts) -1 else 1 }

    val visited = Array(r) { BooleanArray(c) { false } }
    q.add(Data(ji, 0))

    val dx = arrayOf(1, 0, -1 ,0)
    val dy = arrayOf(0, 1, 0, -1)

    val stageFirePoints = computeFirePoints(firePoints, maze)

    while(!q.isEmpty()) {
        val (jihoon, counts) = q.poll()

        if(jihoon.x == 0 || jihoon.x == r - 1 || jihoon.y == 0 || jihoon.y == c - 1) {
            return counts + 1
        }

        for(i in dx.indices) {
            val nextX = jihoon.x + dx[i]
            val nextY = jihoon.y + dy[i]

            if(nextX in 0..<r && nextY in 0..<c && !visited[nextX][nextY] &&
                (stageFirePoints[nextX][nextY] == -1 || stageFirePoints[nextX][nextY] > counts + 1)
                && maze[nextX][nextY] != '#')
            {
                visited[nextX][nextY] = true
                val nextData = Data(Point(nextX, nextY),counts + 1)

                q.add(nextData)
            }
        }
    }

    return -1
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (r, c) = readLine()!!.split(' ').map { it.toInt() }

    val maze = Array(r) { CharArray(c) { ' ' } }

    val firePoints = mutableListOf<Point>()
    var jihoon = Point(0, 0)
    for(i in 0..<r) {
        val line = readLine()!!

        for(j in 0..<c) {
            maze[i][j] = line[j]
            if(maze[i][j] == 'F') {
                firePoints.add(Point(i, j))
            }
            if(maze[i][j] == 'J') {
                jihoon = Point(i, j)
            }
        }
    }

    val result = bfs(maze, jihoon, firePoints)
    println(if(result == -1) "IMPOSSIBLE" else result)
}
