from collections import Counter
from matplotlib import pyplot as plt

num_friends = [100, 49, 41, 40, 25]
friend_counts = Counter(num_friends)
xs = range(101)  # o valor máximo é 100
ys = [friend_counts[x] for x in xs]  # a altura é somente de amigos

plt.bar(xs, ys)
plt.axis([0, 101, 0, 25])
plt.title("Histograma da Contagem de amigos")
plt.xlabel("# de amigos")
plt.ylabel("# de pessoas")
plt.show()
