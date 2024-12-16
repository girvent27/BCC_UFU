#include <stdio.h>

void mostra_passos(int i, int j, int arr[], int n)
{
    printf("%d - %d. {", j, i + 1);
    for (int h = 0; h < n; h++)
    {
        printf(" %d ", arr[h]);
    }
    printf("}\n");
}

void arr_read(int array[], int size_of_array)
{
    printf("\n");
    for (int i = 0; i < size_of_array; i++)
    {
        printf("arr[%d] -> %d\n", i, array[i]);
    }
}

void arr()
{
    int const n = 5;
    int cont_i = 0, cont_j = 0;
    // int arr[] = {5, -1, 0, 8, 2}, aux;

    int arr[] = {-1, 0, 2, 5, 8}, aux;
    for (int j = 1; j < n - 2; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
            }
            mostra_passos(i, j, arr, n);

            cont_i++;
        }
        cont_j++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("\narr[%d] -> %d", i, arr[i]);
    }
    printf("\nIteracoes de i: %d e j: %d", cont_i, cont_j);
}

void arr_c()
{
    // int arr[] = {5, -1, 0, 8, 2, -3}, aux;
    int arr[] = {-1, 0, 2, 5, 8, 2}, aux, n;
    n = sizeof(arr) / sizeof(int);

    printf("\n{");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("}\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // printf("\n%d e %d", arr[i], arr[j]);
            if (arr[i] < arr[j])
            {
                aux = arr[j];
                arr[j] = arr[i];
                arr[i] = aux;
            }
            /*else
            {
                arr[i] = arr[i];
                arr[j] = arr[j];
            }*/
            // printf("\n");
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("\narr[%d] -> %d", i, arr[i]);
    }
}

void selec_sort()
{
    int arr[] = {1, 2, 5, 4, 6, 3};
    // int arr[] = {5, -1, 0, 8, 2};
    int aux, n;
    n = sizeof(arr) / sizeof(int);
    aux = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (aux > arr[i])
            aux = arr[i];
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > aux)
            {
                aux = arr[j];
                arr[j] = arr[i];
                arr[i] = aux;
            }
            mostra_passos(i, j, arr, n);
        }
    }
    arr_read(arr, n);
}
typedef struct
{
    float lado;
} quad;
typedef struct
{
    float alt;
    float lar;
} ret;
typedef struct
{
    float raio;
} cir;
typedef union
{
    quad quad;
    ret ret;
    cir cir;
} form;
typedef struct
{
    int etiq;
    form fig;

} Forma;
float area_forma(Forma f)
{
    float area;
    switch (f.etiq)
    {
    case 0:
        area = f.fig.quad.lado * f.fig.quad.lado;
        break;
    case 1:
        area = f.fig.ret.lar * f.fig.quad.lado;

        break;
    case 2:
        area = (f.fig.cir.raio * f.fig.cir.raio) * 3.1415;
        break;
    default:
        break;
    }
    return area;
}
void structure()
{

    int const N = 3;
    Forma arr[N];
    int etiqueta;
    float larg, alt, raio;

    for (int i = 0; i < N; i++)
    {
        do
        {
            printf("\nDigite o formato: \n0 - Quadrado\n1 - Retangulo\n2 - Circulo\n\n Opcao: ");
            scanf("%d", &etiqueta);
        } while (etiqueta > 2 || etiqueta < 0);
        arr[i].etiq = etiqueta;

        if (etiqueta == 0)
        {
            printf("Escreva a largura: ");
            scanf("%f", &larg);
            arr[i].fig.quad.lado = larg;
        }
        if (etiqueta == 1)
        {
            printf("Escreva a largura: ");
            scanf("%f", &larg);
            printf("Escreva a Altura: ");
            scanf("%f", &alt);
            arr[i].fig.ret.alt = alt;
            arr[i].fig.ret.lar = larg;
        }
        if (etiqueta == 2)
        {
            printf("Escreva o Raio: ");
            scanf("%f", &raio);
            arr[i].fig.cir.raio = raio;
        }
    }
    for (int i = 0; i < N; i++)
    {
        printf("%f ", area_forma(arr[i]));
    }
}
void enumbool()
{
    int x;
    enum
    {
        false,
        true
    };
    printf("True: %d e False: %d", true, false);

    x = false;
    if (x)
    {
        printf("\nIsso eh vdd");
    }
    else
    {
        printf("\nIsso eh falso");
    }
}
int main()
{
    int menu_esc;
    char menu[][20] = {"Bubble Sorting", "Compara Todos", "Selection Sorting", "Structure", "Bool in C"};
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
        printf("\n0 - Sair\n");
        printf("__________________________________");

        printf("\n  Escolha: ");
        scanf("%d", &menu_esc);
    } while (menu_esc < 0 || menu_esc > 21);

    switch (menu_esc)
    {
    case 1:
        arr();
        break;
    case 2:
        arr_c();
        break;
    case 3:
        selec_sort();
        break;
    case 4:
        structure();
        break;
    case 5:
        enumbool();
        break;
    default:
        break;
    }
    printf("\n");

    return 0;
}