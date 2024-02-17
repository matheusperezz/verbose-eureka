package leetcodeMedium

class Solution36 {
    fun isValidSudoku(board: Array<CharArray>): Boolean {
        val rows = Array(9) { BooleanArray(9) }
        val columns = Array(9) { BooleanArray(9) }
        val boxes = Array(9) { BooleanArray(9) }

        for (i in 0..<9) {
            for (j in 0..<9) {
                if (board[i][j] != '.') {
                    val num = board[i][j] - '1'
                    val k = (i / 3) * 3 + j / 3
                    if (rows[i][num] || columns[j][num] || boxes[k][num]) {
                        return false
                    }
                    rows[i][num] = true
                    columns[j][num] = true
                    boxes[k][num] = true
                }
            }
        }
        return true
    }
}

fun main(){
    val s = Solution36()
    val board = arrayOf(
        charArrayOf('5','3','.','.','7','.','.','.','.'),
        charArrayOf('6','.','.','1','9','5','.','.','.'),
        charArrayOf('.','9','8','.','.','.','.','6','.'),
        charArrayOf('8','.','.','.','6','.','.','.','3'),
        charArrayOf('4','.','.','8','.','3','.','.','1'),
        charArrayOf('7','.','.','.','2','.','.','.','6'),
        charArrayOf('.','6','.','.','.','.','2','8','.'),
        charArrayOf('.','.','.','4','1','9','.','.','5'),
        charArrayOf('.','.','.','.','8','.','.','7','9')
    )
    val o = s.isValidSudoku(board)
    println("é válido? $o")
}