#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int mynum = atoi(argv[1]);
        if (mynum == (int) argv[1][0])
        {
            printf("It's a match!\n");
        }
        else{
            printf("No match :(\n%i - new\n%li - old\n;",mynum, (long) argv[1]);
        }
    }
}
