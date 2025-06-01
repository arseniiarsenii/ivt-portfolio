#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    int i;
    char string[20] = "gRoMh2O01, blg m0ney";

    printf("Original string \n%s \n", string);

    for (i = 0; i < 20; i++) {
        printf("%c - ", string[i]);
        if (isalnum(string[i]) != 0) {
            printf(" alphanumeric,");
            if (isalpha(string[i]) != 0) {
                printf(" alphabetic,");
                if (isupper(string[i]) != 0) {
                    printf(" in upper case \n");
                } else {
                    printf(" in lower case \n");
                }
            } else {
                printf(" digit \n");
            }
        } else {
            if (isspace(string[i]) != 0) {
                printf(" space \n");
            }
            if (ispunct(string[i]) != 0) {
                printf(" punctuation character \n");
            }
        }
    }

    scanf("%s");

    return 0;
}
