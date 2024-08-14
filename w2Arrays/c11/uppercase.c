#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //if ((int) s[i] > 96 && (int) s[i] < 123)
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            // printf("%c", (char) ((int) s[i] - 32));
            // printf("%c", s[i] - ('a' - 'A'));
            // printf("%c", s[i] - 32);
            printf("%c", toupper(s[i])); // CAN HANDLE UPPERCASE !!!
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
