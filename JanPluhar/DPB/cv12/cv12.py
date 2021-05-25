from datetime import datetime

from cassandra.cluster import Cluster
import time

'''
DPB - 12. cvičení Cassandra

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
1. Vložte libovolnou novou zprávu do místnosti 1 od uživatele 3
"""

print_delimiter(1)
session.execute(
    """
    INSERT INTO dc.messages (room_id, speaker_id, time, message)
    VALUES (%s,%s,%s,%s)
    """,
    (1, 3, "2021-05-20 10:10:10", "ahoj vsichni"))
"""
2. Smažte zprávu vloženou v bodě 7.
    Nápověda: získejte poslední záznam, čas do podmínky získáte pomocí str(result[0].time)[:-3],
        čas musí být uveden v jednoduchých uvozovkách, doporučujeme si první vypsat příkaz do konzole pro kontrolu
"""

print_delimiter(2)
session.execute("DELETE FROM dc.messages WHERE time='2021-05-20 10:10:10' AND room_id=1")

"""
3. Pro textovou analýzu chcete poskytovat anonymizovaná textová data. Vytvořte Materialized View pro tabulku messages,
který bude obsahovat pouze čas, room_id a zprávu.

Vypište jeden výsledek z vytvořeného view.
"""

print_delimiter(3)
session.execute(
    """
    CREATE MATERIALIZED VIEW IF NOT EXISTS dc.messagesmw
    AS SELECT room_id, time, message
    FROM dc.messages
    WHERE room_id IS NOT NULL AND time IS NOT NULL
    PRIMARY KEY (room_id, time);
    """
)
print((session.execute("SELECT * FROM dc.messagesmw limit 1;")).all())
"""
4. V aplikaci chceme navíc vytvořit feature pro tzv. mizející režim. Odeslané zprávy zmizí po 10 sekundách.

Vložte libovolnou zprávu s časovým limitem a poté ji vypište. Počkejte 10 s a zkuste ji znovu vypsat. 
"""

print_delimiter(4)
session.execute("INSERT INTO dc.messages (room_id, speaker_id, time, message)"
                " VALUES (10,5, '2221-05-27','nejvic tajna zprava') USING TTL 10;")

print(session.execute("SELECT * FROM dc.messages WHERE time='2221-05-27' AND room_id=10").all())
time.sleep(10)
print(session.execute("SELECT * FROM dc.messages WHERE time='2221-05-27' AND room_id=10").all())
"""
5. Chceme vytvořit funkci (UDF), která při výběru dat vrátí navíc příznak, zda vybraný text obsahuje nevhodný výraz.

Vyberte jeden výraz (nemusí být nevhodný:), vytvořte a otestujte Vaši funkci.

Před začátkem řešení je potřeba jít do souboru cassandra.yaml uvnitř docker kontejneru a nastavit enable_user_defined_functions=true

docker exec -it dpb_cassandra bash
sed -i -r 's/enable_user_defined_functions: false/enable_user_defined_functions: true/' /etc/cassandra/cassandra.yaml

Poté restartovat kontejner

"""
print_delimiter(5)
session.execute(
    "CREATE OR REPLACE FUNCTION dc.censor (column text) CALLED ON NULL INPUT RETURNS text LANGUAGE java AS 'return column.contains(\"time\") ? \"nevhodny\" : \"vhodny\";';")
result = session.execute("SELECT dc.censor(message), message from dc.messages LIMIT 10;").all()
for row in result:
    print(row[0] + " " + row[1])
