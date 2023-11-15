package leetcode

class Solution234 {
    fun isPalindrome(head: ListNode?): Boolean {
        if (head?.next == null){
            return true
        }

        var slow = head
        var fast = head

        // Find the half of the list
        while (fast?.next != null && fast.next?.next != null){
            slow = slow?.next
            fast = fast.next?.next
        }

        val reversedList = reverseLinkedList(slow?.next)

        var left = head
        var right = reversedList

        while (right != null){
            if (left?.`val` != right.`val`){
                return false
            }
            left = left.next
            right = right.next
        }
        return true
    }

    private fun reverseLinkedList(head: ListNode?): ListNode? {
        var prev: ListNode? = null
        var current = head
        while (current != null){
            val nextNode = current.next
            current.next = prev
            prev = current
            current = nextNode
        }

        return prev
    }
}

fun main(){
    val li1 = ListNode(1)
    val li2 = ListNode(2)
    val li3 = ListNode(2)
    val li4 = ListNode(1)

    li1.next = li2
    li2.next = li3
    li3.next = li4

    val s = Solution234().isPalindrome(li1)
    println(s)
}