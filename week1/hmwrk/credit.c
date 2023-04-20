#include <cs50.h>
#include <stdio.h>

int sumOfDgts(int card, int sumOfEven);
int checkLength(long inputCard, long division);
string checkCard(int sumOfBoth, int length, int firstDgt);

int main(void)
{
    long inputCard = get_long("Input card: ");
    long division = 10;
    int everyOtherDgt = 0;
    int oddDgts = 0;
    int sumOfEven = 0;
    int sumOfBoth = 0;
    int length = checkLength(inputCard,division);
    long firstDgt = 0;
    int useDivision = 0;
    // VISA 4003600000000014, 4012888888881881, 4111111111111111
    // AMEX 378282246310005
    // MAstercard 5105105105105100
    // INVALID 1234567890


    while (division <= inputCard*10)
    {
        everyOtherDgt = (( inputCard % (division * 10 ) ) / division) * 2;
        sumOfEven = sumOfDgts(everyOtherDgt, sumOfEven);
        oddDgts += (inputCard % division) / ( division / 10 );
        division *= 100;
        if (!(division<=inputCard * 10)) {
         if (length == 15)
         {
            useDivision = 10000;
         }
         else if (length == 16)
         {
            if (everyOtherDgt == 8)
            {
                useDivision = 100;
            }
            else if (everyOtherDgt == 10)
            {
                useDivision = 1000;
            };
         }
         else if (length == 13)
         {
            useDivision = 1000;
         }
         else
         {
            useDivision = division/10;
         }
        firstDgt = (( inputCard % division) / (division/useDivision));
        // printf("%ld\n", firstDgt); // testing purposes
        }
    }
    sumOfBoth = sumOfEven + oddDgts;
    printf("%s", checkCard(sumOfBoth, length, firstDgt));
}

int checkLength(long inputCard, long division)
{
    int length = 1;
    while (division <= inputCard)
    {
        length++;
        division*=10;
    }
    return length;
}

int sumOfDgts(int card, int sumOfEven)
{
    if (card % 100 > 9)
    {
        int division = 10;
        for (int i = 0; i < 2; i++)
        {
          sumOfEven+=(card % division) / ( division / 10);
          division *= 10;
        }
    }
    else
    {
        sumOfEven += card;
    };
    return sumOfEven;
}

string checkCard(int sumOfBoth, int length, int firstDgt)
{
    if (sumOfBoth % 10 != 0)
    {
        return "INVALID\n";
    }
    else if (length == 15 && (firstDgt == 34 || firstDgt == 37))
    {
      return "AMEX\n";
    }
    else if ((length == 16 || length == 13) && firstDgt == 4)
    {
        return "VISA\n";
    }
    else if (length == 16)
    {
        for (int k = 1; k < 6; k++)
        {
            if (k == firstDgt % 10)
            {
                return "MASTERCARD\n";
            }
        }
    }
      return "INVALID\n";
}


