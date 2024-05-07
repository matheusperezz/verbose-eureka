class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def invert_binarytree(node):
    if node is None:
        return None
    node.left, node.right = invert_binarytree(node.right), invert_binarytree(node.left)
    return node


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
root = invert_binarytree(root)
printTree(root)