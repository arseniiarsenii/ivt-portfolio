####### задание 1
# ввод
num = int(input())

# извлекаем из числа цифры
digit_1 = num // 100
digit_2 = (num // 10) % 10
digit_3 = num % 10

# вычисляем новое число
num = digit_3 * 100 + digit_2 * 10 + digit_1

# вывод
print(num)

####### задание 2
# ввод
flat = int(input("Номер квартиры: "))

# вычисляем этаж
floor = flat // 4
if flat % 4 != 0:
    floor += 1

# вычисляем парадную
staircase = floor // 9
if floor % 9 != 0:
    staircase += 1

# вычисляем этаж заново
floor = floor % 9
if floor == 0:
    floor = 9

# вывод ответа
print(f"Друг живет на {floor} этаже в {staircase} парадной.")
