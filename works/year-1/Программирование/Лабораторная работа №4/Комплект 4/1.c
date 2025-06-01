#include <stdio.h>

int main(void) {
    double **ptr = NULL;
    double a = 2.0;
    double *b = &a;
    ptr = &b;
    printf("%f", **ptr);
    return 0;
}
