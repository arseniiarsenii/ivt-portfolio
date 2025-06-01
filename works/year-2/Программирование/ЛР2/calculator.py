def f():
    return '100'



def main():
    # Функция main позволяет ввести значения
    # с клавиатуры и запустить вычисление действия калькулятора
    operand1 = float(input("Введите 1 число:"))
    operand2 = float(input("Введите 2 число:"))
    action = input("Введите действие: ")
    # # print(type(operand1), operand2)
    res = calculate(operand1, operand2, action)
    print("Результат вычисления:", res)


def calculate(op1, op2, act):
    # 2-3 дополнительных действия с двумя операндами

    if act == "+":
        r = op1 + op2
    elif act == "-":
        r = op1 - op2
    elif act == "*":
        r = op1 * op2
    elif act == "/":
        if op2 != 0:
            r = op1 / op2
        else:
            r = "деление на ноль невозможно"
    elif act == "^":
        r = op1 ** op2
    elif act == "//":
        r = op1 // op2
    elif act == "%":
        r = op1 % op2
    else:
        r = "операция не распознана"

    return r


main()
