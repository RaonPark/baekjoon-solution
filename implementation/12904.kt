package ab

import java.io.BufferedReader
import java.io.InputStreamReader

class AAndB {
    companion object {
        fun simulate(s: String, t: String): Int {
            if(s.length > t.length)
                return 0
            if(s == t)
                return 1

            if (t.last() == 'A') {
                val newT = t.substring(0, t.length - 1)
                return simulate(s, newT)
            }
            if(t.last() == 'B') {
                val newT = t.substring(0, t.length - 1).reversed()
                return simulate(s, newT)
            }

            return 0
        }
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val s = readLine()
    val t = readLine()

    println(AAndB.simulate(s, t))
}
