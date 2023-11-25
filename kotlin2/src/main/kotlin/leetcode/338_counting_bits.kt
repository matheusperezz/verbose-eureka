package leetcode

class Solution338 {
    private fun countOnes(s: String): Int {
        return s.count { it == '1' }
    }

    fun countBits(n: Int): IntArray {
        val arr = mutableListOf<Int>()
        for (i in 0..n) {
            arr.add(countOnes(i.toString(2)))
        }
        return arr.toIntArray()
    }

    fun optimalSolution(n: Int): IntArray {
        val result = IntArray(n + 1)

        for (i in 1..n) {
            // dynamic programing technique: result[i] = result[i/2] + (i % 2)
            result[i] = result[i shr 1] + (i and 1)
        }

        return result
    }
}

fun main() {
    val s = Solution338().countBits(5)
    for (i in s) {
        print("$i ")
    }
    println()
}