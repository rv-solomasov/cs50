#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char c = get_char("Do you agree? ");

    if (c == 'y' || c == 'Y') // or is '||', and is '&&'
    {
        printf("Agreed.\n");
    }
    else if (c == 'n' || c == 'n')
    {
        printf("Not agreed.\n");
    }
}
