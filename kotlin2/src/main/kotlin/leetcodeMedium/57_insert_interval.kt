package leetcodeMedium


class Solution57 {
    fun insert(intervals: Array<IntArray>, newInterval: IntArray): Array<IntArray> {
        val combination = intervals.toMutableList()
        combination.add(newInterval)
        val output = merge(combination.toTypedArray())
        return output
    }

    private fun merge(intervals: Array<IntArray>): Array<IntArray> {
        if (intervals.isEmpty()) return arrayOf()

        intervals.sortBy { it[0] }

        val mergedIntervals = mutableListOf<IntArray>()
        var currentInterval = intervals[0]

        for (i in 1..<intervals.size){
            val interval = intervals[i]

            if (interval[0] <= currentInterval[1]){
                currentInterval[1] = maxOf(currentInterval[1], interval[1])
            } else {
                mergedIntervals.add(currentInterval)
                currentInterval = interval
            }
        }

        mergedIntervals.add(currentInterval)
        return mergedIntervals.toTypedArray()
    }
}

fun main(){
    val s = Solution57()
    val intervals = arrayOf(intArrayOf(1,2), intArrayOf(3,5), intArrayOf(6,7), intArrayOf(8,10), intArrayOf(12,16))
    val newInterval = intArrayOf(4,8)
    val result = s.insert(intervals, newInterval)
    result.forEach { ints ->
        ints.forEach {
            print("$it ")
        }
        println()
    }
}