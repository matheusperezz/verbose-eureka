class Node:
    def __init__(self, val) -> None:
        self.data = val
        self.left = None
        self.right = None

def dfs(node):
    if node is None:
        return

    print(node.data, end=' ') # Visit the node
    if node.left:
        dfs(node.left)
    if node.right:
        dfs(node.right)

class Graph:
    def __init__(self):
        self.graph = {}
    
    def add_edge(self, u, v):
        if u not in self.graph:
            self.graph[u] = []
        self.graph[u].append(v)
    
    def dfs_util(self, v, visited):
        visited.add(v)
        print(v, end=" ")

        if v in self.graph:
            for neighbor in self.graph[v]:
                if neighbor not in visited:
                    self.dfs_util(neighbor, visited)
    
    def dfs(self, start):
        visited = set()
        self.dfs_util(start, visited)

"""

"""

g = Graph()
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 0)
g.add_edge(2, 3)
g.add_edge(3, 3)

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

print("DFS in the binary tree")
dfs(root)