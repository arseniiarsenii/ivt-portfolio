#include <stdio.h>

int main() {
    int a, b;
    int *p1 = &a, *p2 = &b;

    printf("A, B: ");
    scanf("%d %d", &a, &b);

    if (*p1 > *p2) {
        printf("A > B");
    }
    else if (*p1 < *p2) {
        printf("A < B");
    }
    else {
        printf("A = B");
    }
    return 0;
}
