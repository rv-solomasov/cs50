#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string input = get_string("Text: ");
    int num_sentences = 0;
    int num_letters = 0;
    int num_words = 0;

    for (int i = 0, n = strlen(input) + 1; i < n; i++)
    {
        if (input[i] == 32)
        {
            num_words++;
        }
        else if (input[i] == 33 || input[i] == 46 || input[i] == 63)
        {
            num_sentences++;
        }
        else if ((input[i] > 64 && input[i] < 91) || (input[i] > 96 && input[i] < 123))
        {
            num_letters++;
        }
        else if (input[i] == 0)
        {
            num_words++;
        }
    }
    float l = num_letters / (num_words / 100.0);
    float s = num_sentences / (num_words / 100.0);
    int index = (int) round(0.0588 * l - 0.296 * s - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
