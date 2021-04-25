import pprint

from init import collection
from bson.code import Code

'''
DPB - 6. cvičení - Agregační roura a Map-Reduce

V tomto cvičení si můžete vybrat, zda ho budete řešit v Mongo shellu nebo pomocí PyMongo knihovny.

Před testováním Vašich řešení si nezapomeňte zapnout Mongo v Dockeru - používáme stejná data jako v minulých cvičeních.

Pro pomoc je možné např. použít https://api.mongodb.com/python/current/examples/aggregation.html a přednášku.

Všechny výsledky limitujte na 10 záznamů. Nepoužívejte české názvy proměnných!

Struktura záznamu v db:
{
  "address": {
     "building": "1007",
     "coord": [ -73.856077, 40.848447 ],
     "street": "Morris Park Ave",
     "zipcode": "10462"
  },
  "borough": "Bronx",
  "cuisine": "Bakery",
  "grades": [
     { "date": { "$date": 1393804800000 }, "grade": "A", "score": 2 },
     { "date": { "$date": 1378857600000 }, "grade": "A", "score": 6 },
     { "date": { "$date": 1358985600000 }, "grade": "A", "score": 10 },
     { "date": { "$date": 1322006400000 }, "grade": "A", "score": 9 },
     { "date": { "$date": 1299715200000 }, "grade": "B", "score": 14 }
  ],
  "name": "Morris Park Bake Shop",
  "restaurant_id": "30075445"
}
'''


def print_delimiter(n):
    print('\n', '#' * 10, 'Úloha', n, '#' * 10, '\n')


def print_query(result):
    for x in result:
        print(x)


'''
Agregační roura
Zjistěte počet restaurací pro každé PSČ (zipcode)
 a) seřaďte podle zipcode vzestupně
 b) seřaďte podle počtu restaurací sestupně
Výpis limitujte na 10 záznamů a k provedení použijte collection.aggregate(...)
'''
print_delimiter('1 a)')

print_query(collection.aggregate([
    {"$group": {"_id": "$address.zipcode", "count": {"$sum": 1}}},
    {"$sort": {"_id": 1}},
    {"$limit": 10}
]))
print("\n")
mapper = Code("""function() { emit(this.address.zipcode, this.name) }""")
reducer = Code("""function(keys, values) { return values.length }""")
result = collection.map_reduce(mapper, reducer, "result")
for doc in result.find().sort("_id").limit(10):
    pprint.pprint(doc)

print_delimiter('1 b)')
print_query(collection.aggregate([
    {"$group": {"_id": "$address.zipcode", "count": {"$sum": 1}}},
    {"$sort": {"count": -1}},
    {"$limit": 10}
]))
print("\n")
for doc in result.find().sort("value", -1).limit(10):
    pprint.pprint(doc)
'''
Agregační roura

Restaurace obsahují pole grades, kde jsou jednotlivá hodnocení. Vypište průměrné score pro každou hodnotu grade.
V agregaci vynechte grade pro hodnotu "Not Yet Graded" (místo A, B atd. se může vyskytovat tento řetězec).

'''
print_delimiter(2)
print_query(collection.aggregate([
    {"$match": {"grades.grade": {"$ne": "Not Yet Graded"}}},
    {"$unwind": "$grades"},
    {"$match": {"grades.grade": {"$ne": "Not Yet Graded"}}},
    {"$group": {"_id": "$name", "average": {"$avg": "$grades.score"}}},
    # {"$match": {"_id": {"$eq": "Pate'S Jeanty"}}},
    {"$limit": 10}
]))

print("\n")
mapper = Code("""function() {
    for(var i = 0; i < this.grades.length; i++) {
      var key = this.name;
      var value = { count: 1, score: this.grades[i].score, grade: this.grades[i].grade };
      emit(key, value);
    }
  }""")
reducer = Code("""function(key, values) {
    reducedVal = { count: 0, score_sum: 0};
    for (var i = 0; i < values.length; i++) {
      reducedVal.count += values[i].count;
      reducedVal.score_sum += values[i].score;
    }
    return reducedVal;
  }""")
finalizef = Code("""function(key, reducedVal) {
      return reducedVal.score_sum/reducedVal.count;
    }""")
result = collection.map_reduce(mapper, reducer, "result", query={"grades.grade": {"$ne": "Not Yet Graded"}}, finalize=finalizef)
for doc in result.find().limit(10):  # { "_id": { "$eq": "Pate'S Jeanty" }}
    pprint.pprint(doc)
'''
Map-Reduce

Zadání je stejné jako u 1. příkladu pro agregační rouru - pouze realizovat přes Map-Reduce. 

Při řešení může pomoct:
https://pymongo.readthedocs.io/en/stable/examples/aggregation.html
https://pymongo.readthedocs.io/en/stable/api/pymongo/collection.html#pymongo.collection.Collection.map_reduce 
'''
