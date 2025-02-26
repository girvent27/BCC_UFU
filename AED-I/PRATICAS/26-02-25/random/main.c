#include <time.h>
#include <stdlib.h>
#include <stdio.h>

char *tab_alphabet="abcdefghijklmnopqrstuvwxyz";

int nombreAlea(int min, int max){
    return (rand()%(max-min+1) + min);
}
void generer_name(int length, char n[]){
    int i ;
    for (i=0;i<length;i++){
        int k = nombreAlea(1,26);// from the table of the alphabet
        n[i] = tab_alphabet[k-1];
    }
    n[i] = '\0';
}

int main (void) {
    char nn[64];
    int a;
    //srand( time( NULL ) );
    a = nombreAlea(4, 6);
    
    printf(" >%s<\n", generer_name(a, nn));
    return 0 ;
}