struct Stud {
    char nome[50];
    float prat, teor, final; 
};
typedef struct Stud Stud;

struct node
{
    Stud student;
    struct node *next;
};
typedef struct node Node;


int menu();

