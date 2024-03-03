package leetcodeMedium

class Solution55 {
    fun canJump(nums: IntArray): Boolean {
        var lastIdx = nums.size - 1

        for (i in nums.size - 2 downTo 0){
            if (i + nums[i] >= lastIdx){
                lastIdx = i
            }
        }

        return lastIdx == 0
    }
}

fun main() {
    val solution = Solution55()

    val result1 = solution.canJump(intArrayOf(3,2,1,0,4))
    println(result1) // Must be false

    val result2 = solution.canJump(intArrayOf(2,3,1,1,4))
    println(result2) // Must be true

}
