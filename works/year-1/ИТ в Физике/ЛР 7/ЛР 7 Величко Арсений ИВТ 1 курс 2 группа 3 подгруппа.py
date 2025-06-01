# импортируем библиотеки
import matplotlib.pyplot as plt
from math import *

# зададим переменные для этой задачи
r0 = 1.496 * (10 ** 11)
v0 = 29.75 * (10 ** 3)
M = 2 * (10 ** 30)
phi0 = 0
G = 6.67 * (10 ** -11)
g0 = G * M / r0
p = v0 ** 2 / g0
e = 0.0167

# сгенерирем массив значений фи
phi_values = [radians(i) for i in range(0, 360)]

# подготовим массив для значений r
r_values = []

# рассчитаем r для всех значений угла в нашем массиве и запишем в массив
for phi in phi_values:
    r = p / (1 + e * cos(phi + phi0))
    r_values.append(r)

# подготовим массивы для значений координат точек
x_values = []
y_values = []

# найдем координаты точек и запишем в массивы
for i in range(len(phi_values)):
    phi = phi_values[i]
    r = r_values[i]
    x = cos(phi) * r
    y = sin(phi) * r
    x_values.append(x)
    y_values.append(y)

# построим график и выведем его на экран
plt.axhline()
plt.axvline()
plt.plot(x_values, y_values)
plt.title('Орбита движения Земли вокруг Солнца', fontsize=16)
plt.show()
