package concurrent

import java.io.BufferedReader
import java.io.InputStreamReader

class GoodNumber {
    fun solve(nums: MutableList<Int>, targetIdx: Int, n: Int): Boolean {
        val target = nums[targetIdx]

        for(fix in 0..<n) {
            if(fix == targetIdx)
                continue
            val lowTarget = nums[fix]
            var lo = 0; var hi = n - 1

            while(lo <= hi) {
                val mid = lo + (hi - lo) / 2
                if(mid != targetIdx && fix != mid && lowTarget + nums[mid] == target) {
//                    println("$lowTarget + ${nums[mid]} == $target")
                    return true
                }

                if(lowTarget + nums[mid] < target) {
                    lo = mid + 1
                } else {
                    hi = mid - 1
                }
            }
        }

        return false
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt()
    val nums = readLine().split(" ").map { it.toInt() }.toMutableList()
    val solution = GoodNumber()

    nums.sort()

    var ans = 0
    for(idx in 0..<n) {
        if(solution.solve(nums, idx, n)) {
            ans++
        }
    }

    println(ans)
}
