#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Exemplo Produto
struct Produto
{
    char descricao[100];
    char tipo;
};

typedef struct Produto Produto;

#define N 127
typedef Produto *Hash[N]; // vetor de ponteiros para a estrutura Produto

int hash(Produto p)
{ // função hashing
    return (mapeamento(p) % N);
}

int mapeamento(Produto p)
{
    int resul = 0;
    for (int i; i < strlen(p.descricao); i++)
    {
        resul = +i * (int)p.descricao[i];
    }
    return resul;
}

void hsh_busca(Hash tab, Produto p, char tipo)
{
    int cont = 0;
    int h = hash(p);
    while (tab[h] != NULL)
    {
        if (!strcmp(tab[h]->tipo, tipo))
            printf("Produto: %s /n", tab[h]->descricao);

        h = (h + 1) % N;
    }
}

Produto *hsh_conta(Hash tab, Produto p, char tipo)
{
    int cont = 0;
    int h = hash(p);
    while (tab[h] != NULL)
    {
        if (!strcmp(tab[h]->tipo, tipo))
            cont++;

        h = (h + 1) % N;
    }
    return cont;
}

Produto *hsh_insere(Hash tab, Produto p)
{
    int h = hash(p);
    while (tab[h] != NULL)
    {
        if (!strcmp(tab[h]->descricao, p.descricao))
            break;
        h = (h + 1) % N;
    }

    if (tab[h] == NULL)
    { // não achou o elemento
        tab[h] = (Produto *)malloc(sizeof(Produto));
        strcpy(tab[h]->descricao, p.descricao);
    }

    // atribui/modifica informação

    return tab[h];
}

Produto cria_prod()
{
    Produto p;
    char desc[100]; // precisa ser array, não char simples
    char tipo;      // aqui sim é só um caractere

    printf("Informe o produto: ");
    fgets(desc, sizeof(desc), stdin);
    desc[strcspn(desc, "\n")] = '\0'; // remove o \n lido pelo fgets

    do
    {
        printf("Informe o tipo (A-Alimentação, H-Higiene, V-Vestimenta, L-Limpeza): ");
        scanf(" %c", &tipo);
        tipo = toupper(tipo);
    } while ((tipo != 'A') && (tipo != 'H') && (tipo != 'V') && (tipo != 'L'));

    strcpy(p.descricao, desc);
    p.tipo = tipo; // tipo é só um char, não precisa strcpy

    return p;
}

int main()
{
    setbuf(stdin, NULL);
    int op;
    char prod[100];
    char tipo;
    Produto p;
    Produto tab[N];
    do
    {
        printf("Informe a o pao desejado:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            p = cria_prod();
            hsh_insere(tab, p);
            break;
        case 2:
            printf("Informe o tipo que deseja:");
            scanf("%s", tipo);
            hsh_busca(tab, p, tipo);
            break;
        case 3:
            printf("Alimentacao - %s", hsh_conta(tab, p, 'A'));
            printf("Vestimenta - %s", hsh_conta(tab, p, 'V'));
            printf("Limpeza - %s", hsh_conta(tab, p, 'L'));
            printf("Higiene - %s", hsh_conta(tab, p, 'H'));
            break;
        case 4:
            printf("Saindo");
            break;
        default:
            printf("Opcao invalida");
            break;
        }
    } while (op != 4);
}
