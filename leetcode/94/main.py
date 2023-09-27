class TreeNode:
    def __init__(self, val=0, left=None, right=None) -> None:
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inorderTransversal(self, root: TreeNode):
        result = []
        self.inorder(root, result)
        return result

    def inorder(self, node, result):
        if node:
            self.inorder(node.left, result)
            result.append(node.val)
            self.inorder(node.right, result)

    def iterativeInorderTransversal(self, root: TreeNode):
        result = []
        stack = []
        current = root

        while current or stack:
            # move all the nodes to left of the stack
            while current:
                stack.append(current)
                current = current.left

            # Pop in the most left node of stack
            current = stack.pop()
            result.append(current.val)

            # Move to the right subtree
            current = current.right

        return result


root = TreeNode(1)
root.right = TreeNode(2)
root.right.left = TreeNode(3)

solution = Solution()
output = solution.iterativeInorderTransversal(root)
print(output)
