import typing as tp
from dataclasses import dataclass, field, asdict
from datetime import datetime as dt
from uuid import uuid4
from pprint import pprint


@dataclass(
    frozen=True
)  # датакласс неизменяем, если frozen=True. становится хешируемым типом
class Car:
    """простая структура данных для демонстрации модуля dataclasses"""

    manufacturer_name: str  # название марки - строка
    model_name: str  # название модели - строка
    wheels_count: int = 4  # число колес - целое число, по умолчанию 4
    doors_count: int = 5  # число дверей - целое число, по умолчанию 5
    manufacturing_year: int = field(
        default_factory=lambda: dt.now().year
    )  # год выпуска. по умолчанию - текущий год
    additional_features: tp.List[str] = field(
        default_factory=list
    )  # список доп. опций - список строк. по умолчанию - пустой список
    vin: tp.Optional[int] = field(
        default_factory=lambda: uuid4().int
    )  # VIN номер ТС, по умолчанию будет присвоена десятичная форма 128 битного случайного числа


if __name__ == "__main__":
    car_1 = Car(
        manufacturer_name="Nissan",
        model_name="Pathfinder",
        additional_features=["Кожаный салон", "Панорманая крыша"],
    )
    pprint(
        asdict(car_1)
    )  # датасклассы можно приводить к словарю с помощью ф-ии asdict()

    # Вывод:
    # {'additional_features': ['Кожаный салон', 'Панорманая крыша'],
    #  'doors_count': 5,
    #  'manufacturer_name': 'Nissan',
    #  'manufacturing_year': 2022,
    #  'model_name': 'Pathfinder',
    #  'vin': 326315215358544830282541641286845582262,
    #  'wheels_count': 4}

    car_2 = Car(
        manufacturer_name="Reliant",
        model_name="Robin",
        wheels_count=3,
        doors_count=3,
        manufacturing_year=1975,
        vin=None,  # у старых авто нет VIN номера
    )
    pprint(
        asdict(car_2)
    )  # датасклассы можно приводить к словарю с помощью ф-ии asdict()

    # Вывод:
    # {'additional_features': [],
    # 'doors_count': 3,
    # 'manufacturer_name': 'Reliant',
    # 'manufacturing_year': 1975,
    # 'model_name': 'Robin',
    # 'vin': None,
    # 'wheels_count': 3}
