#include <stdio.h>
#include <stdlib.h>

void output_vector(int * pointer_a, int * pointer_b);
void multiply(int * A, int * B, int * C);

int main() {
    int A[3] = {
        3,
        4,
        5
    };
    int B[3] = {
        4,
        5,
        6
    };
    int C[3];
    int * pointer_a, * pointer_b, * pointer_c;

    pointer_a = A;
    pointer_b = B;
    pointer_c = C;

    output_vector(pointer_a, pointer_b);

    multiply(pointer_a, pointer_b, pointer_c);

    scanf("%d");

    return 0;
}

void output_vector(int * A, int * B) {
    int * adress_A = A;
    int * adress_B = B;

    printf("Вектор A = ");
    while (A < adress_A + 3) {
        printf("[%d] ", * A);
        A++;
    }
    printf("\n");

    printf("Вектор B = ");
    while (B < adress_B + 3) {
        printf("[%d] ", * B);
        B++;
    }
    printf("\n");
}

void multiply(int * A, int * B, int * C) {
    int * adress_C;
    adress_C = C;

    * C = ( * (A + 1) * * (B + 2) - * (A + 2) * * (B + 1));
    *(C + 1) = ( * (A + 2) * * (B) - * (A) * * (B + 2));
    *(C + 2) = ( * (A) * * (B + 1) - * (A + 1) * * (B));

    printf("Произведение векторов: ");
    while (C < adress_C + 3) {
        printf("[%d] ", * C);
        C++;
    }
}
