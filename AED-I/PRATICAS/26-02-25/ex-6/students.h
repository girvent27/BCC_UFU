struct Stud
{
    int code;
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
Stud student(int);
Stud studentManual(int);
Node *nodeStart();
int isEmptyNode(Node *);
Node *insertStart(Node *, Stud);
void searchStudent(Node *, int);
void searchStudentGrade70(Node *);
void removeByName(Node *, int);
// funçaõ da prof, não mexer
void percurso(Node *);
