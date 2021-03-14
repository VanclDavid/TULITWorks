import re


def save_persons(path, dictionaries):
    f = open(path, "w")
    for row in dictionaries:
        f.write(row['name'] + ';' + str(row['age']) + '\n')
    f.close()


def load_persons(path):
    f = open(path, "r")
    dictionaries = []
    for line in f:
        temp = line.split(';')
        dictionaries.append({"name": temp[0], "age": temp[1][:-1]})
    f.close()
    return dictionaries


def text_analysis(path):
    def key_counter(dictionary, key):
        if key in dictionary:
            dictionary[key] += 1
        else:
            dictionary[key] = 1

    frq_analysis = {}
    frq_word_analysis = {}
    f = open(path, "r")
    for line in f:
        line = line.lower()
        words = filter(None, re.split('[ ,.";?!-]', line[:-1]))
        for word in words:
            key_counter(frq_word_analysis, word)
        for char in line:
            key_counter(frq_analysis, char)
    f.close()
    frq_analysis = dict(sorted(frq_analysis.items(), key=lambda item: item[1]))
    frq_word_analysis = dict(sorted(frq_word_analysis.items(), key=lambda item: item[1], reverse=True))
    return [frq_analysis, frq_word_analysis]


def get_words(n, m, data):
    result = {}
    data = dict(sorted(data.items(), key=lambda item: item[1], reverse=True))
    counter = 0
    for key, value in data.items():
        if counter >= n:
            return result
        if len(key) >= m:
            result[key] = value
            counter = counter+1


if __name__ == '__main__':
    # save_persons('D:\\test.csv', [{'name': 'Jarda', 'age': 20},{'name': 'Pepa', 'age': 15}])
    # test = load_persons('D:\\test.csv')
    # print(text_analysis('D:\\sh.txt'))
    print(get_words(10, 8, text_analysis('D:\\sh.txt')[1]))
