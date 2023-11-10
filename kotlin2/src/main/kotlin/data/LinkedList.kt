package data

class Node<T>(val data: T, var next: Node<T>? = null)

class LinkedList<T> {
    var head: Node<T>? = null

    fun append(data: T){
        val newNode = Node(data)
        if (head == null){
            head = newNode
            return
        }

        var current = head
        while (current?.next != null){
            current = current.next
        }
        current?.next = newNode
    }

    fun display(){
        var current = head
        while (current != null){
            print("${current.data} -> ")
            current = current.next
        }
        println("null")
    }
}