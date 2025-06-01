#include <stdio.h>
#define N 2

void main() {
  int
    a[N][N] = {{2, 0}, {-3, 1}},
    a2[N][N] = {0};

  // умножить A на A
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int p = 0; p < N; ++p) {
        a2[i][j] += a[i][p] * a[p][j];
      }
    }
  }

  // вывести результат
  printf("A = \n");
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j)
      printf("%3d ", a[i][j]);
    printf("\n");
  }

  printf("\nf(A) = \n");
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j)
      printf("%3d ", -2 * a2[i][j] + 5 * a[i][j] + 9);
    printf("\n");
  }
}
