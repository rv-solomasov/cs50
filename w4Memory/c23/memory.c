#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;

    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%i >> %p\n", x[i], &x[i]);
    // }

    // while (1)
    // {
    // }
    free(x);
}
