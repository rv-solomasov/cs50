#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    int total_l = 2 * height + 2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < height + i + 3; j++)
        {
            if (j < height - i)
            {
                printf(" ");
            }
            else if (j == height + 1)
            {
                printf("  ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
