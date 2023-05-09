#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char rotate(char letter, int key);

int main(int argc, string argv[])
{
    // Give error if input is not a number or if input is n/a
    if (!(argc == 2))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int j = 1; j < argc; j++)
    {
        for (int i = 0, k = strlen(argv[j]); i < k; i++)
        {
            if (!(argv[j][i] >= 48 && argv[j][i] <= 57))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    // Take input from user for input & plaintext
    int keyInput = atoi(argv[1]);
    string plainInput = get_string("plaintext:  ");

    // Convert plain text to cypher text based on key value
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plainInput); i++)
    {
        printf("%c", rotate(plainInput[i], keyInput));
    }
    printf("\n");
    return 0;
}

// barfoo -> for testing
char rotate(char letter, int key)
{
    int charASCII = (key % 26) + letter;
    // Make sure spaces and punctuation aren't changed, below are for upper case letters
    if (letter >= 65 && letter <= 90)
    {
        if (charASCII > 90)
        {
            charASCII -= 26;
        }
    }
    else if (letter >= 97 && letter <= 122)
    {
        if (charASCII > 122)
        {
            charASCII -= 26;
        }
    }
    else
    {
        charASCII = letter;
    }
    char rotateChar = charASCII;
    return rotateChar;
}
