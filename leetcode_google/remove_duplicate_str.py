def remove_duplicate(s):
    n = len(s) - 1
    for i in range(1, n):
        if s[i] == s[i-1]:
            s = s[:i-1] + s[i+1:]
            return remove_duplicate(s)
    return s

def remove_duplicate_stack(s):
    stack = []
    for char in s:
        if len(stack) and stack[-1] == char:
            stack.pop()
        else:
            stack.append(char)
    return ''.join(stack)



s = "abbaca"
print(remove_duplicate(s))
print(remove_duplicate_stack(s))