#include <stdio.h>

typedef char* string;

int main(void)
{
    string s = "HI!";
    printf("%p\n", s);
    printf("%s\n", s);
    printf("%p\n", &s[1]);
}
