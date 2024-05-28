"""
AVL Trees
    - Self-balancing binary search tree
    - named after Adelson-Velsky and Landis
    - similar to red-black trees
    - perform fixes after insert and delete
        - height-balanced => longests path to root to a leaf
    - guarantees specific time complexities for operations
        - O(log n) - search, insert, delete

    For any node, the height of its two subtrees differs by at most 1
    balance factor = height of left subtree - height of right subtree
    {-1, 0, 1}

"""
class TreeNode:
    def __init__(self, key) -> None:
        self.key = key
        self.left = None
        self.right = None
        self.height = 1
    

class AVLTree:
    def get_height(self, root):
        if not root:
            return 0
        return root.height
    
    def get_balance(self, root):
        if not root:
            return 0
        return self.get_height(root.left) - self.get_height(root.right)
    
    def left_rotate(self, z):
        y = z.right
        T2 = y.left
        y.left = z
        z.right = T2
        z.height = 1 + max(self.get_height(z.left), self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))
        return y
    
    def right_rotate(self, z):
        y = z.left
        T3 = y.right
        y.right = z
        z.left=  T3
        z.height = 1 + max(self.get_height(z.left), self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))
        return y
    
    def insert(self, root, key):
        if not root:
            return TreeNode(key)
        elif key < root.key:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)

        root.height = 1 + max(self. get_height(root.left), self.get_height(root.right))

        balance = self.get_balance(root)

        if balance > 1 and key < root.left.key:
            return self.right_rotate(root)
        
        if balance < -1 and key > root.right.key:
            return self.left_rotate(root)
        
        if balance > 1 and key > root.left.key:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)
        
        if balance < -1 and key < root.right.key:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)

        return root
    
    def pre_order(self, root):
        if not root:
            return
        print(f'{root.key} ', end='')
        self.pre_order(root.left)
        self.pre_order(root.right)


avl_tree = AVLTree()
root = None
keys = [10, 20, 30, 40, 50, 25]

for key in keys:
    root = avl_tree.insert(root, key)

print("Preorder traversal da árvore AVL construída é:")
avl_tree.pre_order(root)
