#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
// {
//     int i = get_int("i: ");
//     int j = get_int("j: ");

//     if (i == j)
//     {
//         printf("Same\n");
//     }
//     else
//     {
//         printf("Different\n");
//     }
//     printf("%c >> %p\n", 'i', &i);
//     printf("%c >> %p\n", 'j', &j);

//     printf("%s >> %i\n", "j+0", *(&j));
//     printf("%s >> %i\n", "j+1", *(&j + 1));
//     printf("%s >> %i\n", "j+2", *(&j + 2));
//     printf("%s >> %i\n", "j+3", *(&j + 3));
//     printf("%s >> %i\n", "j+4", *(&j + 4));
// }

{
    string s = get_string("s: ");
    string t = get_string("t: ");

    // if (*s == *t) // only manages to compare first char
    // if (!strcmp(s, t))
    int eq = 0;
    int i = 0;
    while (*(s+i) != '\0' && *(t+i) != '\0')
    {
        if (*(s+i) != *(t+i))
        {
            eq = 1;
            break;
        }
        else
        {
            i++;
        }
    }
    if (!eq)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
