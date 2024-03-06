package leetcodeMedium

class Solution59 {
    fun generateMatrix(n: Int): Array<IntArray> {
        val matrix = Array(n) { IntArray(n) }
        var counter = 1
        var top = 0
        var bottom = n - 1
        var left = 0
        var right = n - 1

        while (counter <= n * n){
            for (i in left..right){
                matrix[top][i] = counter++
            }
            top++
            for (i in top..bottom){
                matrix[i][right] = counter++
            }
            right--
            for (i in right downTo left){
                matrix[bottom][i] = counter++
            }
            bottom--
            for (i in bottom downTo top){
                matrix[i][left] = counter++
            }
            left++
        }

        return matrix
    }
}

fun main(){
    val s = Solution59()
    val n = 9
    val output = s.generateMatrix(n)
    output.forEach { ints ->
        ints.forEach {
            print("$it ")
        }
        println()
    }
}