package leetcode

class Solution263 {
    fun isUgly(n: Int): Boolean {
        var t = n
        while (true){
            if (t == 1){
                return true
            }

            if (t == 0){
                return false
            }

            if (t % 2 == 0){
                t /= 2
            } else if (t % 3 == 0){
                t /= 3
            } else if (t % 5 == 0){
                t /= 5
            } else {
                return false
            }
        }
        return true
    }
}

fun main(){
    val uglyNumber = 0
    val s = Solution263().isUgly(uglyNumber)
    println("Is ugly? ${if (s) "yes" else "no"}")
}