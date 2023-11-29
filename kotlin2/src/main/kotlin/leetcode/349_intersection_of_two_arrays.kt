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

    fun intersection2(nums1: IntArray, nums2: IntArray): IntArray {
        val set1 = nums1.toSet()
        val set2 = nums2.toSet()

        return (set1 intersect set2).toIntArray()
    }

    // Best performance
    fun intersection3(nums1: IntArray, nums2: IntArray): IntArray {
        val set1 = HashSet(nums1.asList())
        val set2 = HashSet(nums2.asList())

        return set1.retainAll(set2).let { set1.toIntArray() }
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