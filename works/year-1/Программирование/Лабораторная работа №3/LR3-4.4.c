#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void main() {
  srand(time(NULL));
  int n, m;
  n = rand() % 10 + 3;
  m = rand() % 10 + 3;

  // объявить матрицу
  int **a = NULL;
  a = (int **) malloc(m * sizeof(int *));
  for (int i = 0; i < m; ++i) {
    a[i] = (int *) malloc(n * sizeof(int));
  }

  // задать и вывести матрицу
  printf("Матрица A[%d x %d]:\n", m, n);
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      a[i][j] = rand() % 21 - 10;
      printf("%3d ", a[i][j]);
    }
    printf("\n");
  }

  // удалить 2 строку
  free(a[1]);
  m -= 1;
  for(int i = 1; i < m; ++i) {
    a[i] = a[i + 1];
  }

  // вывести результат
  printf("\nМатрица A[%d x %d] (удалена 2 строка):\n", m, n);
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      printf("%3d ", a[i][j]);
    }
    printf("\n");
  }
}
