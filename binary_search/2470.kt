package concurrent

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

class Solution2 {
    companion object {
        const val INF = 2_000_000_001L
    }
    fun solve(solution: MutableList<Long>, n: Int) {
        val ans = mutableListOf(-1L, -1L)

        var approach = INF
        for(targetIdx in 0..<n - 1) {
            val target = solution[targetIdx]

            var lo = targetIdx + 1; var hi = n - 1
            while(lo <= hi) {
                val mid = lo + (hi - lo) / 2
                val sum = abs(solution[mid] + target)

                if(sum < approach) {
                    approach = sum
                    ans[0] = target
                    ans[1] = solution[mid]
                }

                if(solution[mid] + target < 0) {
                    // solution[mid] + target 이 음수인 경우에는 solution[mid]가 양수가 되면 절대값이 줄어들으므로
                    // right search
                    lo = mid + 1
                } else {
                    // solution[mid] + target 이 양수인 경우에는 solution[mid]가 음수가 되면 절대값이 줄어들으므로
                    // left search
                    hi = mid - 1
                }
            }
        }

        ans.sort()

        println("${ans[0]} ${ans[1]}")
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt()
    val solution = readLine().split(" ").map { it.toLong() }.toMutableList()

    solution.sort()

    val obj = Solution2()
    obj.solve(solution, n)
}
