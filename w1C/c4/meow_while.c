#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i = get_int("How many times to meow? ");
    while (i > 0)
    {
        printf("meow\n");
        i--;
    }
}
