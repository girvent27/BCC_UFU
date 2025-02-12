/*
3) Considere o seguinte programa e responda:

   #include <stdio.h> 
   int a=0; 
   void p(int,int); 
   void main(){
      int a = 1;
      p(a,a);
   } 
   void p(int b, int c){
      a = a+1; 
      b = b+1; 
      c = c+1; 
      printf("%d\n",a+b+c);
   }
(a) Qual será o valor impresso?

(b) Suponha que a função p seja modificada para passar os parâmetros por referência. A nova assinatura da função ficaria: void p(int *b, int *c){...}. Nesse caso, qual seria o valor impresso?

*/
#include <stdio.h>
#include <stdlib.h>