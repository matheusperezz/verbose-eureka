edges = [[0,3], [1,2], [1,5], [2,4], [3,5], [5,4], [5,0]]
graph = {}
n = len(edges) - 1
matrix = []
for i in range(n):
    row = [0 for _ in range(n)]
    matrix.append(row)

for edge in edges:
    a = edge[0]
    b = edge[1]
    matrix[a][b] = 1

for i in range(n):
    for j in range(n):
        print(matrix[i][j], end=' ')
    print()