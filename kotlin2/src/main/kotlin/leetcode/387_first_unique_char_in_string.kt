package leetcode

class Solution387 {
    fun firstUniqChar(s: String): Int {
        val map = mutableMapOf<Char, Int>()
        val uniqueLetters = mutableListOf<Char>()
        s.forEach { c ->
            map[c] = map.getOrDefault(c, 0) + 1
        }

        map.forEach { (char, value) ->
            if (value == 1){
                uniqueLetters.add(char)
            }
        }

        return if (uniqueLetters.isNotEmpty()) s.indexOf(uniqueLetters[0]) else -1
    }

    // Improved memory usage and runtime
    fun firstUniqChar2(s: String): Int {
        val map = mutableMapOf<Char, Int>()

        for (c in s){
            map[c] = map.getOrDefault(c, 0) + 1
        }

        for ((index, char) in s.withIndex()){
            if (map[char] == 1){
                return index
            }
        }

        return -1
    }
}

fun main() {
    val input = "leetcode"
    val s = Solution387().firstUniqChar(input)
    println(s)
}