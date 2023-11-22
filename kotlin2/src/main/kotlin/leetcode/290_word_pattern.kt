package leetcode

class Solution {
    fun wordPattern(pattern: String, s: String): Boolean {
        val words = s.split(" ")

        if (pattern.length != words.size){
            return false
        }

        val charToWord = mutableMapOf<Char, String>()
        val wordToChar = mutableMapOf<String, Char>()
        for ((index, char) in pattern.withIndex()){
            val word = words[index]
            if (charToWord.containsKey(char)){
                if (charToWord[char] != word){
                    return false
                }
            } else {
                charToWord[char] = word
            }

            if (wordToChar.containsKey(word)){
                if (wordToChar[word] != char){
                    return false
                }
            } else {
                wordToChar[word] = char
            }
        }

        return true
    }
}