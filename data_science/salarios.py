from collections import defaultdict

salaries_and_tenures = [(83000, 8.7), (88000, 8.1),
                        (48000, 0.7), (76000, 6),
                        (69000, 6.5), (76000, 7.5),
                        (60000, 2.5), (83000, 10),
                        (48000, 1.9), (63000, 4.2)]

salary_by_tenure = defaultdict(list)

for salary, tenure in salaries_and_tenures:
    salary_by_tenure[tenure].append(salary)

# as chaves são os anos, cada valor é a média salarial para aquele ano
avarage_salary_by_tenure = {
    tenure: sum(salaries)/len(salaries)
    for tenure, salaries in salary_by_tenure.items()
}

# print(f'Salários médio por ano: {avarage_salary_by_tenure}')


# Aqui estamos agrupando os casos
def tenure_bucket(tenure):
    if tenure < 2:
        return "less than two"
    elif tenure < 5:
        return "between two and five"
    else:
        return "more than five"


# as chaves são agrupamentos dos casos, os valores são as listas
# dos salários para aquele agrupamento

salary_by_tenure_bucket = defaultdict(list)

for salary, tenure in salaries_and_tenures:
    bucket = tenure_bucket(tenure)
    salary_by_tenure_bucket[bucket].append(salary)

print(salary_by_tenure_bucket)

# Agora finalmente computar a média salarial para cada grupo
avarage_salary_by_bucket = {
    tenure_bucket: sum(salaries)/len(salaries)
    for tenure_bucket, salaries in salary_by_tenure_bucket.items()
}

print(f'Média de salário por tempo: {avarage_salary_by_bucket}')


def predict_paid_or_unpaid(year_experience):
    if year_experience < 3.0:
        return "paid"
    elif year_experience < 8.5:
        return "unpaid"
    else:
        return "paid"
