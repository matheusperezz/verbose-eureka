package leetcodeMedium

class Solution34 {
    fun searchRange(nums: IntArray, target: Int): IntArray {
        val result = IntArray(2)
        result[0] = findFirst(nums, target)
        result[1] = findLast(nums, target)
        return result
    }

    private fun findFirst(nums: IntArray, target: Int): Int {
        var left = 0
        var right = nums.size - 1
        var index = -1
        while (left <= right) {
            val mid = left + (right - left) / 2
            if (nums[mid] >= target) {
                right = mid - 1
            } else {
                left = mid + 1
            }
            if (nums[mid] == target) {
                index = mid
            }
        }
        return index
    }

    private fun findLast(nums: IntArray, target: Int): Int {
        var left = 0
        var right = nums.size - 1
        var index = -1
        while (left <= right) {
            val mid = left + (right - left) / 2
            if (nums[mid] <= target) {
                left = mid + 1
            } else {
                right = mid - 1
            }
            if (nums[mid] == target) {
                index = mid
            }
        }
        return index
    }
}

fun main(){
    val s = Solution34()
    val nums = intArrayOf(5,7,7,8,8,10)
    val target = 8
    val output = s.searchRange(nums, target)
    output.forEach {
        print("$it ")
    }
    println()
}