struct Livro {
    char titulo[30], autor[30];
    int ano;
    float preco; 
};
typedef struct Livro Livro;
struct Lista{
    Livro *list;
    int size, curr;
};
typedef struct Lista Lista;

int menu();
//++============+Para Criar e Matar Listas+============++
Lista  *emptyVet(int cap);
void killList(Lista *);

//++============+Inserir e Remover Itens+============++

//++============+Listar Itens da Lista+============++