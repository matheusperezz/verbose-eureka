package leetcode

class Solution268 {
    fun missingNumber(nums: IntArray): Int {
        val n = nums.size
        var sum = n * (n + 1) / 2

        for (num in nums){
            sum -= num
        }

        return sum
    }
}

fun main(){
    val arr = intArrayOf(1)
    val s = Solution268().missingNumber(arr)
    println(s)
}