import math


def Fibonacci(i):
    number = [0, 1]
    print(number[0])
    print(number[1])
    for j in range(2, int(i)):
        number.append(number[j - 1] + number[j - 2])
        print(number[j])


def pyramid(height):
    row_count = 1
    for i in range(height):
        for j in range(height - i):
            print(" ", end=" ")
        for j in range(row_count):
            print("#", end=" ")
        print("")
        row_count += 2


def is_prime(number):
    if number <= 1:
        print("ANO")
        return
    if number == 2:
        print("NE")
        return
    if number % 2 == 0:
        print("NE")
        return
    for i in range(3, int(math.sqrt(number)), 2):
        if number % i == 0:
            print("NE")
        return
    print("ANO")


def pow(number, up):
    return number ** up


def digit_sum(number):
    data = [char for char in str(number)]
    sums = 0
    for i in range(len(data)):
        sums += int(data[i])
    return sums


def is_palindrom(str):
    for i in range(int(len(str) / 2)):
        if str[i] != str[len(str) - i - 1]:
            return "NENI"
    return "JE"
