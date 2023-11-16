package leetcode

class Solution242 {
    fun isAnagram(s: String, t: String): Boolean {
        val m1 = mutableMapOf<Char, Int>()
        val m2 = mutableMapOf<Char, Int>()

        for (letter in s){
            val lowerCase = letter.lowercaseChar()
            m1[lowerCase] = m1.getOrDefault(lowerCase, 0) + 1
        }

        for (letter in t){
            val lowerCase = letter.lowercaseChar()
            m2[lowerCase] = m2.getOrDefault(lowerCase, 0) + 1
        }

        return m1 == m2
    }
}

fun main(){
    val s = Solution242().isAnagram("anagram", "nagarem")
    println(s)
}