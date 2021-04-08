"""
Úkol 6.
Vaším dnešním úkolem je vytvořit program, který o zadaném textu zjistí některé
údaje a vypíše je na standardní výstup. Hlavním smyslem cvičení je procvičit
si práci s regulárními výrazy, takže pro plný bodový zisk je nutné použít k
řešení právě tento nástroj.

Program musí pracovat s obecným textem, který bude zadaný v souboru. Jméno
souboru bude zadáno jako vstupní parametr funkce main, která by měla být
vstupním bodem programu. Samozřejmě, že funkce main by neměla řešit problém
kompletně a měli byste si vytvořit další pomocné funkce. Můžete předpokládat,
že soubor bude mít vždy kódování utf-8 a že bude psaný anglicky, tedy jen
pomocí ASCII písmen, bez české (či jiné) diakritiky.

Konkrétně musí program zjistit a vypsat:

1. Počet slov, která obsahují nejméně dvě samohlásky (aeiou) za sebou. Například
slovo bear.

2. Počet slov, která obsahují alespoň tři samohlásky - například slovo atomic.

3. Počet slov, která mají šest a více znaků - například slovo terrible.

4. Počet řádků, které obsahují nějaké slovo dvakrát.

Podrobnější zadání včetně příkladu je jako obvykle na elearning.tul.cz
"""

import re


def two_vowels_in_row(data):
    """
    two_vowels_in_row
    :param data:
    :return:
    """
    return len(set(re.findall(r'(\w*[a|e|y|i|o|u]{2}\w*)', data.lower())))


def three_vowels_in_word(data):
    """
    three_vowels_in_word
    :param data:
    :return:
    """
    return len(set(re.findall(r'(?:\w*[a|e|i|y|o|u]){3,}\w*', data.lower())))


def more_than_6_characters(data):
    """
    more_than_6_characters
    :param data:
    :return:
    """
    return len(set(re.findall(r'([a-z]{6,})', data.lower())))


def lines_count_twice_word(data):
    """
    lines_count_twice_word
    :param data:
    :return:
    """
    return len(re.findall(r'.*\b(\w+)\b(?=.*\b\1\b).*', data.lower()))


def main(file_name):
    """
    main
    :param file_name:
    """
    with open(file_name, 'r') as file:
        data = file.read()
    print("1. {0}".format(two_vowels_in_row(data)))
    print("2. {0}".format(three_vowels_in_word(data)))
    print("3. {0}".format(more_than_6_characters(data)))
    print("4. {0}".format(lines_count_twice_word(data)))


if __name__ == '__main__':
    main('cv06_test.txt')
