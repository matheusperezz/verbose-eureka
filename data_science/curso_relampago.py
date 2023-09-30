from collections import Counter
import random

# Basicamente é a ocorrência de cada elemento
c = Counter([0, 1, 2, 0, 0])   # c é { 0:3, 1:1, 2:1 }
print(c)

# Dará o mesmo resultado em ambos os prints
random.seed(10)
print(random.random())
random.seed(10)
print(random.random())

# Testando uma classe em Python


class Set:
    # Implementação com Listas
    def __init__(self, values=None) -> None:
        s1 = []
        s2 = [1, 2, 2, 3]
        self.__dict__ = {}
        if values is not None:
            for value in values:
                self.add(value)

    def __repr__(self) -> str:
        # representação da string de um objeto
        return "Set: " + str(self.__dict__.keys())

    def add(self, value):
        self.__dict__[value] = True

    def contains(self, value):
        return value in self.__dict__

    def remove(self, value):
        del self.__dict__[value]


s = Set([1, 2, 3])
s.add(4)
print(s.contains(4))
s.remove(3)
print(s.contains(3))
