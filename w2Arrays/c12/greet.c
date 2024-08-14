#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc >= 2)
    {
        printf("Hello, %s\n", argv[argc-1]);
    }
    else
    {
        printf("Hello, world\n");
    }
}
