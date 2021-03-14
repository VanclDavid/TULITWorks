import math


def fibonacci(n):
    if n == 0 or n == 1:
        print(n)
        return
    last = [0, 1]
    result = 0
    for x in range(1, n):
        result = last[0] + last[1]
        last[0] = last[1]
        last[1] = result
    print(result)


def pyramid(height):
    for y in range(0, height):
        for x in range(0, height-y):
            print(" ", end="")
        for x in range(0, 1+2*y):
            print("*", end="")
        print("")


def is_prime(n):
    if n == 1:
        print("False")
        return
    for x in range(2, int(math.sqrt(n))+1):
        if n % x == 0:
            print("False")
            return
    print("True")


def pow(m, n):
    result = 1
    for x in range(0, n):
        result *= m
    return result


def digit_sum(n):
    string = str(n)
    return sum(map(int, string))


def is_palindrom(string):
    for x in (range(0, int(len(string)/2))):
        if string[x] != string[len(string)-1-x]:
            return False
    return True


fibonacci(4)
pyramid(5)
is_prime(9973)
print(pow(2, 10))
print(digit_sum(1011))
print(is_palindrom("kajak"))

