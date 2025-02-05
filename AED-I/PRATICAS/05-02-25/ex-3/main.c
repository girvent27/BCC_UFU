/*
3) Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endereço de cada posição desse array.

*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    float *arr;
    int N = 10;
    arr = (float *)malloc(sizeof(float) * N);


    for (int i = 0; i < N; i++)
    {
        printf("Digite: ");
        scanf("%f", &arr[i]);
    }
    printf("\nImprimindo\n");
        for (int i = 0; i < N; i++)
    {
        printf("arr[%d] = 0x%x = %.2f\n", i, &arr[i], arr[i]);

    }
    free(arr);
}