#include <stdio.h>
#include <math.h>

// подынтегральная функция
double func(double x) {
  return cos(x) / x;
}

void main() {
  double a, b, f, x, f1, f2, h, integral = 0;
  int n = 10000;
  printf("a, b: ");
  scanf("%lg %lg", &a, &b);
  h = (b - a) / n;
  x = a;

  while (x < b) {
      f1 = func(x);
      x += h;
      f2 = func(x);
      f = (f1 + f2) / 2;
      integral += f;
  }

  integral *= h;

  printf("Интеграл = %lg", integral);
}
