package leetcode

import kotlin.math.ln
import kotlin.math.log10
import kotlin.math.log2

const val guest = 8

fun guess(n: Int) : Int {
    return when {
        n > guest -> -1
        n < guest -> 1
        else -> 0
    }
}

class Solution374 {
    fun guessNumber(n:Int):Int {
        var left = 1
        var right = n

        while (left <= right) {
            val mid = left + (right - left) / 2
            val result = guess(mid)

            when {
                result == 0 -> return mid
                result == -1 -> right = mid - 1
                else -> left = mid + 1
            }
        }

        return -1
    }
}

fun main(){
    val input = 10
    val s = Solution374().guessNumber(input)
    println(s)
}