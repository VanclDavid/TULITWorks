# -*- coding: utf8 -*-
"""
Zakladni sablona pro prvni cviceni
"""


def triangle(a, b, c):
    expected_c = (a ** 2) + (b ** 2)
    if expected_c != (c ** 2):
        return False
    return True
