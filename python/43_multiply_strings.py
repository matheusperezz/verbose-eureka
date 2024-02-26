class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        n1 = int(num1)
        n2 = int(num2)
        return str((n1 * n2))
    
    def multiply2(self, num1: str, num2: str) -> str:
        if num1 == '0' or num2 == '0':
            return '0'
        
        # init a empty list with the size of two numbers to contains the result of multiply
        result = [0] * (len(num1) + len(num2))

        for i in reversed(range(len(num1))):
            for j in reversed(range(len(num2))):
                mul = (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0'))
                total = mul + result[i +j + 1]

                # update the digits
                result[i +j + 1] = total % 10
                result [i + j] += total // 10

        result_str = ''.join(map(str, result))
        result_str = result_str.lstrip('0')

        return result_str if result_str else '0' 



s = Solution()
num1 = "2"
num2 = "3"
print(s.multiply(num1, num2))