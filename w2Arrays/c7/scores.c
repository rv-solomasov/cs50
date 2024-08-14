#include <cs50.h>
#include <stdio.h>

const int N = 3;

int main(void)
{
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score%i: ",i+1);
    }

    printf("Average: %.2f\n", (scores[0] + scores[1] + scores[2]) / (float) N);
}
