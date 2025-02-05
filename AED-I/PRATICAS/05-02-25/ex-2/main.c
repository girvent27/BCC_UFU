/*
Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. 
Associe as variáveis aos ponteiros (use &). 
Modifique os valores de cada variável usando os ponteiros.
Imprima os valores das variáveis antes e após a modificação.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int intg = 1, *ip = &intg;
    float real = 1.2,*fp = &real;
    char chrt = 'a', *cp = &chrt;

    printf("%d, %.2f, %c\n", intg, real, chrt);
    printf("0x%d, 0x%d, 0x%d\n\n",ip, fp, cp);

    *ip= 10;
    *fp= 12.2;
    *cp = 'b';

    printf("%d, %.2f, %c\n", intg, real, chrt);
    printf("0x%d, 0x%d, 0x%d\n\n",ip, fp, cp);
}