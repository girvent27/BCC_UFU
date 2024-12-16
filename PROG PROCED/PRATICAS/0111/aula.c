#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *x;
    x = (int *)malloc(sizeof(int) * 10000);
    x[9876] = 1234;

    printf("\n%d e %d", x[9876], sizeof(int));
}