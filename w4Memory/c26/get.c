#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // int n;
    // printf("n: ");
    // scanf("%i", &n);

    // printf("n: %i\n", n);

    // char* s = malloc(2);
    char s[4]; // UNSAFE AH
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}
