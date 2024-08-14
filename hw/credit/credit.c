#include <cs50.h>
#include <math.h>
#include <stdio.h>

bool valid_card(long card);
bool check_amex(long card);
bool check_visa(long card);
bool check_mc(long card);

int main(void)
{
    long card;
    card = get_long("Number: ");

    if (card % (long) pow(10, 12) > card || card / (long) pow(10, 15) > 10 || !valid_card(card))
    {
        printf("INVALID\n");
    }
    else
    {
        if (check_visa(card))
        {
            printf("VISA\n");
        }
        else if (check_mc(card))
        {
            printf("MASTERCARD\n");
        }
        else if (check_amex(card))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

bool valid_card(long card)
{
    int sum = 0;
    int temp = 0;
    for (int i = 15; i > -1; i--)
    {
        temp = (card / (long) pow(10, i)) % 10;
        if (i % 2 == 1)
        {
            if (temp < 5)
            {
                sum += temp * 2;
            }
            else
            {
                sum = sum + (temp * 2 / 10) + (temp * 2 % 10);
            }
        }
        else
        {
            sum += temp;
        }
    }
    if (sum % 10 == 0)
    {
        return true;
    }
    return false;
}

bool check_visa(long card)
{
    if ((card / (long) pow(10, 15) == 4) || (card / (long) pow(10, 12) == 4))
    {
        return true;
    }
    return false;
}

bool check_amex(long card)
{
    if (card / (long) pow(10, 13) == 34 || card / (long) pow(10, 13) == 37)
    {
        return true;
    }
    return false;
}

bool check_mc(long card)
{
    if (card / (long) pow(10, 14) > 50 && card / (long) pow(10, 14) < 56)
    {
        return true;
    }
    return false;
}
