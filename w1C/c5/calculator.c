#include <stdio.h>
#include <cs50.h>

int add(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
float div(int a, int b);

int main(void)
{
    char op = get_char("operation? ");
    int x = get_int("x: ");
    int y = get_int("y: ");

    if (op == '+')
    {
        printf("Answer: %i\n", add(x ,y));
    }
    else if (op == '-')
    {
        printf("Answer: %i\n", sub(x ,y));
    }
    else if (op == '*')
    {
        printf("Answer: %i\n", mult(x ,y));
    }
    else if (op == '/')
    {
        printf("Answer: %.6f\n", div(x ,y));
    }
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mult(int a, int b)
{
    return a * b;
}

float div(int a, int b)
{
    return (float) a / b;
}
