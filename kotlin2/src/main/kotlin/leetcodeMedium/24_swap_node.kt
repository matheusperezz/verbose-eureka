package leetcodeMedium

import data.ListNode

class Solution24 {
    fun swapPairs(head: ListNode?): ListNode? {
        val dummy = ListNode(0)
        dummy.next = head
        var prevNode: ListNode? = dummy
        var currentNode = head

        while (currentNode?.next != null){
            val firstNode = currentNode
            val secondNode = currentNode.next

            prevNode?.next = secondNode
            firstNode.next = secondNode?.next
            secondNode?.next = firstNode

            prevNode = firstNode
            currentNode = firstNode.next
        }

        return dummy.next
    }
}