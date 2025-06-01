#include <stdio.h>
#include <math.h>

void main() {
  float x_fl, y_fl, f_fl, num_fl, denom_fl;
  double x_dl, y_dl, f_dl, num_dl, denom_dl;

  printf("x, y: ");
  scanf("%lf %lf", &x_dl, &y_dl);

  x_fl = x_dl;
  y_fl = y_dl;
  num_fl = 1.265 * M_PI / 3;
  denom_fl = sin(x_fl) + abs(cos(x_fl)) + 1;
  f_fl = sqrt(num_fl / denom_fl);
  printf("f(%f, %f) = %f (float variables)\n", x_fl, y_fl, f_fl);

  num_dl = 1.265 * M_PI / 3;
  denom_dl = sin(x_dl) + abs(cos(x_dl)) + 1;
  f_dl = sqrt(num_dl / denom_dl);
  printf("f(%lf, %lf) = %lf (double variables)\n", x_dl, y_dl, f_dl);
}
