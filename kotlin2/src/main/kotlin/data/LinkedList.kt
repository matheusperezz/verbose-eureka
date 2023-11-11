package data

class ListNode<T>(val data: T, var next: ListNode<T>? = null)

class LinkedList<T> {
    var head: ListNode<T>? = null

    fun append(data: T){
        val newListNode = ListNode(data)
        if (head == null){
            head = newListNode
            return
        }

        var current = head
        while (current?.next != null){
            current = current.next
        }
        current?.next = newListNode
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