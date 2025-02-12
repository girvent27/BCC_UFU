typedef struct {
    int codProd;        //código do PRODUTO
    char nomeProd[10];  //nome do PRODUTO
    float valor;        //valor do PRODUTO
    int qtdeEstoque;    //quantidade disponível em estoque
} PRODUTO;
  
typedef struct {
    PRODUTO *prods;
    int size, max;
  
} LIST;

LIST * createList(int num){
    LIST *pnt;
    pnt = (LIST*) malloc(sizeof(LIST));
    pnt->prods = (PRODUTO*)malloc(num * sizeof(PRODUTO));
    pnt->size = 0;
    pnt->max = num;
  
    return pnt;
  }
  LIST * insert(LIST vet, char nome, float val, int estq){
    printf("%d",sizeof(vet));
  }