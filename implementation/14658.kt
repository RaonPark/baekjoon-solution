package stars

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

data class Point(val x: Int, val y: Int)

// 시작은 별똥별 위치에서 한다.
fun solve(starPoints: MutableList<Point>, n: Int, m: Int, l: Int, k: Int): Int {
    var result = 0
    // 각각 별똥별이 4방향을 이룬다.
    for(i in 0..<k) {
        val starPoint = starPoints[i]
        for(j in 0..<k) {

            val findStar = starPoints[j]

            val rightX = starPoint.x + l
            val upY = findStar.y + l

            var count = 0
            for(nextStar in starPoints) {
                if(nextStar.x in starPoint.x..rightX && nextStar.y in findStar.y..upY) {
                    count++
                }
            }
            result = max(result, count)
        }
    }

    return result
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (n, m, l, k) = readLine()!!.split(' ').map { it.toInt() }

    val starPoints = mutableListOf<Point>()
    repeat(k) {
        val starPoint = readLine()!!.split(' ').map { it.toInt() }
        starPoints.add(Point(starPoint[0], starPoint[1]))
    }

    val result = solve(starPoints, n, m, l, k)

    println(k - result)
}
