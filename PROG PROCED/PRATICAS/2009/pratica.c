#include <stdio.h>

float med = 0;

float media(float n1, float n2)
{
    float media;
    media = (n1 + n2) / 2;
    return media;
}
void media_global(float n1, float n2)
{
    med = (n1 + n2) / 2;
}
float menor(float n1, float n2)
{
    if (n1 > n2)
    {
        return n2;
    }
    else
    {
        return n1;
    }
}

int main()
{
    int menu_2;
    float a, b;
    char menu[21][20] = {"media", "media glob", "nao fiz", "menor numero"};
    float length = (sizeof(menu) / sizeof(char) / 20);
    do
    {
        printf("__________________________________\n");
        printf("Menu: ");
        printf("\n\n");
        for (int i = 0; i < length; ++i)
        {
            if (sizeof(menu[i]) != 0)
            {
                printf("%d - ", i + 1);
                printf("%s\n", menu[i]);
            }
        }
        printf("\n0 - Sair\n ");
        printf("__________________________________");

        printf("\n  Escolha: ");
        scanf("%d", &menu_2);
    } while (menu_2 < 0 || menu_2 > 21);

    switch (menu_2)
    {
    case 1:
        printf("Escreva dois numeros: ");
        scanf("%f %f", &a, &b);
        printf("A media dos Numeros eh: %.2f", media(a, b));
        break;
    case 2:
        printf("Escreva dois numeros: ");
        scanf("%f %f", &a, &b);
        media_global(a, b);
        printf("A media dos Numeros eh: %.2f", med);
        break;

    case 4:
        printf("Escreva dois numeros: ");
        scanf("%f %f", &a, &b);
        media_global(a, b);
        printf("O menor dos Numeros eh: %.0f", menor(a, b));
        break;
    default:
        menu_2 = 0;
        break;
    }
    printf("\n");
    return 0;
}
