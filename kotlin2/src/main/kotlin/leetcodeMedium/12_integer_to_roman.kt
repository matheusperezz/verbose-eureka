package leetcodeMedium

class Solution12 {
    fun intToRoman(num: Int): String {
        val values = intArrayOf(1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1)
        val numerals = arrayOf("M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I")

        var result = ""
        var number = num

        var i = 0
        while (number > 0) {
            val times = number / values[i]
            repeat(times) {
                result += numerals[i]
                number -= values[i]
            }
            i++
        }
        return result
    }
}