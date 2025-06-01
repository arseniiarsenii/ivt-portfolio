#include <stdio.h>

void main() {
    int const N = 3, M = 4;
    int x[N][M], y[N][M], s;

    for (int i = 0; i < N; ++i) {
      s = 0;
      for (int j = 0; j < M; ++j) {
        printf("X[%d][%d] = ", i + 1, j + 1);
        scanf("%d", &x[i][j]);
        s += x[i][j];
      }
      x[i][0] = s / M;
    }

    printf("\n");
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        printf("%d ", x[i][j]);
      }
      printf("\n");
    }
}
