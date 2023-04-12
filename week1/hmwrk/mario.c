#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // To get the amount of hashes for the base to top
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    // To create the hashes
    // input rows -> 3
    // **#
    // *##
    // ###

    // Guide to creating the stairs
    // n = height given
    // spaces for line one prints n-1 then n-2 for line two then n-3
    // at the end of each line is i = 0; i++ ; i < n then print new line at the very end

    for (int i = 1; i <= height; i++)
    {
        for (int k = height; k > i; k--)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}