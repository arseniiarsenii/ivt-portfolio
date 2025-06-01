import typing as tp

from tabulate import tabulate

MatrixRow = tp.List[tp.Union[int, float]]
Matrix = tp.List[MatrixRow]


def output_matrix(matrix: Matrix, digits: int = 4) -> None:
    """Вывод матрицы"""
    matrix = [[round(i, digits) for i in row] for row in matrix]
    print(tabulate(matrix))


def backward_iteration(matrix: Matrix) -> MatrixRow:
    """Обратный ход"""
    l = []
    n = len(matrix) - 1

    for i in range(n, -1, -1):
        res = (matrix[i][-1] - sum(matrix[i][i+1:-1])) / matrix[i][i]
        l.append(res)

        for j in range(i - 1, -1, -1):
            matrix[j][i] = matrix[j][i] * res

    return l[::-1]


def gauss_method(matrix: Matrix) -> Matrix:
    """Метод Гаусса. Алгоритм последовательного исключения неизвестных"""
    n = len(matrix)

    for k in range(n - 1):
        matrix[k] = [i / matrix[k][k] for i in matrix[k]]

        for i in range(k + 1, n):
            div = (matrix[i][k] / matrix[k][k]) * (-1)
            l = [i * div for i in matrix[k]]
            matrix[i] = [
                element1 + element2 for (element1, element2) in zip(matrix[i], l)
            ]

    matrix[n - 1] = [i / matrix[n - 1][n - 1] for i in matrix[n - 1]]
    return matrix


if __name__ == "__main__":
    matrix = [
        [1, 1, 1, 6],
        [1, -1, 2, 5],
        [2, -1, -1, -3],
    ]
    print("Расширенная матрица коэффициентов:")
    output_matrix(matrix)

    matrix = gauss_method(matrix)
    print(f'\nПрямой ход. {gauss_method.__doc__}:')
    output_matrix(matrix)

    answers = backward_iteration(matrix)
    print("\nОтвет после применения обратного хода:")
    print("; ".join(f"x{i} = {round(x, 4)}" for i, x in enumerate(answers, 1)))

