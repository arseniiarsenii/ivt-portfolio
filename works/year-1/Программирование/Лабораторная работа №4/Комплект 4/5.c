#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));

    int n;
    printf("Длина массива: ");
    scanf("%d", &n);
    int *A = calloc(n, sizeof(int));
    int *p = A;

    printf("Массив: ");
    while (p < A + n) {
        *p = rand() % n;
        printf("%d ", *p);
        p++;
    }
    p--;
    printf("\n");

    printf("Массив в обратном порядке: ");
    while (p >= A) {
        printf("%d ", *p);
        p--;
    }

    return 0;
}
