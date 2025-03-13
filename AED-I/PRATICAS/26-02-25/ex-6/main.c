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
    void searchStudent(Node *node, char search){
        if (student.name == search)
            printf("Nome: %s\nNotas: %.2f\n", student.name, student.nota + student.nota2);
        else
            searchStudent(node->next, search);
    }

3 - Retornar alunos com média superior a 70
    void searchStudentGrade70(Node *node){
        if (node->student.name == 70){
            printf("Nome: %s\nMédia: %.2f\n", student.name, student.final);
            searchStudentGrade70(node->next);
        }else{
            searchStudentGrade70(node->next);
        }
    }
4 - Remover aluno - Informar o nome e remover da lista.\n

    !! NAO VAI FUNCIONAR NO ULTIMO OU SE TIVER SO UM NA LISTA (Nao tem prox pra testar, duh) !!
    void removeByName(Node *node, char name){
        if(node->next != NULL){
            Node *n = node->next;
            if (n->student.name == search){
                node->next = n->next;
                free(*node->next);
            }else{
                removeByName(node->next);
            }
        } else {
            return NULL
        }
    }
*/
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "students.h"
#include "aleat.h"

int main()
{
    Node *node = nodeStart();
    srand(time(NULL));
    int men = 0, qtd = 0, search, i = 0;
    do
    {
        printf("\n\nv.1.2.b ==> Ainda usando codigo Int para alunos invés de nome\nporque o gerador de nome ainda nao funciona\n\n\n");
        men = menu();
        switch (men)
        {

        case 1:
            node = insertStart(node, studentManual(2000 + i));
            i++;
            printf("\nCod\tPrat\tTeo\tMedia\n");
            percurso(node);
            sleep(3);

            break;
        case 2:

            printf("Digite o codigo do aluno: ");
            scanf("%d", &search);
            printf("Cod\tMedia\n");
            searchStudent(node, search);
            sleep(3);

            break;
        case 3:

            printf("Num\tCod\tMedia\n");
            searchStudentGrade70(node);
            sleep(3);

            break;
        case 4:
            printf("Digite o codigo do aluno: ");
            scanf("%d", &search);
            removeByName(node, search);
            percurso(node);

            sleep(3);
            break;
        case 5:

            printf("Digite a quantidade de alunos (Eles serao gerados automaticamente): ");
            scanf("%d", &qtd);
            int qtdAtual = qtd + i;
            for (i; i < qtdAtual; i++)
                node = insertStart(node, student(2000 + i));

            printf("\nCod\tPrat\tTeo\tMedia\n");
            percurso(node);
            sleep(3);

            break;
        default:
            // killList(&x);
            return 0;
            break;
        }
    } while (men < 6 || men > 0);

    return 0;
}