# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isMirror(self, left, right):
        if not left and not right:
            return True
        if not left or not right:
            return False
        return left.val == right.val and self.isMirror(left.left, right.right) and self.isMirror(left.right, right.left)

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        return self.isMirror(root.left, root.right)

def printTree(root):
    if root is None:
        return
    stack = [root]
    while stack:
        curr = stack.pop()
        print(curr.val, end=' ')

        if curr.right:
            stack.append(curr.right)
        if curr.left:
            stack.append(curr.left)

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(4)
root.left.left = TreeNode(6)
printTree(root)