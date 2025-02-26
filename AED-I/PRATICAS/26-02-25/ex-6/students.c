#include <stdio.h>
#include <stdlib.h>
#include "students.h"

int menu(){
    int menu;
    printf("Menu\n1 - Inserir aluno\n2 - Buscar aluno\n3 - Retornar alunos com media superior a 70\n4 - Remover aluno\n");
    printf("\nEscolha: ");
    scanf("%d", &menu);
    return menu;
}

Stud student(){
    Stud student;
    student.nome[0] = 'x';
    scanf("%f", &student.prat);
    scanf("%f", &student.teor);
    return student;
}


Node *nodeStart(){
    return NULL;
}

int isEmptyNode(Node *addr){
    if (addr == NULL)
    return 1;
    else return 0;
}

Node insertStart(Node *node, Stud student){
    Node *insert;
    insert = (Node *) malloc(sizeof(Node));
    insert->next = node;
    insert->student = student;

    return *insert;
}