package leetcode

class Solution389 {
    fun findTheDifference(s: String, t: String): Char {
        val ls = s.toCharArray().toMutableList()
        val lt = t.toCharArray().toMutableList()
        ls.sort()
        lt.sort()

        var c = lt.last()
        for (i in 0..<ls.size) {
            if (ls[i] != lt[i]) {
                c = lt[i]
                break
            }
        }
        return c
    }

    fun findTheDifference2(s: String, t: String): Char {
        val ls = s.toCharArray()
        val lt = t.toCharArray()
        ls.sort()
        lt.sort()

        return ls.zip(lt).firstOrNull { it.first != it.second }?.second ?: lt.last()
    }
}

fun main() {
    val s = ""
    val t = "y"
    val output = Solution389().findTheDifference(s, t)
    println(output)
}