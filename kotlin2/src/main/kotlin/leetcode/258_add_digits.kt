package leetcode

class Solution258 {
    fun addDigits(num: Int): Int {
        if (num == 0){
            return 0
        } else if (num % 9 == 0){
            return 9
        } else {
            return num % 9
        }
    }
}

fun main(){

}