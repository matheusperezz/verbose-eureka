package leetcode

class Solution263 {
    fun isUgly(n: Int): Boolean {
        var t = n
        while (true) {
            if (t == 1) {
                return true
            }

            if (t == 0) {
                return false
            }

            if (t % 2 == 0) {
                t /= 2
            } else if (t % 3 == 0) {
                t /= 3
            } else if (t % 5 == 0) {
                t /= 5
            } else {
                return false
            }
        }
        return true
    }

    fun isUgly2(n: Int): Boolean {
        var t = n
        if (t <= 0) {
            return false
        }
        val factors = intArrayOf(2, 3, 5)
        for (factor in factors) {
            while (t % factor == 0) {
                t /= factor
            }
        }

        return n == 1 || n == 2 || n == 3 || n == 5
    }
}

fun main() {
    val uglyNumber = 6
    val s = Solution263().isUgly2(uglyNumber)
    println("Is ugly? ${if (s) "yes" else "no"}")
}