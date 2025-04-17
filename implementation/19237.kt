package shark

import java.io.BufferedReader
import java.io.InputStreamReader

class AdultShark(
    val n: Int,
    val m: Int,
    val k: Int,
    val board: Array<IntArray>,
    val heads: IntArray,
    val prefers: Array<Array<IntArray>>
) {
    companion object {
        const val UP = 1
        const val DOWN = 2
        const val LEFT = 3
        const val RIGHT = 4
    }

    val smellBoard = Array(n) { Array(n) { Pair(0, 0) } }
    val sharkPoints = Array(m) { Pair(0, 0) }
    val dx = listOf(-1, 1, 0, 0)
    val dy = listOf(0, 0, -1, 1)

    fun init() {
        for(i in board.indices) {
            for(j in board[i].indices) {
                if(board[i][j] != 0) {
                    sharkPoints[board[i][j] - 1] = Pair(i, j)
                    smellBoard[i][j] = Pair(board[i][j], k)
                }
            }
        }
    }

    fun simulate() {
        var timer = 0
        while (timer < 1001) {
            timer++
            val nextMoves = Array(m) { Pair(-1, -1) }
            // 먼저 이동 방향을 잡는다.
            for (sharkNum in 1..m) {
                val (sharkX, sharkY) = sharkPoints[sharkNum - 1]
                if(sharkX == -1) {
                    continue
                }
                var nowHeading = heads[sharkNum - 1]
                val headList = mutableListOf<Int>()

                for (i in 0..<4) {
                    val newX = sharkX + dx[i]
                    val newY = sharkY + dy[i]

                    if (newX in 0..<n && newY in 0..<n && smellBoard[newX][newY].first == 0) {
                        headList.add(i + 1)
                    }
                }

                if (headList.isEmpty()) {
                    for (i in 0..<4) {
                        val newX = sharkX + dx[i];
                        val newY = sharkY + dy[i]

                        if (newX in 0..<n && newY in 0..<n && smellBoard[newX][newY].first == sharkNum) {
                            headList.add(i + 1)
                        }
                    }
                }

                for (heading in prefers[sharkNum - 1][heads[sharkNum - 1] - 1]) {
                    if (headList.contains(heading)) {
                        nowHeading = heading
                        break
                    }
                }

                var nextX = sharkX + dx[nowHeading - 1]
                var nextY = sharkY + dy[nowHeading - 1]

                if (smellBoard[nextX][nextY].first >= sharkNum || smellBoard[nextX][nextY].first == 0) {
                    heads[sharkNum - 1] = nowHeading
                }

                if(sharkNum > 1) {
                    for(idx in 0..<sharkNum) {
                        if(nextMoves[idx].first == nextX && nextMoves[idx].second == nextY) {
                            nextX = -1
                            nextY = -1
                        }
                    }
                }
                nextMoves[sharkNum - 1] = Pair(nextX, nextY)
            }

            for (i in smellBoard.indices) {
                for (j in smellBoard.indices) {
                    if (smellBoard[i][j].second == 1) {
                        smellBoard[i][j] = Pair(0, 0)
                    } else if (smellBoard[i][j].second in 2..k) {
                        smellBoard[i][j] = Pair(smellBoard[i][j].first, smellBoard[i][j].second - 1)
                    }
                }
            }

            for (i in nextMoves.indices) {
                val (sharkX, sharkY) = nextMoves[i]
                sharkPoints[i] = nextMoves[i]
                if (sharkX != -1 && sharkY != -1) {
                    smellBoard[sharkX][sharkY] = Pair(i + 1, k)
                }
            }

            var flag = 0
            for(i in sharkPoints.indices) {
                if(sharkPoints[i].first == -1) {
                    flag++
                }
            }

            if(flag == m - 1)
                break
        }

        if(timer == 1001) {
            println(-1)
        } else {
            println(timer)
        }
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (n, m, k) = readLine().split(" ").map { it.toInt() }

    val board = Array(n) { readLine().split(" ").map { it.toInt() }.toIntArray() }

    val heads = readLine().split(" ").map { it.toInt() }.toIntArray()

    val prefer = Array(m) { Array(4) { readLine().split(" ").map { it.toInt() }.toIntArray() } }

    val shark = AdultShark(n, m, k, board, heads, prefer)

    shark.init()

    shark.simulate()
}
