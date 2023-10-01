from functools import reduce
import math


def vector_add(v, w):
    # Soma elementos correspondentes
    return [v_i + w_i for v_i, w_i in zip(v, w)]


def vector_subtract(v, w):
    return [v_i - w_i for v_i, w_i in zip(v, w)]


def vector_sum(vectors):
    return reduce(vector_add, vectors)


def scalar_multiply(c, v):
    # c é um número, v é um vetor
    return [c * v_i for v_i in v]


def vector_mean(vectors):
    # computa o vetor cujo i-ésimo elemento seja a média dos
    # i-ésimos elementos dos vetores inclusos
    n = len(vectors)
    return scalar_multiply(1/n, vector_sum(vectors))


def dot(v, w):
    # v_1 * w_1 + ... + v_n * w_n
    return sum(v_i * w_i for v_i, w_i in zip(v, w))


def sum_of_squares(v):
    return dot(v, v)


def magnitude(v):
    # tamanho do vetor
    return math.sqrt(sum_of_squares(v))


def squared_distance(v, w):
    # (v_1 - w_1)² + ... + (v_n - w_n)²
    return sum_of_squares(vector_subtract(v, w))


def distance(v, w):
    return magnitude(vector_subtract(v, w))


v1 = [1, 2]
v2 = [2, 1]
v3 = [5, 2]

v = [v1, v2, v3]

print(magnitude(v1))
