#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text, int wordLength);
int count_words(string text, int wordLength);
int count_sentences(string text, int wordLength);
int product_number(float letters, float words, float sentences);

int main(void)
{
    // get a text from user
    string text = get_string("Text: ");
    int wordLength = strlen(text);

    long letters = count_letters(text, wordLength);
    // The word is in lowercase or uppercase 
    // Seperated with spaces = word
    long words = count_words(text, wordLength);
    // Any punctuation including . ? ! = end of sentence
    long sentences = count_sentences(text, wordLength);
    // Output Grade X using Coleman-Liau formula rounded to the nearest int
    // If grade is higher than 16, output Grade 16+, lower than 1 output Before Grade 1
    int grade = product_number(letters, words, sentences);
    
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text, int wordLength)
{
    int countLetters = 0;
    for (int i = 0; i < wordLength; i++)
    {
        char c = tolower(text[i]);
        if (c >= 'a' && c <= 'z')
        {
            countLetters++;
        }

    }
    return countLetters;
}

int count_words(string text, int wordLength)
{
    int countWords = 0;

    for (int i = 0; i < wordLength; i++)
    {
        char c = tolower(text[i]);

        if (c >= 'a' && c <= 'z')
        {
            if (text[i+1] == ' ' || text[i+1] == '.' || text[i+1] == ',' || text[i+1] == ';' || text[i+1] == ':' || text[i+1] == '!' || text[i+1] == '?')
            {
                countWords++;
            }
        }
    }

    if (countWords == 0 && wordLength > 0)
    {
        countWords++;
    }

    return countWords;
}

//  When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.
// 295 letters
// 70 words
// 3 sentences

int count_sentences(string text, int wordLength)
{
    int countSentences = 0;

    for (int i = 0; i < wordLength; i++)
    {
        char c = tolower(text[i]);

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
                countSentences++;
        }
    }

    return countSentences;
}
// Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.

int product_number(float letters, float words, float sentences)
{
    const float L = letters / words * 100;
    const float S = sentences / words * 100;
    float floatIndex = 0.0588 * L - 0.296 * S - 15.8;
    int intIndex = floatIndex;

    if (floatIndex - intIndex >= 0.5)
    {
        intIndex++;
    };
    // printf("%f, %f, %f, %f, %f\n",letters, words, L, S, floatIndex); //debugging
    return intIndex;
}