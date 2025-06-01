#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Длина массива: ");
    scanf("%d", &n);
    double *A = calloc(n, sizeof(double));
    double *i = A;

    printf("Значения эл-тов \n");
    while (i < A + n) {
        scanf("%lf", i);
        i++;
    }

    i = A;
    printf("Массив: ");
    while (i < A + n) {
        printf("%lf ", *i);
        i++;
    }

    free(A);
    return 0;
}
