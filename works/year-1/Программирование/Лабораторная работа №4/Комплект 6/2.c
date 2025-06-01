#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    double source_double;
    int source_int;
    char output_double[1];
    char output_int[1];

    printf("Число типа double: ");
    scanf("%s", output_double);
    printf("Число типа int: ");
    scanf("%s", output_int);

    source_double = atof(output_double);
    source_int = atoi(output_int);
    printf("Строка 1 (double) %lf \nСтрока 2 (int) %d", source_double, source_int);

    return 0;
}
