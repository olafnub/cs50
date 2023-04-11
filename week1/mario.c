#include <stdio.h>
#include <cs50.h>

int get_size(void);
void print_grid(int n);

int main(void)
{
    // Get size of grid to show a n x n block
    int n = get_size();
    // Prints the grid of bricks from input above
    print_grid(n);
}

int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);
    return n;
}

void print_grid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            printf("#");
        }
        printf("\n");
    }
}