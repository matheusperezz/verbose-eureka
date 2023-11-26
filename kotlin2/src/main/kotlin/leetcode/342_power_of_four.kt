package leetcode

import kotlin.math.log10

class Solution342 {
    fun isPowerOfFour(n: Int): Boolean {
        val log4n = log10(n.toDouble()) / log10(4.0)
        return log4n % 1.0 == 0.0
    }
}

fun main(){
    val s = Solution342().isPowerOfFour(14)
    println(s)
}