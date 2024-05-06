from collections import deque

class Node:
    def __init__(self, val) -> None:
        self.data = val
        self.left = None
        self.right = None
    def bfs(root):
        if root is None: return
        q = deque()
        q.append(root)

        while q:
            curr = q.popleft()
            print(f'Queue: {[node.data for node in q]}')
            print(curr.data, end=' -> ')

            if curr.left:
                q.append(curr.left)

            if curr.right:
                q.append(curr.right)
        


root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
Node.bfs(root)