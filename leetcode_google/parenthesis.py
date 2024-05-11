class Solution:
    def generateParenthesisHelper(self, result, current, open, close, n):
        if len(current) == 2 * n:
            result.append(current)
            return
        
        if open < n:
            print(f'current open < n -> {current + '('}')
            self.generateParenthesisHelper(result, current + '(', open+1, close, n)
        
        if close < open:
            print(f'current close < open -> {current + ')'}')
            self.generateParenthesisHelper(result, current + ')', open, close+1, n)
    
    def generateParenthesis(self, n: int) -> list[str]:
        result = []
        self.generateParenthesisHelper(result, "", 0, 0, n)
        return result
    
n = 3
s = Solution().generateParenthesis(n)
print(s)