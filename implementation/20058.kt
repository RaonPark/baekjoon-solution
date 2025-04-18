package fireball

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.pow

class FireStorm(
    val n: Int,
    val q: Int,
    val board: Array<IntArray>,
    val l: IntArray
) {
    val dx = listOf(0, -1, 0, 1)
    val dy = listOf(-1, 0, 1, 0)
    var counts = 1
    var totalCounts = 0

    fun simulate() {
        for(exec in l.indices) {
            val amount = 2.0.pow(l[exec]).toInt()

            for(i in board.indices step amount) {
                for(j in board[i].indices step amount) {
                    rotate2DArray(i, j, amount)
                }
            }

            val meltedList = mutableListOf<Pair<Int, Int>>()
            for(i in board.indices) {
                for(j in board[i].indices) {
                    if(board[i][j] == 0)
                        continue
                    var flag = 0
                    for(k in dx.indices) {
                        val neighborX = i + dx[k]
                        val neighborY = j + dy[k]
                        if(neighborX !in board.indices || neighborY !in board.indices) {
                            flag++
                        } else if(board[neighborX][neighborY] == 0) {
                            flag++
                        }
                    }
                    if(flag >= 2) {
                        meltedList.add(Pair(i, j))
                    }
                }
            }

            for((x, y) in meltedList) {
                board[x][y]--
            }
        }

        val visited = Array(board.size) { BooleanArray(board.size) { false } }
        var result = 0
        for(i in board.indices) {
            for(j in board[i].indices) {
                if(!visited[i][j] && board[i][j] > 0) {
                    counts = 0
                    dfs(i, j, visited)
                    result = max(counts, result)
                }
            }
        }

        println(totalCounts)
        if(result == 0 || result == 1) {
            println(0)
        } else {
            println(result)
        }
    }

    fun dfs(x: Int, y: Int, visited: Array<BooleanArray>){
        counts++
        totalCounts += board[x][y]
        visited[x][y] = true

        for(i in dx.indices) {
            val nextX = x + dx[i]
            val nextY = y + dy[i]
            if(nextX in board.indices && nextY in board[nextX].indices && !visited[nextX][nextY] && board[nextX][nextY] > 0)
                dfs(nextX, nextY, visited)
        }
    }

    fun rotate2DArray(x: Int, y: Int, amount: Int) {
        // [0, amount), [0, amount)
        // [0, amount), [amount, amount + amount)

        // transpose
        // e.g. x = 0, y = 2
        for(i in 0..<amount) {
            for(j in 0..i) {
                if(i == j) continue
                // e.g. i = 0, j = 1
                val temp = board[x + i][y + j]
                board[x+i][y+j] = board[x + j][y + i]
                board[x + j][y + i] = temp
            }
        }

        // reverse
        for(i in 0..<amount) {
            var lo = 0; var hi = amount - 1
            while(lo <= hi) {
                if(lo != hi) {
                    board[x + i][y + lo] = board[x + i][y + lo] xor board[x + i][y + hi]
                    board[x + i][y + hi] = board[x + i][y + hi] xor board[x + i][y + lo]
                    board[x + i][y + lo] = board[x + i][y + lo] xor board[x + i][y + hi]
                }
                lo++
                hi--
            }
        }
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (n, q) = readLine().split(" ").map { it.toInt() }

    val boardWidth = 2.0.pow(n)
    val board = Array(boardWidth.toInt()) { readLine().split(" ").map { it.toInt() }.toIntArray() }

    val l = readLine().split(" ").map { it.toInt() }.toIntArray()

    val fireStorm = FireStorm(n, q, board, l)
    fireStorm.simulate()
}
