#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 2;
    int y = 3;

    printf("x: %i y: %i\n", x, y);
    swap(&x, &y);
    printf("x: %i y: %i\n", x, y);

}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}