/*
Descrição: Usando estrutura de nós encadeados, defina uma estrutura para 
a organização das informações de um aluno, contando com seu nome (podendo 
conter espaços\), nota prática (até 50) e nota teórica (até 50) de uma disciplina. 
Organize o código para que se possa:

struct Stud {
    char nome[50];
    float nota; 
};
typedef struct Stud Stud;

criar uma lista vazia
inserir alunos (nome, nota prática, nota teórica)
retornar a nota final de um determinado aluno
retornar os alunos com média superior a 70
remover um aluno (e suas notas)  
Faça um menu da seguinte maneira:

1 - Inserir aluno - Informar: nome (podendo conter espaços), nota prática (até 50) e nota teórica (até 50)
2 - Buscar aluno - Informar o nome completo e retornar a soma das notas.
3 - Retornar alunos com média superior a 70
4 - Remover aluno - Informar o nome e remover da lista.\n
*/

#include<stdio.h>
#include<stdlib.h>
#include "students.h"

int main(){
    int men = 0;
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
            //killList(&x);
            return 0;
            break;
        }
    } while (men < 5 || men > 0);
    
    return 0;
}