package leetcode

import java.util.*

class Solution404 {
    fun sumOfLeftLeaves(root: TreeNode?): Int {

        var sum = 0
        val queue: Queue<TreeNode?> = LinkedList()
        queue.offer(root)

        while (queue.isNotEmpty()){
            val current = queue.poll()

            if (current?.left != null && current.left?.left == null && current.left?.right == null) {
                sum += current.left!!.`val`
            }

            current?.left?.let { queue.offer(it) }
            current?.right?.let { queue.offer(it) }
        }

        return sum
    }

}

/**
 *          1
 *        / \
 *       2   3
 *      / \ / \
 *     4  5 6  7
 *
 * **/

fun main() {
    val root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left?.left = TreeNode(4)
    root.left?.right = TreeNode(5)
    root.right?.left = TreeNode(6)
    root.right?.right = TreeNode(7)

    val s = Solution404().sumOfLeftLeaves(root)
    println(s)
}