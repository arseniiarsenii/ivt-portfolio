#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 12

void main() {
  srand(time(NULL));
  int *a;
  a = (int *) malloc(12 * sizeof(int));

  printf("Массив A: [ ");
  for(int i = 0; i < N; ++i) {
    a[i] = rand() % 21 - 10;
    printf("%d ", a[i]);
  }
  printf("]");

  // Вычислить y
  double y, u = 0, t;
  int s = N / 2;
  t = abs(a[0]);
  for(int i = 0; i < N; ++i) {
    if (abs(a[i]) > t) t = a[i];
    if (a[i] < 0) u += a[i];
  }

  y = (u + t) * (s + 2);
  printf("\nY = %lg\n", y);
}
