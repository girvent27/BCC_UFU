#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int arr[] = {2, 4, 6, 8, 10}, sum = 0, *b = arr;
    // for (int i = 0; i < 5; i++)
    // {
    //     sum = sum + (*b - i) - *(b - i);
    //     //(*b - i) => *b Pega o valor do endereço arr[b] e faz "arr[4] - i"
    //     //*(b - i) => *(b - 1) Pega a posição, que é "arr[4 - i]"
    //     printf("i = %d; b = 4;\n(*b - i)(%d) - *(b - i)(%d) = %d\nsum = %d\n\n", i, (*b - i), *(b - i), (*b - i) - *(b - i), sum);
    // }
    printf("\n\nPrintando o Array:\n------------------------------\n");

    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, *(b + i));
    }
}