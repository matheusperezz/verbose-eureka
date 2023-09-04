def myatoi(s)->int:
    
    s = s.lstrip()
    if len(s) == 0:
        return 0
    if s[0] == '-' or s[0] == '+':
        sign = -1 if s[0] == '-' else 1
        s = s[1:]
    else:
        sign = 1
    digits = []
    for c in s:
        if c.isdigit():
            digits.append(c)
        else:
            break
    if len(digits) == 0:
        return 0
    else:
        num = int(''.join(digits))
        num *= sign
    num = max(num, -2**31)
    num = min(num, 2**31 - 1)
    return num


testcase1 = "42"
testcase2 = "   -42"
testcase3 = "words and 987"
testcase4 = "4193 with words"
testcase5 = "   000435"
testcase6 = "-91283472332"
testcase7 = "3.14159"
testcase8 = "+-12"
testcase9 = "-+12"
testcase10 = "21474836460" 
testcase11= "00000-42a1234"

print(f'TestCase 1 -> Input: "{testcase1}" || Output: {myatoi(testcase1)}')
print(f'TestCase 2 -> Input: "{testcase2}" || Output: {myatoi(testcase2)}')
print(f'TestCase 3 -> Input: "{testcase3}" || Output: {myatoi(testcase3)}')
print(f'TestCase 4 -> Input: "{testcase4}" || Output: {myatoi(testcase4)}')
print(f'TestCase 5 -> Input: "{testcase5}" || Output: {myatoi(testcase5)}')
print(f'TestCase 6 -> Input: "{testcase6}" || Output: {myatoi(testcase6)}')
print(f'TestCase 7 -> Input: "{testcase7}" || Output: {myatoi(testcase7)}')
print(f'TestCase 8 -> Input: "{testcase8}" || Output: {myatoi(testcase8)}')
print(f'TestCase 9 -> Input: "{testcase9}" || Output: {myatoi(testcase9)}')
print(f'TestCase 10 -> Input: "{testcase10}" || Output: {myatoi(testcase10)}')
print(f'TestCase 11 -> Input: "{testcase11}" || Output: {myatoi(testcase11)}')