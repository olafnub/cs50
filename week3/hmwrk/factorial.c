#include <cs50.h>
#include <stdio.h>

int factorial(int number);

int main(void)
{
    int getFactorial = get_int("Enter a number: ");
    printf("%i\n", factorial(getFactorial));
}

int factorial(int number)
{
    if (number == 1)
    {
        return 1;
    }

    return number * factorial(number-1);
}