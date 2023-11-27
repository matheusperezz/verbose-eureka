package leetcode

class Solution344 {
    fun reverseString(s: CharArray): Unit {
        var left = 0
        var right = s.size-1
        while (left != s.size/2){
            val t = s[left]
            s[left] = s[right]
            s[right] = t
            left++
            right--
        }
    }
}

fun main() {
    val input = charArrayOf('h', 'e', 'l', 'l', 'o')
    Solution344().reverseString(input)
    println(input)
}