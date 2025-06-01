#include <stdio.h>

void main() {
  int const N = 5;
  int x[N], n;

  for (int i = 0; i < N; ++i) {
    printf("X[%d] = ", i + 1);
    scanf("%d", &x[i]);
  }

// Без вспомогательного массива
  printf("[");
  for (int i = N - 1; i >= 0; --i) {
    printf(" %d", x[i]);
  }
  printf(" ]\n");

// С привлечением вспомогательного массива
  int y[N];

  for (int i = 0; i < N; ++i) {
    y[N - i - 1] = x[i];
  }

  printf("[");
  for (int i = 0; i < N; ++i) {
    printf(" %d", y[i]);
  }
  printf(" ]\n");
}
