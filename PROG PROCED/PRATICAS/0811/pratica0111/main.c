#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int **arr, n;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);
    arr = (int **)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
}