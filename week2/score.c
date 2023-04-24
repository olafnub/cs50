#include <cs50.h>
#include <stdio.h>

const int N = 3;

float average(int arrays[]);

int main(void)
{
    // int score1 = 77;
    // int score2 = 76;
    // int score3 = 44;

    int scores[N];
    // scores[0] = get_int("Score ");
    // scores[1] = get_int("Score ");
    // scores[2] = get_int("Score ");

    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score ");
    }
    printf("Average: %f\n", average(scores));
}

float average(int arrays[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum+= arrays[i];
    }
    return sum / (float) N;
}