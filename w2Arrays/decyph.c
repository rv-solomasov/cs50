#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string in = get_string("Cypher: "); // add \0 to break string
    char out[strlen(in)];
    int i = 0;
    do
    {
        if ((in[i] >= 'A' && in[i] <= 'Z') || (in[i] >= 'a' && in[i] <= 'z'))
        {
            out[i] = in[i] - 1;
        }
        else
        {
            out[i] = in[i];
        }
        i++;
    }
    while (in[i] != '\0');
    printf("Decrypted %s\n", out);
}
