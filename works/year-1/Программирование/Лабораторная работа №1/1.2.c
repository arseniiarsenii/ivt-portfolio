#include <stdio.h>

void main() {
  printf("Введите числа x и y через пробел: ");
  int x, y;
  scanf("%d %d", &x, &y);
  printf("%d + %d = %d\n", x, y, x + y);
}
