#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> //malloc and free
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    // NULL is different from NUL and occurs when there's not enough memory. Example essay to *s, not enough storage
    if (s == NULL)
    {
        return 1;
    }
    char *t = malloc(strlen(s+1));
    if (t == NULL)
    {
        return 1;
    }

    // +1 to add the NUL = \0 character in the end
    for (int i = 0, p =  strlen(s) + 1; i < p; i++)
    {
        t[i] = s[i];
    }
    // strcpy(t,s ) to rpelace the for loop function

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);

    // Free the malloc you created incase user decides to have application running in background
    free(t);

    return 0;
}