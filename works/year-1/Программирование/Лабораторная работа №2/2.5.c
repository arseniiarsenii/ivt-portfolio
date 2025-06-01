#include <stdio.h>

void main() {
  int dig1, dig2, dig3;

  while (1) {
    printf("Введите 3-х значное число: ");
    scanf("%1d%1d%1d", &dig1, &dig2, &dig3);
    if ((dig1 + dig2 + dig3) <= 10) break;
  }

  printf("Работа завершена");
}
