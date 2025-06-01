#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main() {
  int const M = 5, N = 5;
  int A[M][N], V[N];
  srand(time(NULL));

  printf("a = ");
  for (int m = 0; m < M; ++m) {
    V[m] = rand() % 10;
    printf("\n%3d ", V[m]);
  }

  printf("\n\nA = \n");
  for (int m = 0; m < M; ++m) {
    for (int n = 0; n < N; ++n) {
      A[m][n] = rand() % 10;
      printf(" %2d", A[m][n]);
    }
    printf("\n");
  }

  printf("\nA * a =");
  for (int m = 0; m < M; ++m) {
    int s = 0;
    for (int n = 0; n < N; ++n) {
      s += A[m][n] * V[n];
    }
    printf("\n%d", s);
  }
}
