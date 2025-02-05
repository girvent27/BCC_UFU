/*
4) Faça um programa que leia três valores inteiros e chame uma função que receba estes 3 valores de 
entrada e em seguida, retorne este valores ordenados. Ou seja, o menor valor na primeira variável, 
o segundo menor valor na variável do meio, e o maior valor na última variável. 

A função deve retornar o valor 1 se os três valores forem iguais e 0 se existirem valores diferentes. 
Exibir os valores ordenados na tela.
*/

#include<stdio.h>
#include<stdlib.h>

int ordena(int *x, int *y, int *z){
    int aux;
    if (*x == *y && *x == *z)
    {
        return 1;
    } else {
        if (*y < *x)
        {
            aux = *x;
            *x = *y;
            *y = aux;
        }
        if (*z < *y)
        {
            aux = *y;
            *y = *z;
            *z = aux;
        }
        return 0;
    }
    

}

int main(){

    int a, b, c;
    printf("Digite 3 num inteiros: ");
    scanf("%d   %d   %d",&a, &b, &c);

    if(ordena(&a, &b ,&c) == 1){
        printf("Valores iguais...\n");
    }
    if(ordena(&a, &b ,&c) == 0){
        printf("a = %d, b = %d, c = %d\n", a, b, c);
    }
    
}