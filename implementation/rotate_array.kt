package interview

import kotlin.time.measureTime

class Juggling {
    fun rotate(nums: MutableList<Int>, target: Int) {
        val gcd = gcd(target, nums.size)

        for(i in 0..<gcd) {
            val temp = nums[i]
            var j = i

            while(true) {
                var next = j + target
                if(next >= nums.size)
                    next -= nums.size

                if(next == i)
                    break

                nums[j] = nums[next]
                j = next
            }

            nums[j] = temp
        }
    }

    private fun gcd(a: Int, b: Int): Int {
        return if(b == 0)
            a
        else
            gcd(b, a % b)
    }
}

class Rotation {
    fun rotate(nums: MutableList<Int>, target: Int) {
        for(i in 0..<target) {
            val temp = nums[i]
            for(j in 0..<nums.size - 1) {
                nums[j] = nums[j + 1].also { nums[j + 1] = nums[j] }
            }
            nums[nums.lastIndex] = temp
        }
    }
}

class ReverseRotation {
    fun rotate(nums: MutableList<Int>, target: Int) {
        reverse(nums, 0, target - 1)
        reverse(nums, target, nums.size - 1)
        reverse(nums, 0, nums.size - 1)
    }

    private fun reverse(nums: MutableList<Int>, left: Int, right: Int) {
        var lo = left; var hi = right;
        while(lo <= hi) {
            nums[lo] = nums[hi].also { nums[hi] = nums[lo] }
            lo++
            hi--
        }
    }
}

fun main() {
    val nums = mutableListOf<Int>()
    for(i in 1..100001)
        nums.add(i)
    val target = 76394

    val obj2 = Rotation()
    val rotation = measureTime {
        obj2.rotate(nums, target)
    }

    println("Brute Force Algorithm for rotation = $rotation")

    val obj = Juggling()
    val juggling = measureTime {
        obj.rotate(nums, target)
    }

    println("Juggling Algorithm for rotation = $juggling")

    val obj3 = ReverseRotation()
    val reverse = measureTime {
        obj3.rotate(nums, target)
    }

    println("Reverse Rotation Algorithm for rotation = $reverse")
}
