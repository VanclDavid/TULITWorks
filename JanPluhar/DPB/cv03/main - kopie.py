import csv


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


def save_persons(path, dictionaries):
    with open(path, 'w', newline='') as csvfile:
        writer = csv.DictWriter(csvfile, delimiter=' ', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        for row in dictionaries:
            writer.writerow(row[0]+';')


def load_persons(path):
    with open(path, newline='') as csvfile:
        reader = csv.reader(csvfile, delimiter=' ', quotechar='|')
        dictionaries = []
        for row in reader:
            dictionaries.append({row[0]: row[1]})
    return dictionaries


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    save_persons('D:\\test.csv', [{'name': 'Jarda', 'age': 20},{'name': 'Pepa', 'age': 15}])

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
