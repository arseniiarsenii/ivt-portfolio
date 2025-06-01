#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 12

void main() {
  srand(time(NULL));
  int *f;
  f = (int *) malloc(12 * sizeof(int));

  printf("Массив F: [ ");
  for(int i = 0; i < N; ++i) {
    f[i] = rand() % 21 - 10;
    printf("%3d ", f[i]);
  }
  printf("]");

  // Вычислить T
  double t, r = 0, q, s = 1;
  for(int i = 0; i < N; ++i) {
    if (f[i] > 0) s *= f[i];
    if (f[i] < 0) {
      r += f[i];
      q = f[i];
    }
  }

  t = (r + q + s) / (r * q * s + 2);
  printf("\nT(%lg) = %lg\n", q, t);
}
