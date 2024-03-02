class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        if not matrix:
            return []

        result = []
        row_begin, row_end = 0, len(matrix) - 1
        col_begin, col_end = 0, len(matrix[0]) - 1

        while row_begin <= row_end and col_begin <= col_end:
            # Direita
            for j in range(col_begin, col_end + 1):
                result.append(matrix[row_begin][j])
            row_begin += 1

            # Baixo
            for i in range(row_begin, row_end + 1):
                result.append(matrix[i][col_end])
            col_end -= 1

            # Esquerda
            if row_begin <= row_end:
                for j in range(col_end, col_begin - 1, -1):
                    result.append(matrix[row_end][j])
                row_end -= 1
            
            # Cima
            if col_begin <= col_end:
                for i in range(row_end, row_begin - 1, -1):
                    result.append(matrix[i][col_begin])
                col_begin += 1
            
        return result



s = Solution()
matrix = [
    [1,2,3,4],
    [5,6,7,8],
    [9,10,11,12]
    ]
print(s.spiralOrder(matrix))