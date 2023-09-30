def climbStairs(n: int):
    if n <= 2:
        return n

    # Initialize an array to store the number of ways to reach each step.
    # We start with 0 and 1 step as base cases.
    ways = [0] * (n+1)
    ways[1] = 1
    ways[2] = 2

    for i in range(3, n+1):
        ways[i] = ways[i - 1] + ways[i - 2]

    return ways[n]


result = climbStairs(3)
print(result)
