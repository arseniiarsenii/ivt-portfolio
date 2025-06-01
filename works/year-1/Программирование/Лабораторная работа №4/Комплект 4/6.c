#include <stdio.h>

int main(void) {
#define n 10
    int t;
    int A[n] = {1, 12, 9, 23, 55, 87, 11, 8, 4, 33};
    int *i = A;
    int *j = A;

    printf("Исходный массив: ");
    while (i < A + n) {
        printf("%d ", *i);
        i++;
    }
    i = A;
    printf("\n");

    while (i < A + n) {
        j = i;
        while (j < A + n) {
            if (*i > *j) {
                t = *i;
                *i = *j;
                *j = t;
            }
            j++;
        }
        i++;
    }
    i = A;

    printf("Отстортированный массив: ");
    while (i < A + n) {
        printf("%d ", *i);
        i++;
    }

    return 0;
}
