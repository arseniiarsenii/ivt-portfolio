#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int n, i, j;

    printf("Сторона матрицы: ");
    scanf("%d", &n);

    int **A = malloc(n * sizeof(int));
    int *t = malloc(n * n * sizeof(int));
    for (i = 0; i < n; i++) {
        A[i] = t + i * n;
    }

    printf("Адреса эл-тов в памяти:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", &A[i][j]);
        }
        printf("\n");
    }

    free(A);
    free(t);
    return 0;
}
