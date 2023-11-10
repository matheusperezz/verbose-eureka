import data.BinaryTree
import data.LinkedList

fun main() {
    val linkedList = LinkedList<Int>()
    linkedList.append(1)
    linkedList.append(2)
    linkedList.append(3)

    linkedList.display()

    println("Normal Tree")

    val tree = BinaryTree<Int>()

    tree.insert(1)
    tree.insert(3)
    tree.insert(5)
    tree.insert(2)
    tree.insert(9)
    tree.insert(13)
    tree.insert(0)

    tree.display()

    tree.balance()

    println("\nBalanced Tree")
    tree.display()
}