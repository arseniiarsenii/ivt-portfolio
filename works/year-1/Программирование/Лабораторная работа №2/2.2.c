#include <stdio.h>

void main() {
  int a[3] = {1, 1, 1}, m, p = 1;
  printf("m = ");
  scanf("%d", &m);

  printf("1 1 1");
  while (p < m) {
    p = a[1] + a[0];
    if (p <= m)
      printf(" %d", p);
    a[0] = a[1];
    a[1] = a[2];
    a[2] = p;
  }
}
