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

 int main() {
    Node *n1;
    criaListaVazia(&n1);
    printf("End. armazenado em n1: %p\n",n1);
 }