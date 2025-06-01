#include <stdio.h>

void iterational_factorial(int a);
int recursive_factorial(int a);

int main() {
    int a;
    printf("Число: ");
    scanf("%d", & a);
    iterational_factorial(a);
    printf("Рекурсивный факториал = %d", recursive_factorial(a));

    return 0;
}

void iterational_factorial(int a) {
    int factorial = 1;

    while (a > 0) {
        factorial *= a;
        --a;
    }

    printf("Циклический факториал = %d \n", factorial);
}

int recursive_factorial(int a) {
    if (a <= 1)
        return 1;
    else
        return a * recursive_factorial(a - 1);
}
