def solve(n):
    m = n * 9
    a = m // 10
    b = m % 10
    s = (a+b) - 5
    print(f'n: {n} resultado: {s}')

for i in range(1, 10):
    solve(i)