/*
Sejam as duas funções abaixo:

void trocaA(int x, int y) { 
  int temp = x; 
  x = y; 
  y = temp; }
void trocaB(int *x, int *y) {
 int temp = *x; 
 *x = *y; 
 *y = temp; }
Mostre o resultado para as chamadas no programa principal e explique o modelo de passagem de parâmetros de ambas.

int main() { 
  int a = 5, b = 10; 
  printf("Antes da trocaA: a = %d, b = %d\n", a, b); 
  trocaA(a, b); 
  printf("Depois da trocaA: a = %d, b = %d\n", a, b); 

  printf("Antes da trocaB: a = %d, b = %d\n", a, b); 
  trocaB(&a, &b); 
  printf("Depois da trocaB: a = %d, b = %d\n", a, b); 
  return 0; 
}
*/
#include <stdio.h>
#include <stdlib.h>