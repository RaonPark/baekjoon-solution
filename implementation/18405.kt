package competitive

import java.io.BufferedReader
import java.io.InputStreamReader

class Solution(
    val n: Int,
    val k: Int,
    val testTube: Array<IntArray>,
    val s: Int,
    val x: Int,
    val y: Int
){
    val dx = listOf(-1, 0, 0, 1)
    val dy = listOf(0, 1, -1, 0)
    val virusMap = mutableMapOf<Int, MutableList<Pair<Int, Int>>>()

    fun initialize() {
        for(i in testTube.indices) {
            for(j in testTube[i].indices) {
                if(testTube[i][j] != 0) {
                    if(!virusMap.containsKey(testTube[i][j])) {
                        virusMap[testTube[i][j]] = mutableListOf()
                    }
                    virusMap[testTube[i][j]]!!.add(i to j)
                }
            }
        }
    }

    fun simulate() {
        repeat(s) {
            val visited = Array(n) { BooleanArray(n) { false } }
            for(virus in 1..k) {
                val pointList = virusMap[virus] ?: continue

                if(pointList.isEmpty()) {
                    continue
                }

                val nextPoints = mutableListOf<Pair<Int, Int>>()
                for((nowX, nowY) in pointList) {
                    for(i in dx.indices) {
                        val nextX = nowX + dx[i]
                        val nextY = nowY + dy[i]

                        if(nextX in testTube.indices && nextY in testTube[nextX].indices && testTube[nextX][nextY] == 0 && !visited[nextX][nextY]) {
                            visited[nextX][nextY] = true
                            nextPoints.add(nextX to nextY)
                        }
                    }
                }

                for(point in nextPoints) {
                    testTube[point.first][point.second] = virus
                }
                virusMap[virus] = nextPoints
            }
        }

        println(testTube[x - 1][y - 1])
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (n, k) = readLine().split(" ").map { it.toInt() }
    val testTube = Array(n) { readLine().split(" ").map { it.toInt() }.toIntArray() }
    val (s, x, y) = readLine().split(" ").map { it.toInt() }

    val solution = Solution(n, k, testTube, s, x, y)
    solution.initialize()
    solution.simulate()
}

