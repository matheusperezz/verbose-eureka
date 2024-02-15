package leetcodeMedium

class Solution29 {
    fun divide(dividend: Int, divisor: Int): Int {
        if (dividend == Int.MIN_VALUE && divisor == -1) {
            return Int.MAX_VALUE
        }

        val r = dividend / divisor
        return r
    }

    fun dividePerformance(dividend: Int, divisor: Int): Int {
        if (dividend == Int.MIN_VALUE && divisor == -1) return Int.MAX_VALUE

        val sign = dividend >= 0 == divisor >= 0

        var dividendT = Math.abs(dividend)
        var divisorT = Math.abs(divisor)
        var result = 0
        while (dividendT - divisorT >= 0) {
            var count = 0
            while (dividendT - (divisorT shl 1 shl count) >= 0) {
                count++
            }
            result += 1 shl count
            dividendT -= divisorT shl count
        }

        return if (sign) result else -result
    }
}