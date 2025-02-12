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


LIST createList(int );
LIST insert(LIST , char , float , int );