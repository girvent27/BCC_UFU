#include <stdio.h>
#include <stdlib.h>

// binnary search
int pesquisa_binaria(int *v, int elm, int search)
{
    int maior = elm, menor = 0;

    while (menor <= maior)
    {
        int meio = menor + (maior - menor) / 2;
        if (v[meio] == search)
        {
            return meio;
        }

        if (v[meio] < search)
        {
            menor = meio + 1;
        }
        else
        {
            maior = meio - 1;
        }
    }
    return -1;
}

// main func
int main()
{
    int *arr, N = 10, search;
    arr = (int *)malloc(sizeof(int) * 10);
    // int v[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}, N = 10;

    // printf("Digite o  elemento que voce procura: ");
    scanf("%d", &search);
    // printf("Digite o n de elementos: ");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        // printf("Digite: ");
        scanf("%d", &arr[i]);
    }

    printf("Resultado: arr[%d]\n", pesquisa_binaria(arr, N, search));
}