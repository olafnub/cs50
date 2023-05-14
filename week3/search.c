#include <cs50.h>
#include <stdio.h>
// Compare string, not using ==
#include <string.h>


int numbers();
int monopoly();

int main(void)
{
    // numbers();
    monopoly();
}

int numbers(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 50};

    int number = get_int("Number: ");
    // Linear Search O(n)
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == number)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}

int monopoly(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");

    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
             printf("Found\n");
            return 0;
        }
    }

    return 1;
}