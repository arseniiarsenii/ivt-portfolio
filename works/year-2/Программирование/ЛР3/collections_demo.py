from collections import (
    namedtuple,
    deque,
    ChainMap,
    Counter,
    OrderedDict,
    defaultdict,
    UserDict,
)


def demonstrate_collections_namedtuple() -> None:
    """factory function for creating tuple subclasses with named fields"""
    Point = namedtuple("Point", ["x", "y"])
    p = Point(11, y=22)  # instantiate with positional or keyword arguments
    p[0] + p[1]  # indexable like the plain tuple (11, 22)
    x, y = p  # unpack like a regular tuple
    print(p.x + p.y)  # fields also accessible by name
    print(p)  # readable __repr__ with a name=value style


def demonstrate_collections_deque() -> None:
    """list-like container with fast appends and pops on either end"""
    # представим очередь из 3 человек на кассе
    cashier_queue = deque(["natasha", "alex", "sergey"])
    print(cashier_queue)  # ["natasha", "alex", "sergey"]

    # пришел еще один человек
    cashier_queue.append("ilya")
    print(cashier_queue)  # ["natasha", "alex", "sergey", "ilya"]

    # первого человека обслужили и он ушел
    person = cashier_queue.popleft()
    print(person)  # natasha

    # последний человек устал ждать и ушел
    person = cashier_queue.pop()
    print(person)  # ilya


def demonstrate_collections_chainmap() -> None:
    """dict-like class for creating a single view of multiple mappings"""
    # можно использовать для задания приоритета обращения к
    # повторяющимся ключам
    main = {"foo": "bar"}
    fallback = {"foo": "spam"}
    chain = ChainMap(main, fallback)
    print(chain["foo"])  # bar

    main = {}
    fallback = {"foo": "spam"}
    chain = ChainMap(main, fallback)
    print(chain["foo"])  # spam


def demonstrate_collections_counter() -> None:
    """dict subclass for counting hashable objects"""
    c = Counter("Alabama")
    print(c)  # Counter({'a': 3, 'A': 1, 'l': 1, 'b': 1, 'm': 1})


def demonstrate_collections_ordereddict() -> None:
    """dict subclass that remembers the order entries were added"""
    a = {}
    b = OrderedDict()
    l = ["natasha", "alex", "sergey", "ilya"]

    for i, s in enumerate(l, 1):
        a[s] = i
        b[s] = i

    # начиная с Pythob 3.7 порядок совпадает, т.к. с этой
    # версии встроенный словарь тоже сохраняет порядок
    for i, j in zip(a.values(), b.values()):
        print(i == j)  # True

    # однако OrderedDict имеет некоторые полезные методы, напр. метод .move_to_end()
    b.move_to_end("alex")
    print(b)  # OrderedDict([('natasha', 1), ('sergey', 3), ('ilya', 4), ('alex', 2)])


def demonstrate_collections_defaultdict() -> None:
    """dict subclass that calls a factory function to supply missing values"""
    # допустим мы храним количество посещений сайта
    # пользователями в словаре вида {"логин": 0}.
    # чтобы не объявлять для каждого пользователя используем
    # defaultdict, фабрикой по умолчанию используем int
    # (вернет 0 при вызове без аргументов)
    user_access_count = defaultdict(int)
    usernames = ["natasha", "alex", "sergey", "ilya"]

    for username in usernames[:-1]:
        user_access_count[username] += 2

    for username in usernames:
        print(f"User {username} accessed page {user_access_count[username]} times")

    # User natasha accessed page 2 times
    # User alex accessed page 2 times
    # User sergey accessed page 2 times
    # User ilya accessed page 0 times


def demonstrate_collections_userdict() -> None:
    """wrapper around dictionary objects for easier dict subclassing"""

    class LowerDict(UserDict):
        def __setitem__(self, key, value):
            key = key.lower()
            super().__setitem__(key, value)

    ordinals = LowerDict({"FIRST": 1, "SECOND": 2})
    ordinals["THIRD"] = 3
    ordinals.update({"FOURTH": 4})

    print(ordinals)  # {'first': 1, 'second': 2, 'third': 3, 'fourth': 4}
