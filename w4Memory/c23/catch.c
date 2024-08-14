#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[])
{// impossible to implement due to isolated memory space
    for (int i = 1; i < argc; i++)
    {
        uintptr_t ptrValue = (uintptr_t)strtoull(argv[i], NULL, 16);
        int *ptr = (int*)ptrValue;
        printf("Value at %p: %i\n", (void*)ptrValue, *ptr);
    }
}
