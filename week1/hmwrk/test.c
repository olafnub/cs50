#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x = 23421;
    float y = x % 10000;

    long longA = 10;
    long longB = 20;

    int intA = 10;
    int intB = 20;

    float floatA = 10;
    float floatB = 20;

    printf("%f\n", y/1000);
}