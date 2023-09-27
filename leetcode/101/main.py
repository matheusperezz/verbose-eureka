class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSymmetric(self, root) -> bool:
        if not root:
            return True
        return self.isMirror(root.left, root.right)

    def isMirror(self, left, right):
        if not left and not right:
            return True
        if not left or not right:
            return False

        return (
            left.val == right.val and
            self.isMirror(left.left, right.right) and
            self.isMirror(left.right, right.left)
        )


root = TreeNode(1)

root.left = TreeNode(2)
root.left.right = TreeNode(3)

root.right = TreeNode(2)
root.right.right = TreeNode(3)

solution = Solution()
output = solution.isSymmetric(root)
print(output)
