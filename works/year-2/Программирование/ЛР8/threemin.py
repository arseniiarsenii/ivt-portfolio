import typing as tp
from functools import reduce
from operator import mul
from itertools import combinations


def validate_input(lst: tp.Any) -> None:
    """валидация входного массива"""
    if not isinstance(lst, list):
        raise TypeError("Аргументом функции должен быть список целых чисел")

    if len(lst) < 3:
        raise ValueError("Длина списка менее трёх элементов")

    if not all(isinstance(i, int) for i in lst):
        raise TypeError("Массив должен содержать только целые числа")


def multiply(lst: tp.Iterable[int]) -> int:
    """перемножить все числа во входном массиве"""
    return reduce(mul, lst, 1)


def threemin_naive(lst: tp.List[int], n: int = 3) -> int:
    """
    Вывести наименьшее произведение
    n целых чисел из приведённого списка

    Наивный метод, работающий за ~O(N^n)
    """
    validate_input(lst)

    candidates = map(multiply, combinations(lst, n))
    result = min(candidates)

    return result


def threemin(lst: tp.List[int]) -> int:
    """
    Вывести наименьшее произведение
    трёх целых чисел из приведённого списка

    Производительный метод, работающий за O(n)
    """
    validate_input(lst)

    if len(lst) == 3:
        return multiply(lst)

    highest = max(lst[:2])
    lowest = min(lst[:2])
    max_for_2 = multiply(lst[:2])
    min_for_2 = multiply(lst[:2])
    min_for_3 = multiply(lst[:3])

    for i in lst[2:]:
        min_for_3 = min(
            min_for_3,
            i * max_for_2,
            i * min_for_2,
        )
        max_for_2 = max(max_for_2, i * highest, i * lowest)
        min_for_2 = min(min_for_2, i * highest, i * lowest)
        highest = max(highest, i)
        lowest = min(lowest, i)

    return min_for_3
