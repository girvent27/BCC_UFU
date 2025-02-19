/*
Exercício 6: Seja a estrutura Livro a seguir: 

struct Livro {
    char titulo[30], autor[30];
    int ano;
    float preco; 
};
  

Crie um TAD lista utilizando vetor alocado dinamicamente e faça funções para:

1 - Iniciar a lista (criando um vetor dinâmico com capacidade inicial definida).
2 - Inserir um novo livro (expandindo a lista com realloc se necessário).
3 - Remover um livro pelo título (deslocando os elementos para evitar espaços vazios).
4 - Listar todos os livros cadastrados.
O programa principal (main) deve apresentar um menu de opções para o usuário escolher a operação desejada. 

Sugestão de Estrutura de Arquivos:

livros.h – Declarações da estrutura e das funções.
livros.c – Implementação das funções.
main.c – Interação com o usuário e chamada das funções.
*/


#include<stdio.h>
#include<stdlib.h>
# include "livros.h"


int main(){
    int men = 0;
    Lista *x;
    do
    {
        men = menu();
        switch (men)
        {
        case 1:
            printf("Oi");
            break;
        case 2:
            printf("hi");
            break;
        case 3:
            printf("tchau");
            break;
        case 4:
            printf("bye");
            break;
        default:
            break;
        }
    } while (men > 4 || men < 0);
    killList(&x);
    return 0;
}