package leetcode

class Solution225 {

    val l = mutableListOf<Int>()

    fun push(x: Int) {
        l.add(x)
    }

    fun pop(): Int {
        val temp = l[l.size-1]
        l.removeAt(l.size - 1)
        return temp
    }

    fun top(): Int {
        return l.last()
    }

    fun empty(): Boolean {
        return l.isEmpty()
    }

}