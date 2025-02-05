#include<stdio.h>
#include<stdlib.h>
/*
1) O que o programa a seguir retorna?

#include <stdio.h>
 typedef struct {
    int dia, mes, ano; 
 } data;

int main (void) {
   printf ("sizeof (data) = %d\n", sizeof (data));
   return 1;
}
==================================================
R: sizeof (data) = 12
*/ 
 typedef struct {
    int dia, mes, ano; 
 } data;
 
int main (void) {
   printf ("sizeof (data) = %d\n", sizeof (data));
   return 1;
}