#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("Set value for X: ");
    int y = get_int("Set value for Y: ");
    if (x < y)
    {
        printf("X is less than Y\n");
    }
    else if (x > y)
    {
        printf("X is greater than Y\n");
    }
    else // additional if is not needed (if (x == y))
    {
        printf("X is equal to Y\n");
    }
}
