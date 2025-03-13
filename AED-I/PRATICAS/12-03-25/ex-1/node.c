// struct no {
//     int valor;
//     struct no *prox;
//  };
//  typedef struct no No;
 
 
//  void criaListaVazia(No **l){
//     *l = NULL;
//  }
 
//  int main() {
//     No *n1;
//     criaListaVazia(&n1);
//     printf("End. armazenado em n1: %p\n",n1);
//  }

// 1) Usando esta técnica de ponteiro duplo e a estratégia de modularização de codigo, inclua o trecho dado 
// como exemplo num ambiente de programação em linguagem C e  programe funções básicas de busca, inserção e 
// remoção de elementos considerando uma lista encadeada não ordenada de palavras. Em seguida:

// a) Refaça o exercício anterior para que as palavras possam ser 
// lidas de um arquivo texto (*.txt).

// b) Inclua uma função que remova da lista as palavras repetidas.

// c) Inclua uma função que copie em uma nova lista as palavras cujo
// amanho seja um número primo.

// d) Inclua uma funçao recursiva e outra não recursiva para contar
// o número de palavras contidas na lista.

#include "node.h"


int menu(char list[5][10])
{
    int menu;
    printf("Menu\n1 - Inserir aluno (Manual)\n2 - Buscar aluno\n3 - Retornar alunos com media superior a 70\n4 - Remover aluno\n5 - Inserir Alunos Aleatorios (Automatico)\n");
    printf("\nEscolha: ");
    scanf("%d", &menu);
    return menu;
}

void *nodeStart(Node **node){
     *node = NULL;
}

int isEmptyNode(Node *addr)
{
    if (addr == NULL)
        return 1;
    else
        return 0;
}

Node *insertStart(Node *node)
{
    Node *insert;
    insert = (Node *)malloc(sizeof(Node));

    if (insert == NULL)
        return insert;

    insert->next = node;
    

    return insert;
}

void searchValue(Node *node, int code)
{
    if (node->value == code)
        printf("%d\t%.2f%%\n", node->value, node->value);
    else
        searchvalue(node->next, code);
}
int i = 0;

void remove(){
 
 
}

// usando a função da prof pra ver a lista depois de feita
void percurso(Node *l)
{

    if (l != NULL)
    {
        percurso(l->next);
        printf("%d\t", l->value);
    }
}
