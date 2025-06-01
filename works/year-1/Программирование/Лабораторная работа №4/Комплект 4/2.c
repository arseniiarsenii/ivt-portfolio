#include <stdio.h>

int main() {
    int a = 2, b = 3;
    printf("a = %d; b = %d \n", a, b);
    int *p1 = &a, *p2 = &b;
    int sum = *p1 + *p2;
    printf("sum = %d", sum);
    return 0;
}
