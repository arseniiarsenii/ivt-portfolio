import typing as tp
from decimal import Decimal

DEFAULT_N: int = 1000
R_ZEM: Decimal = Decimal(6377 * 1000)
R: Decimal = R_ZEM * Decimal(60.27)
G: Decimal = Decimal(9.81)


def integrate_trapezoid(
    f: tp.Callable[[Decimal], Decimal],
    a: Decimal,
    b: Decimal,
    n: tp.Optional[int] = None,
) -> Decimal:
    """Проинтегрировать ф-ию f(x) на отрезок от a до b методом трапеций с кол-вом разбиений n"""
    h = (a - b) / (n or DEFAULT_N)
    return (f(a) + f(b) + sum(f(a + step * h) for step in range(1, n or DEFAULT_N))) * h


def f(r: Decimal) -> Decimal:
    """Мат. модель"""
    return Decimal.sqrt(
        (r * R) / (2 * G * (R_ZEM ** 2) * (R - r))
    )  # FIXME: zero devision


if __name__ == "__main__":
    print(integrate_trapezoid(f=f, a=R_ZEM, b=R))
