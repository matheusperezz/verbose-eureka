package leetcode

import java.util.*

class Solution257 {

    data class NodeWithPath(val node: TreeNode?, val path: List<Int?>)

    fun binaryTreePaths2(root: TreeNode?): List<String> {
        val stack = Stack<NodeWithPath>()
        val pathsNodeToLeaf = mutableListOf<List<Int?>>()
        stack.push(NodeWithPath(root, emptyList()))

        while (stack.isNotEmpty()){
            val currentNodeWithPath = stack.pop()
            val currentNode = currentNodeWithPath.node
            val currentPath = currentNodeWithPath.path + currentNode?.`val`

            if (currentNode?.left == null && currentNode?.right == null){
                pathsNodeToLeaf.add(currentPath)
            }

            currentNode?.right?.let { stack.push(NodeWithPath(it, currentPath)) }
            currentNode?.left?.let { stack.push(NodeWithPath(it, currentPath)) }
        }

        val listStringOutput = mutableListOf<String>()

        for (v in pathsNodeToLeaf){
            var str = ""
            v.forEach {
                str += "$it->"
            }
            listStringOutput.add(str.substring(0, str.length - 2))
            str = ""
        }

        return listStringOutput
    }

    fun binaryTreePaths(root: TreeNode?): List<String> {
        val result = mutableListOf<String>()
        if (root != null) {
            traverse(root, "", result)
        }
        return result
    }

    private fun traverse(node: TreeNode, path: String, result: MutableList<String>) {
        val currentPath = if (path.isEmpty()) "${node.`val`}" else "$path->${node.`val`}"

        if (node.left == null && node.right == null) {
            result.add(currentPath)
        }

        node.left?.let { traverse(it, currentPath, result) }
        node.right?.let { traverse(it, currentPath, result) }
    }
}

fun main() {
    val n1 = TreeNode(1)
    val n2 = TreeNode(2)
    val n3 = TreeNode(3)
    val n4 = TreeNode(5)

    n1.left = n2
    n1.right = n3
    n2.left = n4

    val s = Solution257().binaryTreePaths(n1)
    println(s)

}