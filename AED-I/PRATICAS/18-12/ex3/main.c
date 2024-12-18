#include <stdio.h>
#include <stdlib.h>
#include "header/mdc.h"

int main(){
    int x, y;
    printf("Didite 3 num: ");
    scanf("%d %d", &x,&y);

    printf("O MDC eh: %d", mdc(x,y));
}