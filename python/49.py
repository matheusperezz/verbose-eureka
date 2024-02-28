class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        n_col = len(matrix[0])
        cols = [[] for _ in range(n_col)]

        for row in matrix:
            for idx, element in enumerate(row):
                cols[idx].insert(0, element)

        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                matrix[i][j] = cols[i][j]

    def rotate2(self, matrix: list[list[int]]) -> None:
        n = len(matrix)

        for i in range(n):
            for j in range(i, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        for row in matrix:
            row.reverse()



s = Solution()
matrix = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
'''
[1 2 3]     [7 4 1]
[4 5 6]     [8 5 2]
[7 8 9]     [9 6 3]

'''
s.rotate2(matrix)
print(matrix)

matrix = [
    [5,1,9,11],
    [2,4,8,10],
    [13,3,6,7],
    [15,14,12,16]
]
s.rotate2(matrix)
print(matrix)