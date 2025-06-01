#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void change_places(int * A, int n);

int main() {
    srand(time(NULL));
    int n = 12, i;
    int * A = calloc(n, sizeof(int));
    printf("Исх. массив: ");

    for (i = 0; i < n; i++) {
        A[i] = rand() % 20 - 10;
        printf("%d ", A[i]);
    }

    printf("\n");
    change_places(A, n);

    printf("Новый массив: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    free(A);
    scanf("%s");
    return 0;
}

void change_places(int * A, int n) {
    int t;

    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) {
            t = A[i];
            A[i] = A[i + 1];
            A[i + 1] = t;
        }
    }
}
