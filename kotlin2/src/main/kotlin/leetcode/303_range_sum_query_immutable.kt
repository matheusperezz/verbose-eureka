package leetcode

class NumArray(nums: IntArray) {
    private val arr = nums
    fun sumRange(left: Int, right: Int): Int {
        var sum = 0
        for (i in left..right) {
            sum += arr[i]
        }
        return sum
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = NumArray(nums)
 * var param_1 = obj.sumRange(left,right)
 */

fun main() {
    val arr = intArrayOf(-2, 0, 3, -5, 2, -1)
    val obj = NumArray(arr)
    val param1 = obj.sumRange(0, 2)
    println("Result: $param1")
}