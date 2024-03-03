package leetcodeMedium

import kotlin.math.max
import kotlin.math.min

class Solution56 {
    fun merge(intervals: Array<IntArray>): Array<IntArray> {
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
    val s = Solution56()
    val intervals = arrayOf(intArrayOf(1,4), intArrayOf(4,5))
    val r = s.merge(intervals)
    r.forEach { ints ->
        ints.forEach {
            print("$it ")
        }
        println()
    }
}