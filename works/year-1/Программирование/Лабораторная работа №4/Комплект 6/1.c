#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MY_SIZE 14

int main(void) {
    int input_size = 0, i;
    char my_string[MY_SIZE];

    printf("Строка: \n");
    fgets(my_string, MY_SIZE, stdin);

    for (i = 0; i < MY_SIZE; i++) {

        {
            input_size++;
        } else {
            break;
        }
    }
    printf("1) Length of entered string (calculated by cycle) %d \n", input_size);

    input_size = 0;

    char * pointer;
    pointer = my_string;

    while (pointer < my_string + MY_SIZE) {

        {
            input_size++;
        } else {
            break;
        }
        pointer++;
    }
    printf("2) Length of entered string (calculated by pointer) %d \n", input_size);

    printf("3) Length of entered string (calculated by strnlen() including enter) %zu \n", strnlen(my_string, MY_SIZE));

    char copied_string[MY_SIZE];
    strncpy(copied_string, my_string, MY_SIZE);
    printf("4) Copied string %s", copied_string);

    srand(time(NULL));
    int m, n;

    m = rand() % 4 + 2;
    n = rand() % 4 + 2;

    char * string_1 = calloc(n + m + 3, sizeof(char));
    char * string_2 = calloc(m + 1, sizeof(char));

    printf("5) \nFirst generated string \n");
    for (i = 0; i < n; i++) {
        string_1[i] = rand() % 25 + 65;
        printf("%c", string_1[i]);
    }
    printf("\n");

    printf("Second generated string \n");
    for (i = 0; i < m; i++) {
        string_2[i] = rand() % 25 + 65;
        printf("%c", string_2[i]);
    }
    printf("\n");

    strncat(string_1, string_2, m + n);
    printf("Concatenated string %s \n", string_1);

    free(string_1);
    free(string_2);

    string_1 = "abcda";
    string_2 = "aboba";

    printf("6) \nFirst string \n%s \n", string_1);
    printf("Second string\n%s\n", string_2);

    if (strncmp(string_1, string_2, 5) == 0) {
        printf("Strings are same \n");
    } else {
        printf("Strings are not same \n");
    }

    char reg_string[9] = "aBCDefGh";

    printf("7) \nOriginal string \n%s\n", reg_string);

    for (i = 0; i < 9; i++) {
        reg_string[i] = toupper(reg_string[i]);
    }
    printf("String in upper case %s \n", reg_string);

    for (i = 0; i < 9; i++) {
        reg_string[i] = tolower(reg_string[i]);
    }
    printf("String in upper case %s \n", reg_string);

    scanf("%s");

    return 0;
}
