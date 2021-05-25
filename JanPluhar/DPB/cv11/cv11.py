import csv

import cassandra
from cassandra.cluster import Cluster
import time

'''
DPB - 11. cvičení Cassandra

Use case: Discord server - reálně používáno pro zprávy, zde pouze zjednodušená varianta.

Instalace python driveru: pip install cassandra-driver

V tomto cvičení se budou následující úlohy řešit s využitím DataStax driveru pro Cassandru.
Dokumentaci lze nalézt zde: https://docs.datastax.com/en/developer/python-driver/3.25/getting_started/


Optimální řešení (nepovinné) - pokud něco v db vytváříme, tak první kontrolujeme, zda to již neexistuje.


Pro uživatele PyCharmu:

Pokud chcete zvýraznění syntaxe, tak po napsání prvního dotazu se Vám u něj objeví žlutá žárovka, ta umožňuje vybrat 
jazyk pro tento projekt -> vyberte Apache Cassandra a poté Vám nabídne instalaci rozšíření pro tento typ db.
Zvýraznění občas nefunguje pro příkaz CREATE KEYSPACE.

Také je možné do PyCharmu připojit databázi -> v pravé svislé liště najděte Database a připojte si lokální Cassandru.
Řešení cvičení chceme s využitím DataStax driveru, ale s integrovaným nástrojem pro databázi si můžete pomoct sestavit
příslušně příkazy.


Pokud se Vám nedaří připojit se ke Cassandře v Dockeru, zkuste smazat kontejner a znovu spustit:

docker run --name dpb_cassandra -p 127.0.0.1:9042:9042 -p 127.0.0.1:9160:9160 -d cassandra:3.11.10

'''


def print_delimiter(n):
    print('\n', '#' * 10, 'Úloha', n, '#' * 10, '\n')


def print_result(result):
    for row in result:
        print(row)


cluster = Cluster()  # automaticky se připojí k localhostu na port 9042
session = cluster.connect()

"""
1. Vytvořte keyspace 'dc' a přepněte se do něj (SimpleStrategy, replication_factor 1)
"""

print_delimiter(1)
try:
    session.execute("CREATE KEYSPACE dc WITH replication = {'class': 'SimpleStrategy', 'replication_factor' : 1}")
except cassandra.AlreadyExists:
    print("KEYSPACE already exists")
session.set_keyspace('dc')
"""
2. V csv souboru message_db jsou poskytnuta data pro cvičení. V prvním řádku naleznete názvy sloupců.
   Vytvořte tabulku messages - zvolte vhodné datové typy (time bude timestamp)
   Primárním klíčem bude room_id a time
   Data chceme mít seřazené podle času, abychom mohli rychle získat poslední zprávy

   Jako id v této úloze zvolíme i time - zdůvodněte, proč by se v praxi time jako id neměl používat.

   Pokud potřebujeme použít čas, tak se v praxi používá typ timeuuid nebo speciální identifikátor, tzv. Snowflake ID
   (https://en.wikipedia.org/wiki/Snowflake_ID). Není potřeba řešit v tomto cvičení.
"""

print_delimiter(2)
try:
    session.execute("CREATE TABLE messages ( \
        room_id int, \
        speaker_id int, \
        time timestamp, \
        message text, \
        PRIMARY KEY (room_id,time) \
    ) WITH CLUSTERING ORDER BY (time DESC)")
except cassandra.AlreadyExists:
    print("TABLE already exists")

# Mohlo by se stát že zprávy byly odeslány ve stejný čas a tudíž měli stejný primární klíč, což nelze.

"""
3. Do tabulky messages importujte message_db.csv
   COPY není možné spustit pomocí DataStax driveru ( 'copy' is a cqlsh (shell) command rather than a CQL (protocol) command)
   -> 2 možnosti:
      a) Nakopírovat csv do kontejneru a spustit COPY příkaz v cqlsh konzoli uvnitř dockeru
      b) Napsat import v Pythonu - otevření csv a INSERT dat
CSV soubor může obsahovat chybné řádky - COPY příkaz automaticky přeskočí řádky, které se nepovedlo správně parsovat
"""

print_delimiter(3)
with open('message_db.csv', newline='') as csvfile:
    reader = csv.reader(csvfile, delimiter=';', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    next(reader)
    for row in reader:
        session.execute_async(
            """
            INSERT INTO messages (room_id, speaker_id, time, message)
            VALUES (%s,%s,%s,%s)
            """,
            (int(row[0]), int(row[1]), row[2][0:23], row[3]))

"""
4. Kontrola importu - vypište 1 zprávu
"""

print_delimiter(4)
result = (session.execute("SELECT * FROM messages limit 1;"))
for row in result:
    print(row[0], row[1], row[2], row[3])

"""
5. Vypište posledních 5 zpráv v místnosti 1 odeslaných uživatelem 2
    Nápověda 1: Sekundární index (viz přednáška) 
    Nápověda 2: Data jsou řazena již při vkládání
"""

print_delimiter(5)
session.execute("CREATE INDEX IF NOT EXISTS messages_q ON messages (speaker_id)")
result = session.execute("SELECT * FROM messages WHERE room_id=1 AND speaker_id=2 limit 5;")
for row in result:
    print(row[0], row[1], row[2], row[3])

"""
6. Vypište počet zpráv odeslaných uživatelem 2 v místnosti 1
"""

print_delimiter(6)
session.execute("CREATE INDEX IF NOT EXISTS messages_q ON messages (speaker_id)")
result = session.execute("SELECT COUNT('room_id') FROM messages WHERE room_id=1 AND speaker_id=2;")
print(result[0])

"""
7. Vypište počet zpráv v každé místnosti
"""

print_delimiter(7)
session.execute("CREATE INDEX IF NOT EXISTS messages_q ON messages (speaker_id)")
result = session.execute("SELECT room_id,COUNT(message) FROM messages GROUP BY room_id;")
for row in result:
    print(row[0], row[1])

"""
8. Vypište id všech místností (3 hodnoty)
"""

print_delimiter(8)
session.execute("CREATE INDEX IF NOT EXISTS messages_q ON messages (speaker_id)")
result = session.execute("SELECT DISTINCT room_id FROM messages;")
for row in result:
    print(row[0])
