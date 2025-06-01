#include <stdio.h>
#include <stdlib.h>
#define N 12

void main() {
  int a[N] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144},
      b[N] = {1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16};

  printf("Массив A: [ ");
  for(int i = 0; i < N; ++i) {
    printf("%d ", a[i]);
  }
  printf("]\n");

  printf("Массив B: [ ");
  for(int i = 0; i < N; ++i) {
    printf("%d ", b[i]);
  }
  printf("]");

  int *c, c_len = 0;
  c = (int *) malloc(N * sizeof(int));

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if (a[i] == b[j]) {
        c[c_len] = a[i];
        c_len += 1;
        break;
      }
    }
  }

  printf("\nПересечение: [ ");
  for(int i = 0; i < c_len; ++i) {
    printf("%d ", c[i]);
  }
  printf("]");
}
