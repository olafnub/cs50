#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z') //replace with islower
        {
            printf("%c", s[i] - 32); // replace with toupper
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}