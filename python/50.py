class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0 and x != 0:
            return float(1)

        return float(x**n)
        

s = Solution()

x, n = 2.10000, 3
print(s.myPow(x, n))