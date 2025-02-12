/*
2) Qual é a saída do seguinte código? Explique.

#include <stdio.h>
void f(int *j) {
  (*j)++;
}

int main() {
  int i = 20;
  int *p = &i;
  f(p);
  printf("i = %d\n", i);
  return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>