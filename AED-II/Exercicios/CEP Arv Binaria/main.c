#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Ana Luiza Moreira Silva -    12411BCC053
    Matheus Martins de Resende - 12411BCC019
    Jean Luc Girvent Deu -       12411BCC101

obs:
1) Utilize um vetor nao muito grande para o codeblocks nao travar.


*/

struct cep
{
    char cep[10];
    char estado[4];
    char cidade[51];
    char rua[101];
};
typedef struct cep Cep;

typedef struct Node Node;

struct Node
{
    Cep postal;
    Node *esq;
    Node *dir;
};

void Inicializa(Node **p)
{
    *p = NULL;
}

void Insere(Cep x, Node **p)
{
    if (*p == NULL)
    {
        *p = (Node *)malloc(sizeof(Node));
        (*p)->postal = x;
        (*p)->esq = NULL;
        (*p)->dir = NULL;
        return;
    }

    if (strcmp(x.cep, (*p)->postal.cep) < 0)
    {
        Insere(x, &(*p)->esq); // endereço do Esq
    }
    else if (strcmp(x.cep, (*p)->postal.cep) > 0)
        Insere(x, &(*p)->dir); // endereço do Dir
    else
        printf("Erro: Registro ja existe na arvore \n");
    // printf("%s", (*p))
}

void Central(Node *p)
{
    if (p == NULL)
        return;
    // printf("Visitando: %s\n", p->postal.cep);
    Central(p->esq);
    printf("%s\n", p->postal.cep);
    Central(p->dir);
}

int main()
{

    struct cep *vetor;
    int cont = 0, n = 20;
    char cep[10], estado[4], cidade[51], rua[101];
    Node *p;

    Inicializa(&p);

    setbuf(stdin, NULL);
    vetor = (Cep *)malloc(sizeof(Cep) * n);

    FILE *arquivo = fopen("cep.txt", "r");

    while (fscanf(arquivo, "%[^;]; %2[^;]; %[^;]; %[^\n]\n", cep, estado, cidade, rua) != EOF)
    {
        strcpy(vetor[cont].cep, cep);
        strcpy(vetor[cont].cidade, cidade);
        strcpy(vetor[cont].estado, estado);
        strcpy(vetor[cont].rua, rua);
        cont++;
    }
    for (int i = 0; i < n; i++)
    {
        // printf("%s\n", vetor[i].cep);
        Insere(vetor[i], &p);
    }
    Central(p);
    free(vetor);
    fclose(arquivo);
    return 0;
}
