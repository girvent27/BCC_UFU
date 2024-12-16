#include <stdio.h>
// #include <stdlib.h>

void arr()
{
    int arr[10], x = 0;
    for (int i = 1; i < 20; i++)
    {
        if (i % 2 != 0)
        {
            arr[x] = i;
            x++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d. %d\n", i + 1, arr[i]);
    }
}

void arr_2()
{
    float arr_a[10], arr_b[10], arr_c[10];
    for (int i = 0; i < 10; i++)
    {
        printf("\nDigite o %dth num do 1st vetor: ", i + 1);
        scanf("%f", &arr_a[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("\nDigite o %dth num do 2nd vetor: ", i + 1);
        scanf("%f", &arr_b[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        arr_c[i] = arr_a[i] - arr_b[i];
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d. %.1f\n", i + 1, arr_c[i]);
    }
}

void arr_3()
{
    float num, arr[7], cont_2 = 0, cont_3 = 0, cont_5 = 0;
    for (int i = 0; i < 7; i++)
    {
        printf("Digite um numero entre (0, 9): ");
        scanf("%f", &num);
        while (num < 0 || num > 9)
        {
            printf("Numero Invalido, tente novamente: ");
            scanf("%f", &num);
        }
        arr[i] = num;
    }
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] == 5)
        {
            cont_5++;
        }
        if (arr[i] == 3)
        {
            cont_3++;
        }
        if (arr[i] == 2)
        {
            cont_2++;
        }
    }
    printf("\nTeve: \n -%.0f dois;\n -%.0f tres;\n -%.0f cinco;", cont_2, cont_3, cont_5);
}
void arr_4()
{
    int const n = 2;
    float x[n], y[n], escalar_x = 1, escalar_y = 1, escalar_total;
    for (int i = 0; i < n; i++)
    {
        printf("\nDigite o %dth num dovetor x: ", i + 1);
        scanf("%f", &x[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nDigite o %dth num do vetor y: ", i + 1);
        scanf("%f", &y[i]);
    }
    for (int i = 0; i < n; i++)
    {
        escalar_x = escalar_x * x[i];
        escalar_y = escalar_y * x[i];
    }
    escalar_total = escalar_x + escalar_y;
    printf("O produto escalar dos vetores eh: %.1f", escalar_total);
}

int main()
{
    int menu;
    do
    {
        printf("\n\n Menu\n 1  - array de impares \n 2 - subtracao de vetores \n 3 - Contagem de elmtos no array \n 4 - determinar o produto escalar\n 5\n opcao: ");
        scanf("%d", &menu);
    } while (menu > 10 || menu < 0);
    printf("\n");
    switch (menu)
    {
    case 1:
        arr();
        break;
    case 2:
        arr_2();
        break;
    case 3:
        arr_3();
        break;
    case 4:
        arr_4();
        break;

    default:
        printf("\n");

        return 0;
    }
    printf("\n");

    return 0;
}
