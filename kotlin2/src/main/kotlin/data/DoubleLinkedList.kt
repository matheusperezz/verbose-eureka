package data

class DoubleListNode<T>(
    val data: T,
    var prev: DoubleListNode<T>? = null,
    var next: DoubleListNode<T>? = null
)

class DoubleLinkedList<T> {
    var head: DoubleListNode<T>? = null

    fun append(data: T){
        val newNode = DoubleListNode(data)
        if (head == null){
            head = newNode
            return
        }

        var current = head
        while (current?.next != null){
            current = current.next
        }
        current?.next = newNode
        current?.next?.prev = current
    }

    fun display() {
        var current = head
        while (current != null){
            print("${current.data} -> ")
            current = current.next
        }
        println("null")
    }

    fun findPreviousValue(data: T){
        var current = head
        while (current != null){
            if (current.data == data){
                println("Value found!, previous one is: ${current.prev?.data}")
                return
            }
            current = current.next
        }
        println("Nothing founded!")
    }
}
