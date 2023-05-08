#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkUsageKey(int argc, string argv[]);
char rotate(char letter, int key);

int main(int argc, string argv[])
{
    // Give error if input is not a number or if input is n/a
    int checkError = checkUsageKey(argc, argv);
    if (checkError == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
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

// Loops through input to see if there are required numeric for
int checkUsageKey(int argc, string argv[]) 
{
    int error = 0;
    for (int j = 0; j < argc-1; j++)
    {
        if (argc == 1 || !(argv[1][j] >= 48 && argv[1][j] <= 57))
        {
            error++;
        }
    }
    if (error > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// barfoo
char rotate(char letter, int key)
{
    int charASCII = (key % 26) + letter;
    // Make sure spaces and punctuation aren't changed, below are for upper case letters
    if (letter >= 65 && letter <= 90)
    {
        if (charASCII > 90)
        {
            charASCII-=26;
        }
    }
    else if (letter >= 97 && letter <= 122)
    {
        if (charASCII > 122)
        {
            charASCII-=26;
        }
    }
    else
    {
        charASCII = letter;
    }
    char rotateChar = charASCII;
    return rotateChar;
}
