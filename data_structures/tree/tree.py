class TreeNode:
    def __init__(self, val, left=None, right=None) -> None:
        self.val = val
        self.left = left
        self.right = right

    def preorder(self, node):
        if node is None:
            return
        print(node.val, end=' ')
        self.preorder(node.left)
        self.preorder(node.right)
    
    def inorder(self, node):
        if node is None:
            return
        self.inorder(node.left)
        print(node.val, end=' ')
        self.inorder(node.right)
    
    def postorder(self, node):
        if node is None:
            return
        self.postorder(node.left)
        self.postorder(node.right)
        print(node.val, end=' ')
    
    def levelorder(self, root):
        if root is None:
            return
        
        queue = []
        queue.append(root)
        while queue:
            node = queue.pop(0)
            print(node.val, end=' ')

            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)
    

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
insertRecursive(root, 3)
insertRecursive(root, 98)
insertRecursive(root, -23)
insertRecursive(root, 5)
insertRecursive(root, 202)
insertRecursive(root, 0)
print("Preorder")
root.preorder(root)
print()
print("Inorder")
root.inorder(root)
print()
print("Postorder")
root.postorder(root)
print()
print("Levelorder")
root.levelorder(root)
print()