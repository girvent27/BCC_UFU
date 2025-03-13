#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
// TO-DO: TRANSFORMAR EM DINAMICO

int rangedRandNum(int min, int max) { return rand() % (max - min + 1) + min; }

char randName()
{
    srand(time(NULL));
    char arr[50];
    int name = rangedRandNum(4, 5),
        surname = rangedRandNum(5, 7),
        sum = name + surname;
    char consoante[] = "bcdfghjklmnpqrstvwxyz",
         vowel[] = "aeiou";
    printf("%d e %d\ncons = %d vow = %d\n", name, surname, sizeof(consoante), sizeof(vowel));
    for (int na = 0; na < name; na++)
    {
        if (na % 2 == 0)
            arr[na] = consoante[rangedRandNum(0, sizeof(consoante) - 2)];
        else
            arr[na] = vowel[rangedRandNum(0, sizeof(vowel) - 2)];
    }
    arr[name] = ' ';
    for (int na = name + 1; na <= sum; na++)
    {
        if (na % 2 == 0)
            arr[na] = consoante[rangedRandNum(0, sizeof(consoante) - 2)];
        else
            arr[na] = vowel[rangedRandNum(0, sizeof(vowel) - 2)];
    }

    for (int j = sum + 2; j < 50; j++)
    {
        arr[j] = ' ';
    }
    arr[50] = '\0';

    for (int i = 0; i < 50; i++)
        printf("%c", arr[i]);

    printf("\n");
    return arr[50];
}

int main()
{

    char arr[50];
    arr[50] = randName();
    printf("\n%d\n", sizeof(arr));

    printf("%c", arr[1]);
}
