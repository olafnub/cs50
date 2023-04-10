#include <stdio.h>
#include <stdlib.h>

int main(int args, char *argv[])
{
    int i, num;
    float sum;

    printf("Enter numbers \n");
    sum = 0;

    for (i = 0; i < 10; i=i+1)
    {
        scanf("%d", &num);
        sum = sum + num;
    };
    printf("Sum = %3.1f\n", sum);
    printf("Average = %3.1f\n", sum / 10.0);
    
    return 0;
}