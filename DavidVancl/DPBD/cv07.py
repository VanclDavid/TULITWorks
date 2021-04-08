############PART 1################
# PUT /person
#
# POST /perosn/_doc
# {
#   "name" : "David Vancl",
#   "age" : 21,
#   "description" : "student"
# }
#
# GET /perosn/_doc/fbnssHgBmlLIMswHH9XZ
#
# POST /perosn/_update/fbnssHgBmlLIMswHH9XZ
# {
#   "doc": {
#     "age": 55,
#     "name" : "Pokus Update"
#   }
# }
#
# GET /perosn/_search
#
# DELETE /perosn/_doc/fbnssHgBmlLIMswHH9XZ
#
# DELETE /person
############PART 2################
from elasticsearch import Elasticsearch
from datetime import datetime

INDEX_NAME = 'person'


def print_delimiter(n):
    print('\n', '#' * 10, 'Úloha', n, '#' * 10, '\n')


# Připojení k ES
es = Elasticsearch([{'host': 'localhost', 'port': 9200}])

# Kontrola zda existuje index 'person'
if not es.indices.exists(index=INDEX_NAME):
    # Vytvoření indexu
    es.indices.create(index=INDEX_NAME)

# Index není potřeba vytvářet - pokud neexistuje, tak se automaticky vytvoří při vložení prvního dokumentu

# 1. Vložte osobu se jménem John
print_delimiter(1)
response = es.index(index=INDEX_NAME, id=50, body={
    'name': 'John',
    'age': '18',
    'timestamp': datetime.now()
})
print(response['result'])

# 2. Vypište vytvořenou osobu (pomocí get a parametru id)
print_delimiter(2)
response = es.get(index=INDEX_NAME, id=50)
print(response['_source'])

# 3. Vypište všechny osoby (pomocí search)
print_delimiter(3)
es.indices.refresh(index=INDEX_NAME)
response = es.search(index=INDEX_NAME, body={"query": {"match_all": {}}})
for hit in response['hits']['hits']:
    print("%(name)s %(age)s: %(timestamp)s" % hit["_source"])

# 4. Přejmenujte vytvořenou osobu na 'Jane'
print_delimiter(4)
doc = es.get(index=INDEX_NAME, id=50)
doc['_source']["name"] = "Jane"
response = es.update(index=INDEX_NAME, id=50, body={"doc": doc['_source']})
print(response['result'])

# 5. Smažte vytvořenou osobu
print_delimiter(5)
response = es.delete(index=INDEX_NAME, id=50)
print(response['result'])

# 6. Smažte vytvořený index
print_delimiter(6)
response = es.indices.delete(index=INDEX_NAME, ignore=[400, 404])
print(response['acknowledged'])
