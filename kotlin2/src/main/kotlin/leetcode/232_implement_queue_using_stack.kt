package leetcode

import java.util.Stack

class MyQueue() {

    val s1: Stack<Int> = Stack()

    fun push(x: Int) {
        if (s1.empty()){
            s1.push(x)
            println("Stack: $s1")
            return
        }
        val auxStack = Stack<Int>()
        // Moving the elements to aux stack
        while (s1.isNotEmpty()){
            auxStack.push(s1.pop())
        }

        // Inserting the new element on the top of original stack
        s1.push(x)

        // Moving the elements back to the original stack
        while (auxStack.isNotEmpty()) {
            s1.push(auxStack.pop())
        }

        println("Stack: $s1")
    }

    fun pop(): Int {
        return s1.pop()
    }

    fun peek(): Int {
        return s1.peek()
    }

    fun empty(): Boolean {
        return s1.isEmpty()
    }

}

fun main(){
    val s = MyQueue()
    s.push(2)
    s.push(3)
    s.push(4)

    s.pop()
    println("Queue after poping: ${s.s1}")

    println("Queue peek: ${s.peek()}")

    println("Is the queue empty? ${if (s.empty()) "Yes" else "No"}")
}