#include <stdio.h>
#include <math.h>

void main() {
  double x, y;
  printf("Введите x: ");
  scanf("%lf", &x);

  y = (-2) * sqrt(pow(x, 2) + (4 * pow(x, 2) / 3)) - pow(cos(x), 2) / x;

  printf("y(%.3lf) = %lf\n", x, y);
}
