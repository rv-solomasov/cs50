#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int meow = get_int("How many times to meow? ");
    for (int i = 0; i < meow; i++)
    {
        printf("meow\n");
    }
}
