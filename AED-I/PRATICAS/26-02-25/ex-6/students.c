#include <stdio.h>
#include <stdlib.h>
#include "students.h"
#include "aleat.h"

int menu()
{
    int menu;
    printf("Menu\n1 - Inserir aluno (Manual)\n2 - Buscar aluno\n3 - Retornar alunos com media superior a 70\n4 - Remover aluno\n5 - Inserir Alunos Aleatorios (Automatico)\n");
    printf("\nEscolha: ");
    scanf("%d", &menu);
    return menu;
}

Stud student(int code) // [int code] sera trocado por nome
{
    Stud student;
    student.code = code;
    student.prat = rangedRandFloat(0, 49);
    student.teor = rangedRandFloat(0, 49);
    student.final = student.prat + student.teor;
    return student;
}

Stud studentManual(int code)
{
    Stud student;
    student.code = code;
    float prat, teo;
    do
    {
        printf("Digite a nota pratica: ");
        scanf("%f", &prat);
    } while (prat > 50 || prat < 0);
    student.prat = prat;

    do
    {
        printf("Digite a nota pratica: ");
        scanf("%f", &teo);
    } while (teo > 50 || teo < 0);
    student.teor = teo;

    student.final = teo + prat;
    return student;
}
Node *nodeStart()
{
    return NULL;
}

int isEmptyNode(Node *addr)
{
    if (addr == NULL)
        return 1;
    else
        return 0;
}

Node *insertStart(Node *node, Stud student)
{
    Node *insert;
    insert = (Node *)malloc(sizeof(Node));

    if (insert == NULL)
        return insert;

    insert->next = node;
    insert->student = student;

    return insert;
}

void searchStudent(Node *node, int code)
{
    if (node->student.code == code)
        printf("%d\t%.2f%%\n", node->student.code, node->student.final);
    else
        searchStudent(node->next, code);
}
int i = 0;
void searchStudentGrade70(Node *node)
{
    if (node != NULL)
    {

        if (node->student.final > 70)
        {
            i++;
            printf("%d\t%d\t%.2f\n", i, node->student.code, node->student.final);
        }
        searchStudentGrade70(node->next);
    }
}

void removeByName(Node *node, int code)
{
    // verifica se o prox eh o ultimo
    if (node->next != NULL)
    {
        // pego o prox para verificar se e o que quero deletar
        Node *n = node->next;
        if (n->student.code == code)
        {
            // deleto o node seguinte, mas antes defino o next
            // do node atual como o do proximo
            node->next = n->next;
            free(node->next);
        }
        else
            removeByName(node->next, code); // caso recursivo com o prox node se ele nn for o que quero deletar
    }
    else
    {
        return;
    }
}

// usando a função da prof pra ver a lista depois de feita
void percurso(Node *l)
{

    if (l != NULL)
    {
        percurso(l->next);
        printf("%d\t", l->student.code);
        printf("%.2f\t", l->student.prat);
        printf("%.2f\t", l->student.teor);
        printf("%.2f%%  \n", l->student.final);
    }
}