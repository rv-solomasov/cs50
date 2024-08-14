#include <stdio.h>

int main(void)
{
    int n = 50;
    int* p = &n; //declaring a pointer
    printf("%i\n", *p); //calling a pointer (i.e go to &n )
}
