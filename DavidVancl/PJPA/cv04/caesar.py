"""
Vytvorte funkce encrypt a decrypt pro Caesarovu sifru.
Kompletni zadani v elearningu.
"""

alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
            'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']


def convert_word(word, offset, convert_type):
    """
    :param word:
    :param offset:
    :param convert_type:
    :return:
    """
    converted = ""
    for index, character in enumerate(word):
        if word[index].isalpha():
            new_index = alphabet.index(word[index].lower())
            if convert_type == "encrypt":
                new_index += offset
                if new_index >= len(alphabet):
                    new_index -= len(alphabet)
            elif convert_type == "decrypt":
                new_index -= offset
                if new_index < 0:
                    new_index += len(alphabet)
            if word[index].isupper():
                converted += alphabet[new_index].upper()
            else:
                converted += alphabet[new_index]
        else:
            converted += character
    return converted


def encrypt(word, offset):
    """
    :param word - slovo k zasifrovani
    :param offset - znakovy posun
    :return: zasifrovane slovo
    """
    return convert_word(word, offset, "encrypt")


def decrypt(word, offset):
    """
    :param word - zasifrovane slovo
    :param offset - znakovy posun
    :return: desifrovane slovo
    """
    return convert_word(word, offset, "decrypt")
