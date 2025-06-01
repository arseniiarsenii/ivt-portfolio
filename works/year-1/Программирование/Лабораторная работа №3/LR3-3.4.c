#include <stdio.h>
#define N 2

void main() {
  int
    a[N][N] = {{1, -1}, {-1, 1}},
    b[N][N] = {{2, 0}, {-3, 1}},
    c[N][N] = {{3, -1}, {2, 3}},
    ab[N][N] = {0}, cb[N][N] = {0}, abc[N][N] = {0}, cba[N][N] = {0};

  // умножить A на B, С на A
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int p = 0; p < N; ++p) {
        ab[i][j] += a[i][p] * b[p][j];
        cb[i][j] += c[i][p] * b[p][j];
      }
    }
  }

  // домножить на С, на A
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int p = 0; p < N; ++p) {
        abc[i][j] += ab[i][p] * c[p][j];
        cba[i][j] += cb[i][p] * a[p][j];

      }
    }
  }

  // вывести результат
  printf("A*B*C = \n");
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j)
      printf("%3d ", abc[i][j]);
    printf("\n");
  }

  printf("\nC*B*A = \n");
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j)
      printf("%3d ", cba[i][j]);
    printf("\n");
  }
}
