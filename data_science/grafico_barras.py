from matplotlib import pyplot as plt

movies = ["Annie Hall", "Ben-Hur", "Casablanca", "Gandhi", "West Side Story"]
num_oscars = [5, 11, 3, 8, 10]

# barras possuem o tamanho padrão de 0.8, então adicionaremos 0.1 as
# coordenadas à esquerda para que cada barra seja centralizada

xs = [i for i, _ in enumerate(movies)]
plt.bar(xs, num_oscars)
plt.ylabel("# de Premiações")
plt.xlabel("Filmes")
plt.title("Meus filmes favoritos")

# nomeia o eixo x com nomes de filmes na barra central
plt.xticks([i for i, _ in enumerate(movies)], movies)
plt.show()
