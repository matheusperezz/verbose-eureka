import data.ListNode
import leetcodeMedium.Solution24

fun main(){
    val s = Solution24()
    val head = ListNode(1)
    head.next = ListNode(2)
    head.next?.next = ListNode(3)
    head.next?.next?.next = ListNode(4)

    println("Lista original:")
    var current: ListNode? = head
    while (current != null) {
        print("${current.`val`} ")
        current = current.next
    }
    println()

    val newHead = s.swapPairs(head)

    println("Lista após troca de pares:")
    current = newHead
    while (current != null) {
        print("${current.`val`} ")
        current = current.next
    }
    println()

}
