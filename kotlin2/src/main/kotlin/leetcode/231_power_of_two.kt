package leetcode

class Solution231 {
    fun isPowerOfTwo(n: Int): Boolean {
        var c = n
        if (n == 1){
            return true
        }
        while (c % 2 == 0){
            c /= 2
        }
        return c == 1
    }

    fun isPowerOfTwo2(n: Int) : Boolean {
        if (n <= 0) {
            return false
        }
        return (n and (n - 1)) == 0
    }
}

fun main(){
    val s = Solution231()
    val output = s.isPowerOfTwo(1023)
    println("Is power of two? ${if (output) "Yes" else "No"}")
}