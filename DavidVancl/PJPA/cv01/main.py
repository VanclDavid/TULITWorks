from triangle import triangle

print("***TEST***")
print(triangle(3, 4, 5))
print(triangle(5, 12, 13))

print(triangle(16, 2, 63))
print(triangle(15, 15, 15))

a = int(input("Enter a: "))
b = int(input("Enter b: "))
c = int(input("Enter c: "))
print(triangle(a, b, c))