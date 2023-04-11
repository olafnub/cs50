#include <cs50.h>
#include <stdio.h>

int start;
int end;

int get_start_pop();
int get_end_pop(int start);
int calc_pop(int start, int end);

int main(void)
{

    // Input starting size of the population, must be more than or equal to 9
    start = get_start_pop();
    // Input ending size of population, must be more than or equal to starting size
    end = get_end_pop(start);
    // Calculate the # of year's starting pop will reach ending pop
    int years = calc_pop(start, end);
    // Print of the # of year's
    printf("Years: %i\n", years);
}

int get_start_pop() 
{
    int n;
    do
    {
        n = get_int("Starting population (greater than 9): ");
    }
    while (n < 9);
    return n;
}

int get_end_pop(int start)
{
    int n;
    do
    {
        n = get_int("Ending population (greater than starting): ");
    }
    while (n <= start);
    return n;
}
int calc_pop(int start, int end)
{
    // Grow start/3 - Die start/4
    int n;
    do
    {
        int grow = start/3;
        int die = start/4;
        start+=grow - die;
        n++;
        // Debugging
        // printf("grow: %i \ndie: %i \nstart: %i\n", grow, die, start); 
    }
    while (start < end);
    return n;
}