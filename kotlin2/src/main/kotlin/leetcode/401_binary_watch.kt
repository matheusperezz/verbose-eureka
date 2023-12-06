package leetcode

class Solution401 {
    fun readBinaryWatch(turnedOn: Int): List<String> {
        val result = mutableListOf<String>()

        for (hour in 0..<12) {
            for (minute in 0..<60) {
                if (Integer.bitCount(hour) + Integer.bitCount(minute) == turnedOn) {
                    result.add(String.format("%d:%02d", hour, minute))
                }
            }
        }

        return result
    }
}

fun main() {

}