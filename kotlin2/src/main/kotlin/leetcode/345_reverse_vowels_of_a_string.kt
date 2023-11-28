package leetcode

class Solution345 {

    private val vowels = setOf(
        'a', 'e', 'i', 'o', 'u',
        'A', 'E', 'I', 'O', 'U'
    )

    fun reverseVowels(s: String): String {
        var str = s.toCharArray()
        var output = ""
        val letters = mutableListOf<Char>()
        val idxs = mutableListOf<Int>()
        s.forEachIndexed { idx, letter ->
            if (vowels.contains(letter)){
                letters.add(letter)
                idxs.add(idx)
            }
        }
        letters.reverse()
        for (i in 0..<idxs.size){
            str[idxs[i]] = letters[i]
        }

        str.forEach {
            output += it
        }
        return output
    }

    fun reverseVowels2(s: String) : String {
        val str = s.toCharArray()
        var left = 0
        var right = str.size - 1

        while (left < right) {
            while (left < right && !vowels.contains(str[left])) {
                left++
            }

            while (left < right && !vowels.contains(str[right])) {
                right--
            }

            // Trocar as vogais nas posições left e right
            val temp = str[left]
            str[left] = str[right]
            str[right] = temp

            left++
            right--
        }

        return String(str)
    }
}

fun main(){
    val input = "aA"
    val s = Solution345().reverseVowels(input)
    println(s)
}