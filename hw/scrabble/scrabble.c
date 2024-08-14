#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int sum_points(string s);

int main(void)
{
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");
    int sump1 = sum_points(p1);
    int sump2 = sum_points(p2);
    if (sump1 > sump2)
    {
        printf("Player 1 wins!\n");
    }
    else if (sump1 < sump2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int sum_points(string s)
{
    int sum = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z')
        {
            sum += scores[toupper(s[i]) - 'A'];
        }
    }
    return sum;
}
