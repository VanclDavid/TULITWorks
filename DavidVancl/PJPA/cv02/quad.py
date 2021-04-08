import math


def count_angle(a, b, c):
    ac = math.sqrt(((c[0] - a[0]) ** 2) + ((c[1] - a[1]) ** 2))
    bc = math.sqrt(((c[0] - b[0]) ** 2) + ((c[1] - b[1]) ** 2))
    ab = math.sqrt(((b[0] - a[0]) ** 2) + ((b[1] - a[1]) ** 2))

    return math.degrees(math.acos((bc * bc + ac * ac - ab * ab) / (2 * bc * ac)))


def is_convex(a, b, c, d):
    if a == b or a == c or a == d or b == c or b == d or c == d:
        return False

    if 360 != int(count_angle(d, b, a) + count_angle(a, c, b) + count_angle(b, d, c) + count_angle(c, a, d)):
        return False

    return True
