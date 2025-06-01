#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double ** generate_an_array(int m, int n);
void free_an_array(double ** A);
void fill_an_array(double ** A, int m, int n);
void output_an_array(double ** A, int m, int n);

int main() {
    int m, n;
    double ** A;

    printf("Размерность массива (MxN): ");
    scanf("%d%d", & m, & n);
    A = generate_an_array(m, n);
    fill_an_array(A, m, n);
    output_an_array(A, m, n);
    free_an_array(A);
    scanf("%s");

    return 0;
}

double ** generate_an_array(int m, int n) {
    double ** A = calloc(m, sizeof(double));
    for (int i = 0; i < m; i++) {
        A[i] = calloc(n, sizeof(double));
    }

    return A;
}

void free_an_array(double ** A) {
    free(A);
}

void fill_an_array(double ** A, int m, int n) {
    srand(time(NULL));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 999999;
            A[i][j] /= 10000;
        }
    }
}

void output_an_array(double ** A, int m, int n) {
    printf("Выходной массив:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
}
