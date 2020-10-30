## Zadání 1:
Mé vypracování funguje tak, že se dioda rozsvěcí a zhasíná dynamicky. Napsal jsem si proto funkci `void blik(double time)`, kdy parametr `time` říká jak dlouho má dioda svítit a jako dlouhý má být interval pauzy - vše v ms.

Následně volám funkci s postupným zkracováním intervalu pod dobu, kdy je interval větší než 0.1. Jednotlivé skoky zmenšuji také dynamicky.
> Zdrojový soubor:  [https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/blob/master/zadani_1/zadani_1.cpp](https://gitlab.tul.cz/david.dlouhy/ops_2020_dlouhy/-/blob/master/zadani_1/zadani_1.cpp)