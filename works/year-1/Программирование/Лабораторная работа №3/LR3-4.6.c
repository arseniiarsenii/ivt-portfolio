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
      a[i][j] = (i + j) % 2;
      printf("%3d ", a[i][j]);
    }
    printf("\n");
  }
}
