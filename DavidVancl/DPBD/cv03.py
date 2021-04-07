def save_persons(filename, persons):
    file = open(filename, "w")
    for person in persons:
        file.write('{};{}\n'.format(str(person[0]), str(person[1])))


def load_persons(filename):
    file = open(filename, "r")
    persons = []
    for person in file.read().strip().split('\n'):
        data = person.split(';')
        persons.append({'name': data[0], 'age': data[1]})

    return persons


def text_analysis(filename):
    content = (open(filename, "r")).read()
    data = {}
    for char in range(len(content)):
        if not content[char].isalpha():
            continue
        if content[char] in data:
            data[content[char]] += 1
        else:
            data[content[char]] = 1

    words = content.split()
    words_count = {}
    for i in range(len(words)):
        words[i] = words[i].replace('\n', '') \
            .replace('.', '').replace('?', '') \
            .replace('&', '').replace('!', '') \
            .replace('\\', '').replace('"', '') \
            .replace("'", '').replace('-', '') \
            .replace(',', '').replace(')', '') \
            .replace('(', '').replace('http://', '')
        if words[i] == '' or words[i].isdigit():
            continue
        if words[i].lower() in words_count:
            words_count[words[i].lower()] += 1
        else:
            words_count[words[i].lower()] = 1

    return [
        {k: v for k, v in sorted(data.items(), key=lambda item: item[1])}.items(),
        {k: v for k, v in reversed(sorted(words_count.items(), key=lambda item: item[1]))}.items()]


def get_words(n, m, data):
    if n == 0 or m == 0:
        return False
    result = []
    found = 0
    for item in data:
        if len(item[0]) >= m:
            result.append(item)
            found += 1

        if found >= n:
            break

    return result
