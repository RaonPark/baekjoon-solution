package concurrent

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

class Temperature {

}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (n, k) = readLine().split(" ").map { it.toInt() }
    val temp = readLine().split(" ").map { it.toInt() }.toMutableList()

    var lo = 0; var hi = 0; var maxTemp = Int.MIN_VALUE; var temperature = 0
    for(i in 0..<n) {
        temperature += temp[i]
        hi++

        if(hi - lo == k) {
            maxTemp = max(temperature, maxTemp)
            temperature -= temp[lo]
            lo++
        }
    }

    if(hi - lo == k)
        maxTemp = max(temperature, maxTemp)

    println(maxTemp)
}
