#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string name = get_string("What is your name? ");

    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }
    printf("%i\n", n);

    int j = strlen(name);
    printf("%i\n", j);


}