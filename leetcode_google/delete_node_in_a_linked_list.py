# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    
def print_list(head):
    curr = head
    while curr != None:
        print(f'{curr.val}', end='->')
        curr = curr.next
    print('None')

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        next_node = node.next
        node.val = next_node.val
        node.next = node.next.next

node1 = ListNode(4)
node2 = ListNode(5)
node3 = ListNode(1)
node4 = ListNode(9)
node1.next = node2
node2.next = node3
node3.next = node4

Solution().deleteNode(node2)

print_list(node1)