#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
int binary[BITS_IN_BYTE];

void print_bulb(int bit);
int powerNumber(int power);

int main(void)
{
    // TODO
    string userInput = get_string("Message: ");

    // Check each user's character and compares its ASCII to each binary appropriate digit. If current binary digit is less than then turn to 1 and subtract char c
    for (int i = 0, n = strlen(userInput); i < n; i++)
    {
        int c = userInput[i];
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            // printf("power: %d - c: %c %d", powerNumber(k), userInput[i], c); // TESTING
            if (powerNumber(k) <= c)
            {
                binary[k] = 1;
                c = c - powerNumber(k);
            }
            else
            {
                binary[k] = 0;
            }
            print_bulb(binary[k]);
        }
        // Loop throug 00000000 to see which one is less than number starting from 7 -> 0
        printf("\n");
    }
}

int powerNumber(int power)
{
    int product = 1;

    for (int j = 0; j < power; j++)
    {
        product *= 2;
    }
    return product;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}