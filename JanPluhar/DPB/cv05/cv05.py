from init import collection

print(collection.find_one())

'''
DPB - 5. Cvičení

Implementujte jednotlivé body pomocí PyMongo knihovny - rozhraní je téměř stejné jako v Mongo shellu.
Před testováním Vašich řešení si nezapomeňte zapnout Mongo v Dockeru.

Pro pomoc je možné např. použít https://www.w3schools.com/python/python_mongodb_getstarted.asp

Funkce find vrací kurzor - pro vypsání výsledku je potřeba pomocí foru iterovat nad kurzorem:

cursor = collection.find(...)
for restaurant in cursor:
    print(restaurant) # případně print(restaurant['name'])

Všechny výsledky limitujte na 10 záznamů. Nepoužívejte české názvy proměnných!
'''


def print_delimiter(n):
    print('\n', '#' * 10, 'Úloha', n, '#' * 10, '\n')


def print_query(result):
    for x in result:
        print(x)


# 1. Vypsání všech restaurací - pouze názvů, abecedně seřazených
print_delimiter(1)
print_query(collection.find({}, {"_id": 0, "name": 1}).sort("name", 1).limit(10))

# 2. Zobrazte dalších 10 záznamů
print_delimiter(2)
print_query(collection.find({}, {"_id": 0, "name": 1}).sort("name", 1).skip(10).limit(10))

# 3. #Vypsání restaurací ve čtvrti Bronx (čtvrť = borough)
print_delimiter(3)
print_query(collection.find({"borough": "Bronx"}).limit(10))

# 4. Vypsání restaurací, jejichž název začíná na písmeno M
print_delimiter(4)
print_query(collection.find({"name": {"$regex": "^M"}}, {"name": 1, "_id": 0}).limit(10))

# 5. Vypsání restaurací, které mají skóre větší než 80
print_delimiter(5)
print_query(collection.find({"grades": {"$elemMatch": {"score": {"$gt": 80}}}}, {"name": 1, "_id": 0}).limit(10))

# 6. Vypsání restaurací, které mají skóre mezi 80 a 90
print_delimiter(6)
print_query(
    collection.find({"grades": {"$elemMatch": {"score": {"$gt": 80, "$lt": 90}}}}, {"name": 1, "_id": 0}).limit(10))
'''
V této části budete opět vytvářet vlastní restauraci.

Řešení:
Vytvořte si vaši restauraci pomocí slovníku a poté ji vložte do DB.
restaurant = {
    ...
}
'''

# 7. Uložte novou restauraci (stačí vyplnit název a adresu)
print_delimiter(7)
restaurant = {
    "address": {
        "building": "666",
        "coord": [
            -73.856077,
            40.848447
        ],
        "street": "Mars Park Ave",
        "zipcode": "666"
    },
    "name": "Doom Slayer's Steak house",
    "restaurant_id": "30000666"
}
collection.insert_one(restaurant)

# 8. Vypište svoji restauraci
print_delimiter(8)
print_query(collection.find({"name": "Doom Slayer's Steak house"}).limit(10))

# 9. Aktualizujte svoji restauraci - změňte libovolně název
print_delimiter(9)
collection.update_one({"name": "Doom Slayer's Steak house"}, {"$set": {"name": "Hell's kitchen"}})

# 10. Smažte svoji restauraci
print_delimiter(10)
# 10.1 pomocí id (delete_one)
collection.delete_one({"restaurant_id": "30000666"})

# 10.2 pomocí prvního nebo druhého názvu (delete_many, využití or)
collection.delete_many({"$or": [{"name": "Doom Slayer's Steak house"}, {"name": "Hell's kitchen"}]})
'''
Poslední částí tohoto cvičení je vytvoření jednoduchého indexu.

Použijte např. 3. úlohu s vyhledáváním čtvrtě Bronx. První použijte Váš již vytvořený dotaz a na výsledek použijte:

cursor.explain()['executionStats'] - výsledek si vypište na výstup a všimněte si položky 'totalDocsExamined'

Poté vytvořte index na 'borough', zopakujte dotaz a porovnejte hodnoty 'totalDocsExamined'.

S řešením pomůže https://pymongo.readthedocs.io/en/stable/api/pymongo/collection.html#pymongo.collection.Collection.create_index
'''
print_delimiter(11)
print(collection.find({"borough": "Bronx"}).limit(10).explain()['executionStats']['totalDocsExamined'])
collection.create_index("borough")
print(collection.find({"borough": "Bronx"}).limit(10).explain()['executionStats']['totalDocsExamined'])