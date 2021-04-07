from init import collection

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
    """
    :param n:
    """
    print('\n', '#' * 10, 'Úloha', n, '#' * 10, '\n')


def print_collection(selected):
    """
    :param selected:
    """
    for row in selected:
        print(row)


# 1. Vypsání všech restaurací - pouze názvů, abecedně seřazených
print_delimiter(1)
print_collection(collection.find({}, {"_id": 0, "name": 1}).sort("name", 1))

# 2. Zobrazte dalších 10 záznamů
print_delimiter(2)
print_collection(collection.find({}, {"_id": 0, "name": 1}).sort("name", 1).skip(10).limit(10))

# 3. #Vypsání restaurací ve čtvrti Bronx (čtvrť = borough)
print_delimiter(3)
print_collection(collection.find({"borough": {"$eq": "Bronx"}}))

# 4. Vypsání restaurací, jejichž název začíná na písmeno M
print_delimiter(4)
print_collection(collection.find({"name": {"$regex": "^M"}}))

# 5. Vypsání restaurací, které mají skóre větší než 80
print_delimiter(5)
print_collection(collection.find({"grades": {"$elemMatch": {"score": {"$gt": 80}}}}))

# 6. Vypsání restaurací, které mají skóre mezi 80 a 90
print_delimiter(6)
print_collection(collection.find({"grades": {"$elemMatch": {"score": {"$gt": 80, "$lt": 90}}}}))

'''
V této části budete opět vytvářet vlastní restauraci.

Řešení:
Vytvořte si vaši restauraci pomocí slovníku a poté ji vložte do DB.
'''

restaurant = {
    "address": {
        "building": "999",
        "coord": [-99.999999, 99.999999],
        "street": "IDK",
        "zipcode": "99999"
    },
    "borough": "Bronx",
    "cuisine": "TEST",
    "grades": [{
        "date": "2012-05-08T00:00:00Z",
        "grade": "F",
        "score": 1
    }, {
        "date": "2016-08-08T00:00:00Z",
        "grade": "Q",
        "score": 999
    }],
    "name": "Fik",
    "restaurant_id": "987654321"
}

# 7. Uložte novou restauraci (stačí vyplnit název a adresu)
print_delimiter(7)
collection.insert_one(restaurant)

# 8. Vypište svoji restauraci
print_delimiter(8)
print_collection(collection.find().limit(1).sort([('$natural', -1)]))

# 9. Aktualizujte svoji restauraci - změňte libovolně název
print_delimiter(9)
collection.update_one({"restaurant_id": "987654321"}, {"$set": {"name": "Maxipes Fik"}})

# 10. Smažte svoji restauraci
# 10.1 pomocí id (delete_one)
# 10.2 pomocí prvního nebo druhého názvu (delete_many, využití or)
print_delimiter(10)
collection.delete_one({"restaurant_id": "987654321"})
collection.delete_many({"$or": [{"name": "Maxipes Fik"}, {"name": "Fik"}]})
'''
Poslední částí tohoto cvičení je vytvoření jednoduchého indexu.

Použijte např. 3. úlohu s vyhledáváním čtvrtě Bronx. První použijte Váš již vytvořený dotaz a na výsledek použijte:

cursor.explain()['executionStats'] - výsledek si vypište na výstup a všimněte si položky 'totalDocsExamined'

Poté vytvořte index na 'borough', zopakujte dotaz a porovnejte hodnoty 'totalDocsExamined'.

S řešením pomůže https://pymongo.readthedocs.io/en/stable/api/pymongo/collection.html#pymongo.collection.Collection.create_index
'''
print_delimiter(11)
# před 'totalDocsExamined': 3772
collection.create_index([("borough", 1)])
# po 'totalDocsExamined': 309
print(collection.find({"borough": {"$eq": "Bronx"}}).explain()['executionStats'])
