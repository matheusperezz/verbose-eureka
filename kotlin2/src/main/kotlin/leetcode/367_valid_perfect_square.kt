package leetcode

class Solution367 {
    fun isPerfectSquare(num: Int): Boolean {
        val sqrt = Math.sqrt(num.toDouble()).toInt()
        return sqrt * sqrt == num
    }
}

fun main() {
    val s = Solution367().isPerfectSquare(100000001)
    println(s)
}