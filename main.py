"""
[1,2,3,4,5]
"""

n = 5
res = []
for i in range(0, n+1):
    binary = bin(i)
    binary = binary[2:]
    binary_list = [int(digit) for digit in binary]
    count = binary_list.count(1)
    res.append(count)

print(res)
