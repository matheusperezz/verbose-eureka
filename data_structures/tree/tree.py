class TreeNode:
    def __init__(self, val, left=None, right=None) -> None:
        self.val = val
        self.left = left
        self.right = right

def printTree(root):
    if not root: return
    print(root.val, end=' ')

    printTree(root.left)
    printTree(root.right)

def insertRecursive(node, val):
    if not node:
        return TreeNode(val)
        
    if val <= node.val:
        node.left = insertRecursive(node.left, val)
    else:
        node.right = insertRecursive(node.right, val)
    return node
    
root = TreeNode(80)
insertRecursive(root, 99)
insertRecursive(root, 1)
printTree(root)