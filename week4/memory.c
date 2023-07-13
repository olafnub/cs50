#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // int = 4 bytes, to create a memory list of 3, x4 bytes
    int *x = malloc(3 * sizeof(int));
    if (x = NULL)
    {
        return 1;
    }
    x[0] = 1;
    x[1] = 3;
    x[2] = 1;

    free(x);
    return 0;
}