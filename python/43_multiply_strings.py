class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        n1 = int(num1)
        n2 = int(num2)
        return str((n1 * n2))        


s = Solution()
num1 = "2"
num2 = "3"
print(s.multiply(num1, num2))