package data

class TreeNode<T : Comparable<T>>(val data: T) {
    var left: TreeNode<T>? = null
    var right: TreeNode<T>? = null
}

class BinaryTree<T : Comparable<T>> {
    var root: TreeNode<T>? = null

    /** Insert Functions **/

    fun insert(data: T) {
        root = insertRecursive(root, data)
    }

    private fun insertRecursive(node: TreeNode<T>?, data: T): TreeNode<T> {
        if (node == null) {
            return TreeNode(data)
        }

        when {
            (data < node.data) -> node.left = insertRecursive(node.left, data)
            (data > node.data) -> node.right = insertRecursive(node.right, data)
            else -> return node
        }

        return node
    }

    /** Display Functions **/

    fun display() {
        displayRecursive(root, 0)
    }

    private fun displayRecursive(node: TreeNode<T>?, level: Int) {
        if (node != null) {
            displayRecursive(node.left, level + 1)
            print("${node.data} ")
            displayRecursive(node.right, level + 1)
        }
    }

    /** Balance Functions **/

    fun balance(){
        val elements = inOrderTransversal(root)
        root = buildBalanceTree(elements, 0, elements.size - 1)
    }

    private fun inOrderTransversal(node: TreeNode<T>?): List<T> {
        val result = mutableListOf<T>()
        if (node != null){
            result.addAll(inOrderTransversal(node.left))
            result.add(node.data)
            result.addAll(inOrderTransversal(node.right))
        }
        return result
    }

    private fun buildBalanceTree(elements: List<T>, start: Int, end: Int): TreeNode<T>? {
        if (start > end){
            return null
        }

        val mid = (start + end) / 2
        val node = TreeNode(elements[mid])
        node.left = buildBalanceTree(elements, start, mid - 1)
        node.right = buildBalanceTree(elements, mid + 1, end)
        return node
    }
}