import math


def func(x, y):
    return math.sin(x + y)


a = 0  # нижняя граница внутреннего интеграла
b = math.pi / 2  # верхняя граница внутреннего интеграла
c = 0  # нижняя граница внешнего интеграла
d = math.pi / 2  # верхняя граница внешнего интеграла
nx = int(input("nx = "))  # количество разбиений внутреннего интеграла
ny = int(input("ny = "))  # количество разбиений внешнего интеграла
hx = (b - a) / nx  # шаг внутреннего интеграла
hy = (d - c) / ny  # шаг внешнего интеграла
sx = 0
x = a
iy = 0

print(f"hx = {hx:.5}; hy = {hy:.5}")

while x <= (b - hx):
    sy = 0
    y = c

    while y <= (d - hy):
        sy += func(x, y)
        y += hy

    iy = hy * sy
    sx += iy
    x += hx

ix = hx * sx

print(f"result = {ix}")

