#include <stdio.h>

void main() {
  int const N = 5;
  int x[N], n;

  for (int i = 0; i < N; ++i) {
    printf("X[%d] = ", i + 1);
    scanf("%d", &n);
    x[i] = n * n;
  }

  printf("Y = [");
  for (int i = 0; i < N; ++i) {
    printf(" %d", x[i]);
  }
  printf(" ]\n");
}
