#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int input_check(string s);
string encrypt(string s, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string raw_key = argv[1];

    if (input_check(raw_key))
    {
        printf("Malformed key\n");
        return 1;
    }

    string input = get_string("plaintext: ");

    int n = strlen(raw_key);

    for (int i = 0; i < n; i++)
    {
        raw_key[i] = toupper(raw_key[i]);
    }

    string output = encrypt(input, raw_key);

    printf("ciphertext: %s\n", output);
    return 0;
}

int input_check(string s)
{
    int check_unique[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int new_val = 0;
    int n = strlen(s);
    if (n == 26)
    {
        for (int i = 0; i < n; i++)
        {
            if (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z')
            {
                for (int j = 0; j < i; j++)
                {
                    if ((int) toupper(s[i]) == check_unique[j])
                    {
                        new_val = 1;
                    }
                }
                if (new_val == 0)
                {
                    check_unique[i] = (int) toupper(s[i]);
                    new_val = 0;
                }
            }
            else
            {
                return 1;
            }
        }
        if (check_unique[25] > 0)
        {
            return 0;
        }
    }
    return 1;
}

string encrypt(string s, string key)
{
    int n = strlen(s);
    string output = s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            output[i] = tolower(key[s[i] - 97]);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            output[i] = key[s[i] - 65];
        }
    }
    return output;
}
