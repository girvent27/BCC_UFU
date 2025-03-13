#include <stdio.h>
#include <stdlib.h>

int rangedRandInt(int min, int max) { return rand() % (max - min + 1) + min; }

float rangedRandFloat(int min, int max) { return (float)(rand() % (max - min + 1) + min) + (float)(rand() % (99 - 0 + 1) + 0) / 100; }

// char randName()
// {
//     srand(time(NULL));
//     char arr[50];
//     int name = rangedRandNum(4, 5),
//         surname = rangedRandNum(5, 7),
//         sum = name + surname;
//     char consoante[] = "bcdfghjklmnpqrstvwxyz",
//          vowel[] = "aeiou";
//     printf("%d e %d\ncons = %d vow = %d\n", name, surname, sizeof(consoante), sizeof(vowel));
//     for (int na = 0; na < name; na++)
//     {
//         if (na % 2 == 0)
//             arr[na] = consoante[rangedRandNum(0, sizeof(consoante) - 2)];
//         else
//             arr[na] = vowel[rangedRandNum(0, sizeof(vowel) - 2)];
//     }
//     arr[name] = ' ';
//     for (int na = name + 1; na <= sum; na++)
//     {
//         if (na % 2 == 0)
//             arr[na] = consoante[rangedRandNum(0, sizeof(consoante) - 2)];
//         else
//             arr[na] = vowel[rangedRandNum(0, sizeof(vowel) - 2)];
//     }

//     for (int j = sum + 2; j < 50; j++)
//     {
//         arr[j] = ' ';
//     }
//     arr[50] = '\0';

//     for (int i = 0; i < 50; i++)
//         printf("%c", arr[i]);

//     printf("\n");
//     return arr[50];
// }