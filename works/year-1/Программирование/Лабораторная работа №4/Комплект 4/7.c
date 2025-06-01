#include <stdio.h>

int main(void) {
    int a = 1234567890;
    char *p = &a;

    while (p < &a + 1) {
        printf("%d ", *p);
        p++;
    }

    return 0;
}
