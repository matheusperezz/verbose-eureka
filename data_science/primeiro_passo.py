from __future__ import division
from collections import Counter
from collections import defaultdict

users = [
    {"id":0, "name":"Hero"},
    {"id":1, "name":"Dunn"},
    {"id":2, "name":"Sue"},
    {"id":3, "name":"Chi"},
    {"id":4, "name":"Thor"},
    {"id":5, "name":"Clive"},
    {"id":6, "name":"Hicks"},
    {"id":7, "name":"Devin"},
    {"id":8, "name":"Kate"},
    {"id":9, "name":"Klein"}
]

# Isso representa um grafo
friendship = [(0,1), (0,2), (1,2), (1,3), (2,3), (3,4),
              (4,5), (5,6), (5,7), (6,8), (7,8), (8,9)]

# Criando uma lista de amigos para cada user
for user in users:
    user["friends"] = []

# Povoando a lista de amigos com dados
for i, j in friendship:
    users[i]["friends"].append(users[j])
    users[j]["friends"].append(users[i])

def number_of_friends(user):
    # Quantos amigos o usuário tem?
    return len(user["friends"])

# Levando em consideração que a conexão é bipartida
total_connections = sum(number_of_friends(user) for user in users)
print(f'Conexões totais: {total_connections}')

# Média de amigos por pessoa
num_users = len(users)
avg_connections = total_connections / num_users
print(avg_connections)

# Agora vamos classificar pessoas que tem "muitos" e "poucos" amigos
num_friends_by_id = [(user["id"], number_of_friends(user)) for user in users]
sorted(num_friends_by_id, key=lambda x: x[1], reverse=True)

print(num_friends_by_id)

# Talvez você conheça

def friends_of_friends_ids_bad(user):
    # "foaf" é abreviação de "friend of a friend"
    return [foaf["id"]
            for friend in user["friends"]
            for foaf in friend["friends"]]


def not_the_same(user, other_user):
    # Dois usuários não são os mesmos se possuem ids diferentes
    return user["id"] != other_user["id"]

def not_friends(user, other_user):
    # other_user não é um amigo se não está em user["friends"]
    # isso é, se é not_the_same com todas as pessoas em user["friends"]
    return all(not_the_same(friend, other_user)
               for friend in user["friends"])

def friends_of_friend_ids(user):
    return Counter(foaf["id"]
                   for friend in user["friends"]    # para cada um dos meus amigos
                   for foaf in friend["friends"]    # que contam *their* amigos
                   if not_the_same(user, foaf)      # que não sejam eu 
                   and not_friends(user, foaf))     # e que não são meus amigos

print(f'Amigos de amigos: {friends_of_friend_ids(users[3])}')

# Interesses similares

interests = [
(0, "Hadoop"), (0, "Big Data"), (0, "HBase"), (0, "Java"),
(0, "Spark"), (0, "Storm"), (0, "Cassandra"),
(1, "NoSQL"), (1, "MongoDB"), (1, "Cassandra"), (1, "HBase"),
(1, "Postgres"), (2, "Python"), (2, "scikit-learn"), (2, "scipy"),
(2, "numpy"), (2, "statsmodels"), (2, "pandas"), (3, "R"), (3, "Python"),
(3, "statistics"), (3, "regression"), (3, "probability"),
(4, "machine learning"), (4, "regression"), (4, "decision trees"),
(4, "libsvm"), (5, "Python"), (5, "R"), (5, "Java"), (5, "C++"),
(5, "Haskell"), (5, "programming languages"), (6, "statistics"),
(6, "probability"), (6, "mathematics"), (6, "theory"),
(7, "machine learning"), (7, "scikit-learn"), (7, "Mahout"),
(7, "neural networks"), (8, "neural networks"), (8, "deep learning"),
(8, "Big Data"), (8, "artificial intelligence"), (9, "Hadoop"),
(9, "Java"), (9, "MapReduce"), (9, "Big Data")
]

def data_scientists_who_like(target_interest):
    return [user_id
        for user_id, user_interest in interests
        if user_interest == target_interest]

"""
Funciona, mas a lista inteira de interesses deve ser examinada para cada busca
se tivermos muitos users e interests seria melhor um índice de interesse
para usuários

As chaves são interesses, os valores são listas de user_ids com interesses
"""
user_ids_by_interest = defaultdict(list)

for user_id, interest in interests:
    user_ids_by_interest[interest].append(user_id)

# E outro de usuários para interesses:
interest_by_user_id = defaultdict(list)
for  user_id, interest in interests:
    interest_by_user_id[user_id].append(interest)

"""
Agora para descobrir quem possui os maiores interesses em comum com um
certo usuário:

- Itera sobre os interesses do usuário
- Para cada interesse, itera sobre os outros usuários com aquele interesse
- Mantém a contagem de quantas vezes vemos cada outro usuário
"""

def most_commom_interest_with(user):
    return Counter(interested_user_id
        for interest in interest_by_user_id[user["id"]]
        for interested_user_id in user_ids_by_interest[interest]
        if interested_user_id != user["id"]
    )

print(f'Lista de interesses: {interest_by_user_id}')
print(f'Interesses em comum com o usuário 0 Hero: {most_commom_interest_with(users[0])}')