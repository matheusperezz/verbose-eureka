class RBNode:
    def __init__(self, key, color='R') -> None:
        self.key = key
        self.color = color
        self.left = None
        self.right = None
        self.parent = None
    

class RBTree:
    def __init__(self) -> None:
        self.TNULL = RBNode(0)
        self.TNULL.color = 'B'
        self.root = self.TNULL
    
    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left != self.TNULL:
            y.left.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self, x):
        y = x.left
        x.left = y.right
        if y.right != self.TNULL:
            y.right.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y
    
    def insert_fix(self, k):
        while k.parent.color == 'R':
            if k.parent == k.parent.parent.right:
                u = k.parent.parent.left
                if u.color == 'R':
                    u.color = 'B'
                    k.parent.color = 'B'
                    k.parent.parent.color = 'R'
                    k = k.parent.parent
                else:
                    if k == k.parent.left:
                        k = k.parent
                        self.right_rotate(k)
                    k.parent.color = 'B'
                    k.parent.parent.color = 'R'
                    self.left_rotate(k.parent.parent)
            else:
                u = k.parent.parent.right
                if u.color == 'R':
                    u.color = 'B'
                    k.parent.color = 'B'
                    k.parent.parent.color = 'R'
                    k = k.parent.parent
                else:
                    if k == k.parent.right:
                        k = k.parent
                        self.right_rotate(k.parent.parent)
            if k == self.root:
                break
        self.root.color = 'B' 

    def insert(self, key):
        node = RBNode(key)
        node.parent = None
        node.key = key
        node.left = self.TNULL
        node.right = self.TNULL
        node.color = 'R'

        y = None
        x = self.root

        while x != self.TNULL:
            y = x
            if node.key < x.key:
                x = x.left
            else:
                x = x.right

        node.parent = y
        if y is None:
            self.root = node
        elif node.key < y.key:
            y.left = node
        else:
            y.right = node
        
        if node.parent is None:
            node.color = 'B'
            return
        
        if node.parent.parent is None:
            return
        
        self.insert_fix(node)

    def pre_order(self, node):
        if node != self.TNULL:
            print(f"{node.key} ", end='')
            self.pre_order(node.left)
            self.pre_order(node.right)

rb_tree = RBTree()
keys = [10, 20, 30, 40, 50, 25]

for key in keys:
    rb_tree.insert(key)

print("Preorder traversal da arvore rubro-negra construida é: ")
rb_tree.pre_order(rb_tree.root)