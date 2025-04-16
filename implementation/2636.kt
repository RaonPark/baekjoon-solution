package cheese

import java.io.BufferedReader
import java.io.InputStreamReader

class Solution(
    val m: Int,
    val n: Int,
    val board: Array<IntArray>
) {

    var visited = Array(m) { BooleanArray(n) { false } }
    val dx = listOf(0, 1, 0, -1)
    val dy = listOf(1, 0, -1, 0)

    fun findOutside(x: Int, y: Int) {
        val q = ArrayDeque<Pair<Int, Int>>()
        q.addLast(Pair(x, y))
        visited[x][y] = true

        while(!q.isEmpty()) {
            val (nowX, nowY) = q.removeFirst()

            for(j in dx.indices) {
                val cheeseX = nowX + dx[j]
                val cheeseY = nowY + dy[j]

                if(cheeseX in 0..<m && cheeseY in 0..<n && board[cheeseX][cheeseY] != 0) {
                    board[cheeseX][cheeseY] = 2
                }
            }

            for(i in dx.indices) {
                val nextX = nowX + dx[i]
                val nextY = nowY + dy[i]

                if(nextX in 0..<m && nextY in 0..<n && !visited[nextX][nextY] && board[nextX][nextY] == 0) {
                    visited[nextX][nextY] = true
                    q.addLast(Pair(nextX, nextY))
                }
            }
        }
    }

    fun simulation() {
        var timer = 0
        while(true) {
            visited = Array(m) { BooleanArray(n) { false } }
            var counts = 0
            for (i in 0..<m) {
                if (!visited[i][0]) {
                    findOutside(i, 0)
                }
                if (!visited[i][n - 1]) {
                    findOutside(i, n - 1)
                }
            }

            for (j in 0..<n) {
                if (!visited[0][j]) {
                    findOutside(0, j)
                }
                if (!visited[m - 1][j]) {
                    findOutside(m - 1, j)
                }
            }

            timer++
            var nonZero = false
            for (i in 0..<m) {
                for (j in 0..<n) {
                    if (board[i][j] == 2) {
                        board[i][j] = 0
                        counts++
                    } else if (board[i][j] != 0) {
                        nonZero = true
                    }
                }
            }

            if (!nonZero) {
                println(timer)
                println(counts)
                return
            }
        }

    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (m, n) = readLine().split(" ").map { it.toInt() }

    val board = Array(m) { readLine().split(" ").map { it.toInt() }.toIntArray() }

    // 해결법
    // X 에서 시작해서 보더를 찾는다.
    val solution = Solution(m, n, board)

    solution.simulation()
}
