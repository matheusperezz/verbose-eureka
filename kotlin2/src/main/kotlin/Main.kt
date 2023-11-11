import data.DoubleLinkedList
import data.LinkedList

fun main() {
    val linkedList = DoubleLinkedList<Int>()

    linkedList.append(3)
    linkedList.append(5)
    linkedList.findPreviousValue(5)
}