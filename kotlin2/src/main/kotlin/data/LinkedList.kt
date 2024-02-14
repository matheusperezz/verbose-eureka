package data

class LinkedListNode<T>(val data: T, var next: LinkedListNode<T>? = null)

class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

class LinkedList<T> {
    var head: LinkedListNode<T>? = null

    fun append(data: T){
        val newLinkedListNode = LinkedListNode(data)
        if (head == null){
            head = newLinkedListNode
            return
        }

        var current = head
        while (current?.next != null){
            current = current.next
        }
        current?.next = newLinkedListNode
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