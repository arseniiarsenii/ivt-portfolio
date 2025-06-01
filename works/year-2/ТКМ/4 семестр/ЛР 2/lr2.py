import typing as tp

from tabulate import tabulate

MatrixRow = tp.List[tp.Union[int, float]]
Matrix = tp.List[MatrixRow]


def input_matrix() -> Matrix:
    """Ввод матрицы"""
    height = int(input("Количество строк: "))
    width = int(input("Количество столбцов, включая столбец свободных членов: "))
    return [[int(i) for i in input().split()][:width] for _ in range(height)]


def output_matrix(matrix: Matrix, digits: int = 4) -> None:
    """Вывод матрицы"""
    matrix = [[round(i, digits) for i in row] for row in matrix]
    print(tabulate(matrix))


def gauss_jordan(matrix: Matrix) -> Matrix:
    """Метод Гаусса-Жордана"""
    n = len(matrix)

    for i in range(n):
        for k in range(n):
            if k == i:
                continue
            kf = matrix[k][i] / matrix[i][i]
            for j in range(i + 1, n + 1):
                matrix[k][j] = matrix[k][j] - matrix[i][j] * kf
            matrix[k][i] = 0

    return matrix


def gauss_jordan_backward(matrix: Matrix) -> MatrixRow:
    """Метод Гаусса-Жордана (обр.)"""
    n = len(matrix)
    return [matrix[i][n] / matrix[i][i] for i in range(n)]


SAMPLE_MATRIX: Matrix = [
    [5, 7, 6, 5, 23],
    [7, 10, 8, 7, 32],
    [6, 8, 10, 9, 33],
    [5, 7, 9, 10, 31],
]
ADDITIONS = [0, 0.1, 0.01, 0.001]
HEADERS = ["Метод", "Прибавлено", "x1", "x2", "x3", "x4"]

if __name__ == "__main__":
    input_matrix = SAMPLE_MATRIX or input_matrix()
    table = []

    for addition in ADDITIONS:
        if addition:
            print("\n" + "=" * 50)
            print(f"\nК столбцу свободных членов прибавлено {addition}\n")

        matrix = [row[:-1] + [row[-1] + addition] for row in input_matrix]

        print("Будет использована матрица:")
        output_matrix(matrix)

        method = gauss_jordan
        matrix = method(matrix)

        print(f'\nРезультат вычислений методом "{method.__doc__}":')
        output_matrix(matrix)

        method = gauss_jordan_backward
        answers: MatrixRow = method(matrix)
        print(f'\nРезультат вычислений методом "{method.__doc__}":')
        print(*(f"x{i} = {round(x, 4)}" for i, x in enumerate(answers, 1)))

        summary = [method.__doc__, addition, *(round(x, 4) for x in answers)]
        table.append(summary)

    print("\nСводная таблица результатов вычислений")
    print(tabulate(table, HEADERS))
