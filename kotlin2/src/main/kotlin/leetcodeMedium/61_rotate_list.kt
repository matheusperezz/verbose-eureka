package leetcodeMedium

import data.ListNode

class Solution {
    fun rotateRight(head: ListNode?, k: Int): ListNode? {
        if (head?.next == null || k == 0) return head

        var length = 1
        var temp = head
        while (temp?.next != null){
            temp = temp.next
            length++
        }

        temp?.next = head

        val breakAt = length - k % length
        temp = head
        for (i in 1..<breakAt){
            temp = temp?.next
        }

        val newHead = temp?.next
        temp?.next = null

        return newHead
    }
}

fun main(){
    val s = Solution()
    val head = ListNode(1)
    head.next = ListNode(2)
    head.next?.next = ListNode(3)
    head.next?.next?.next = ListNode(4)
    head.next?.next?.next?.next = ListNode(5)
    // 1 2 3 4 5 null
    // 5 1 2 3 4 null
    val k = 4
    val output = s.rotateRight(head, k)
    var temp: ListNode? = output
    while (temp != null){
        print("${temp.`val`} ")
        temp = temp.next
    }
}