#include <stdio.h>
#include <math.h>

void main() {
  double x, y, u, numerator, denominator;
  printf("Введите числа x и y через пробел: ");
  scanf("%lf %lf", &x, &y);

  numerator = 1.0 + pow(sin(x + y), 2.0);
  denominator = 2.0 + fabs(x - ((2 * pow(x, 2.0)) / (1.0 + fabs(sin(x + y)))));
  u = numerator / denominator;

  printf("u(%.3lf, %.3lf) = %lf\n", x, y, u);
}
