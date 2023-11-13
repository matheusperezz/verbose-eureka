package leetcode

class Solution228 {
    // Return must be List<String>
    fun summaryRanges(nums: IntArray): List<String> {
        val ranges = mutableListOf<String>()
        val r = mutableListOf<MutableList<Int>>()
        var currentRange = mutableListOf<Int>()

        for (n in nums){
            if (currentRange.isEmpty() || n - currentRange.last() == 1){
                currentRange.add(n)
            } else {
                r.add(currentRange.toMutableList())
                currentRange = mutableListOf(n)
            }
        }

        if (currentRange.isNotEmpty()){
            r.add(currentRange.toMutableList())
        }

        r.forEachIndexed { i, v ->
            if (v.size == 1){
                ranges.add("${v.first()}")
            } else {
                val str = "${v.first()}->${v.last()}"
                ranges.add(str)
            }
        }
        return ranges
    }
}

