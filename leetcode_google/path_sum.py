class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def all_paths(root, targetSum):
    paths = []

    def dfs(node, current_path):
        if node is None:
            return
        current_path.append(node.val)
        if node.left is None and node.right is None:
            path_list = list(current_path)
            if sum(path_list) == targetSum:
                paths.append(list(current_path))
        else:
            dfs(node.left, current_path)
            dfs(node.right, current_path)
        
        current_path.pop()
    
    dfs(root, [])
    return paths

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

root = TreeNode(5)

root.left = TreeNode(4)
root.right = TreeNode(8)

root.left.left = TreeNode(11)
root.right.left = TreeNode(13)
root.right.right = TreeNode(4)

root.left.left.left = TreeNode(7)
root.left.left.right = TreeNode(2)

root.right.right.left = TreeNode(5)
root.right.right.right = TreeNode(1)

result = all_paths(root, 22)

print(result)
