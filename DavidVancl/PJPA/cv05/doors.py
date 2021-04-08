# -*- coding: utf-8 -*-

"""
Úkol 5.
Napište program, který načte soubor large.txt a pro každé dveře vyhodnotí,
zda je možné je otevřít nebo ne. Tedy vyhodnotí, zda lze danou množinu uspořádat
požadovaným způsobem. Výstup z programu uložte do souboru vysledky.txt ve
formátu 1 výsledek =  1 řádek. Na řádek napište vždy počet slov v množině a True
nebo False, podle toho, zda řešení existuje nebo neexistuje.

Podrobnější zadání včetně příkladu je jako obvykle na elearning.tul.cz
"""


def test_file(input_file_name):
    """
    Testování souboru
    :param file_name:
    """
    file_ = open(input_file_name, 'r')
    output_ = open("vysledky.txt", "w")
    max_len = len(max(file_.read().split(), key=len)) * 3
    min_size = 24 if max_len < 24 else max_len
    file_.seek(0, 0)
    for _ in range(int(file_.readline())):
        errors_count = 0
        array_of_first = min_size * [0]
        array_of_last = min_size * [0]
        words_count = int(file_.readline())
        for _ in range(words_count):
            word = file_.readline()
            array_of_first[ord(word[0]) - 97] += 1
            array_of_last[ord(word[-2]) - 97] += 1
        for let in range(min_size - 1):
            if (array_of_first[let] < array_of_last[let]) or\
                    (array_of_first[let] != 0) and (array_of_last[let] == 0):
                errors_count += 1
            if (errors_count == 2) or (let == (min_size - 2)):
                output_.write("{0} {1}\n".format(words_count, errors_count != 2))
                break


if __name__ == '__main__':
    test_file("large.txt")
