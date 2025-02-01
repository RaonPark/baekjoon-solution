package concurrent

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

class Solution3 {
    companion object {
        const val INF = 3_000_000_001L
    }

    fun solve(solution: MutableList<Long>, n: Int) {
        var sum = INF
        var ans = mutableListOf<Long>()
        for(targetIdx in 0..<n - 2) {
            val ret = twoSolution(solution, n, targetIdx)
            if(sum > abs(ret[0] + ret[1] + ret[2])) {
                sum = abs(ret[0] + ret[1] + ret[2])
                ans = ret
            }
        }

        ans.sort()

        println("${ans[0]} ${ans[1]} ${ans[2]}")
    }

    fun twoSolution(solution: MutableList<Long>, n: Int, targetIdx: Int): MutableList<Long> {
        val target = solution[targetIdx]
        var approach = INF
        val ans = mutableListOf(-1L, -1L, -1L)
        for(left in 0..<n - 1) {
            if(left == targetIdx)
                continue
            val leftTarget = solution[left]
            var lo = left + 1; var hi = n - 1

            while(lo <= hi) {
                val mid = lo + (hi - lo) / 2
                val midVal = abs(target + leftTarget + solution[mid])

                if(mid != targetIdx && mid != left && midVal < approach) {
                    approach = midVal
                    ans[0] = target
                    ans[1] = leftTarget
                    ans[2] = solution[mid]
                }

                if(target + leftTarget + solution[mid] < 0) {
                    lo = mid + 1
                } else {
                    hi = mid - 1
                }
            }
        }

        return ans
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt()
    val solution = readLine().split(" ").map { it.toLong() }.toMutableList()

    solution.sort()

    val obj = Solution3()
    obj.solve(solution, n)
}
