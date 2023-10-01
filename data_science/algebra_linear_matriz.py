A = [[1, 2, 3],
     [4, 5, 6]]

B = [[1, 2],
     [3, 4],
     [5, 6]]


def shape(A):
    num_rows = len(A)
    num_cols = len(A[0]) if A else 0  # número de elementos na primeira linha
    return num_rows, num_cols


def get_row(A, i):
    return A[i]


def get_column(A, j):
    return [A_i[j] for A_i in A]


def make_matrix(num_rows, num_cols, entry_fn):
    # retorna a matriz num_rows X num_cols
    # cuja entrada (i, j)th é entry_fn(i,j)
    return [[entry_fn(i, j)             # dado i, cria uma lista
             for j in range(num_cols)]  # [entry_fn(i, 0), ...]
            for i in range(num_rows)]  # cria uma lista para cada i


def is_diagonal(i, j):
    return 1 if i == j else 0

# [[1, 0, 0, 0, 0],
#  [0, 1, 0, 0, 0],
#  [0, 0, 1, 0, 0],
#  [0, 0, 0, 1, 0],
#  [0, 0, 0, 0, 1]]
