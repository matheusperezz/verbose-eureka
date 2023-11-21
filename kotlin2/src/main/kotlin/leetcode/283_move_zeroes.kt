package leetcode

class Solution283 {
    fun moveZeroes(nums: IntArray): Unit {
        var nonZeroIndex = 0
        for (i in nums.indices) {
            if (nums[i] != 0) {
                nums[nonZeroIndex] = nums[i]
                nonZeroIndex++
            }
        }

        for (i in nonZeroIndex until nums.size) {
            nums[i] = 0
        }
    }
}

fun main(){
    val input = intArrayOf(1,0,3,13,0)
    val s = Solution283().moveZeroes(input)
    input.forEach {
        print("$it ")
    }
}