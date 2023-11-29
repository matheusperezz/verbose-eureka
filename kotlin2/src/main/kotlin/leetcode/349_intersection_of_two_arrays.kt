package leetcode

class Solution349 {
    fun intersection(nums1: IntArray, nums2: IntArray): IntArray {
        val s = mutableListOf<Int>()
        nums1.forEach { i ->
            if (nums2.contains(i)) {
                s.add(i)
            }
        }
        return s.distinct().toIntArray()
    }
}

fun main(){
    val input1 = intArrayOf(4,9,5)
    val input2 = intArrayOf(9,4,9,8,4)
    val s = Solution349().intersection(input1, input2)
    s.forEach {
        println(it)
    }
}