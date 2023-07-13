#include <stdio.h>

int main(void)
{
    int n = 50;
    int r = 20;
    int *p = &n;
    int **k = &p;
    int ***j = &k;
    // printf("%i\n", n);
    // printf("p of n - %p\nk of p - %p\nj of k - %p\n", p, k, j);
    // printf("%p\n", k-p);

    char *s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s[0]);

}

// p of n - 0x16bbd320c
// k of p - 0x16bbd3200
// j of k - 0x16bbd31f8