#include <stdio.h>

void main() {
  printf("Верхняя граница диапазона: ");
  int i;
  scanf("%d", &i);

  for (int n = 0; n <= i; ++n) {
    printf("%d ", n);
  }
}
