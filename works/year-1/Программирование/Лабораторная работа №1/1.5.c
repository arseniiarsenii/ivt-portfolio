#include <stdio.h>
#include <math.h>

void main() {
  double x, h, a, b, c;
  printf("Введите числа a, b, c, x через пробел: ");
  scanf("%lf %lf %lf %lf", &a, &b, &c, &x);

  h = (-1) * ((x - a) / cbrt(pow(x, 2) + pow(a, 2))) - ((4 * pow(pow(pow(x, 2) \
  + pow(b, 2), 3), 1.0 / 4.0)) / (2 + a + b + pow(pow(x - c, 2), 1.0 / 3.0)));

  printf("h(%.3lf) = %lf (при a = %.2lf; b = %.1lf, c = %.1lf)\n", x, h, a, b, c);
}
