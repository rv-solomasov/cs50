#include <stdio.h>
#include <cs50.h>

void meow(int n); // in case you define the function below call to it

int main(void)
{
    int counter = get_int("How many times to meow? ");
    meow(counter);
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
