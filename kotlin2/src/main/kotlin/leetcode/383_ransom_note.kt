package leetcode

class Solution383 {
    fun canConstruct(ransomNote: String, magazine: String): Boolean {
        val charCountMap = mutableMapOf<Char, Int>()

        // Count the ocurrency for each char in magazine
        for (char in magazine) {
            charCountMap[char] = charCountMap.getOrDefault(char, 0) + 1
        }

        // Verify if is possible make the ransomNote
        for (char in ransomNote) {
            val count = charCountMap.getOrDefault(char, 0)
            if (count <= 0) {
                return false
            }
            charCountMap[char] = count - 1
        }

        return true
    }
}

fun main(){
    val ransomNote = "a"
    val magazine = "b"
    val output = Solution383().canConstruct(ransomNote, magazine)
    println(output)
}