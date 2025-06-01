import math
import typing as tp

DEFAULT_N: int = 1000  # число разбиений по умолчанию
R_ZEM: int = 6377 * 1000  # радиус Земли (м)
R: float = R_ZEM * 60.27  # расстояние от падающего тела до Земли (м)
G: float = 9.81  # ускорение свободного падения (м / с^2)


def integrate_right_rectangle(
    f: tp.Callable[[float], float],
    a: float,
    b: float,
    n: tp.Optional[int] = None,
) -> float:
    """
    Проинтегрировать ф-ию f(x) на отрезке от a до b методом 
    правых прямоугольников с кол-вом разбиений n
    """
    h: float = (b - a) / (n or DEFAULT_N)
    i: float = a
    result: float = 0.0

    while i < b:
        i += h
        result += h * f(i)

    return result


def t(r: float) -> float:
    """Мат. модель"""
    tmp = (r * R) / (2 * G * (R_ZEM ** 2) * (R - r))
    print(r, tmp)
    return math.sqrt(tmp)


if __name__ == "__main__":
    print(integrate_right_rectangle(f=t, a=R_ZEM, b=R))
    
