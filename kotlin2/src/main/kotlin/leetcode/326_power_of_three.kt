package leetcode

import kotlin.math.ln
import kotlin.math.log
import kotlin.math.log10

class Solution326 {
    fun isPowerOfThree(n: Int): Boolean {
        if (n <= 0){
            return false
        }

        val log3n = log10(n.toDouble()) / log10(3.0)
        // verifying if its a integer number
        return log3n.toInt().toDouble() == log3n
    }
}

fun main(){
    val s = Solution326().isPowerOfThree(243)
    println("Solution s: $s")
}