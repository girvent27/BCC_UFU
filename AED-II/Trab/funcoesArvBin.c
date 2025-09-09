#include "head.h"

//criação da arvore
ArvBin* cria_arvBin() {
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NoBin(struct No3* no) {
  if(no == NULL)
    return;
  libera_NoBin(no -> esq);
  libera_NoBin(no -> dir);
  free(no);
  no = NULL;
}

void libera_ArvBin(ArvBin* raiz) {
  if(raiz == NULL)
    return;
  libera_NoBin(*raiz); //liberar cada nó
  free(raiz); //liberar a raiz
}

void insereBin(ArvBin* raiz, struct musica valor, char* str) {
  if(raiz == NULL) return;

  if(*raiz == NULL){
      struct No3 *novo = (struct No3*)malloc(sizeof(struct No3));
      if(novo == NULL) return;

      strcpy(novo->palavra, str);
      strcpy(novo->info.nome, valor.nome);
      strcpy(novo->info.compositor, valor.compositor);
      strcpy(novo->info.estrofe, valor.estrofe);
      novo->info.freq = valor.freq;
      novo->freq = valor.freq;
      novo->esq = NULL;
      novo->dir = NULL;

      *raiz = novo;
      return;
  }

  struct No3* atual = *raiz;
  int cmp = strcmp(str, atual->palavra);

  if(cmp < 0){
      // Inserir na subárvore esquerda
      return insereBin(&(atual->esq), valor, str);
  }
  else if(cmp > 0){
      // Inserir na subárvore direita
      return insereBin(&(atual->dir), valor, str);
  }
  else {
      // Palavra já existe → atualiza se necessário
      if(valor.freq > atual->info.freq){
          strcpy(atual->info.nome, valor.nome);
          strcpy(atual->info.compositor, valor.compositor);
          strcpy(atual->info.estrofe, valor.estrofe);
          atual->info.freq = valor.freq;
          atual->freq += valor.freq;
      }
      return;
  }
}

struct No3* buscaBin(ArvBin* raiz, char* palavra) {
    if (raiz == NULL || *raiz == NULL)
        return NULL;
    char palavra_limpa[100];
    strcpy(palavra_limpa, palavra);
    size_t len = strlen(palavra_limpa);
    if (len > 0 && palavra_limpa[len - 1] == '\n') {
        palavra_limpa[len - 1] = '\0';
    }

    int cmp = strcmp(palavra_limpa, (*raiz)->palavra);
    if (cmp == 0) {
        return (*raiz);
    } else if (cmp < 0) {
        return buscaBin(&((*raiz)->esq), palavra_limpa); 
    } else {
        return buscaBin(&((*raiz)->dir), palavra_limpa); 
    }
}

void salvarPalavraBin(ArvBin *raiz, char* str, char* nomeArq) {
  struct musica musica;
  int resultado;
  char nome[100], compositor[100], linha[256], palavra[100];
  musica.freq = 0; // frequência na música

  FILE *arq = fopen(nomeArq, "r");
  if(arq == NULL) return;

  // Ler nome e compositor (duas primeiras linhas)
  if(!fgets(nome, sizeof(nome), arq) || !fgets(compositor, sizeof(compositor), arq)) {
      fclose(arq);
      return;
  }

  // Remover newlines
  nome[strcspn(nome, "\n")] = '\0';
  compositor[strcspn(compositor, "\n")] = '\0';

  // Limpar palavra a ser inserida
  char str_limpa[100];
  strncpy(str_limpa, str, sizeof(str_limpa)-1);
  str_limpa[sizeof(str_limpa)-1] = '\0';
  for (int i = 0; str_limpa[i]; i++)
      str_limpa[i] = tolower(str_limpa[i]);
  removerPontuacao(str_limpa);

  if(strlen(str_limpa) < 3) {
      fclose(arq);
      return;
  }

  // Contar frequência da palavra na música
  rewind(arq);
  fgets(linha, sizeof(linha), arq); // pular duas primeiras linhas
  fgets(linha, sizeof(linha), arq);

  while(fscanf(arq, "%99s", palavra) == 1) {
      for(int i = 0; palavra[i]; i++)
          palavra[i] = tolower(palavra[i]);
      removerPontuacao(palavra);

      if(strcmp(str_limpa, palavra) == 0)
          musica.freq++;
  }

  // Armazenar estrofe onde a palavra aparece
  rewind(arq);
  fgets(linha, sizeof(linha), arq); // pular duas primeiras linhas
  fgets(linha, sizeof(linha), arq);

  musica.estrofe[0] = '\0';
  while(fgets(linha, sizeof(linha), arq)) {
      char linha_limpa[256];
      strncpy(linha_limpa, linha, sizeof(linha_limpa)-1);
      linha_limpa[sizeof(linha_limpa)-1] = '\0';
      for(int i = 0; linha_limpa[i]; i++)
          linha_limpa[i] = tolower(linha_limpa[i]);
      removerPontuacao(linha_limpa);

      if(strstr(linha_limpa, str_limpa) != NULL) {
          strncpy(musica.estrofe, linha, sizeof(musica.estrofe)-1);
          musica.estrofe[sizeof(musica.estrofe)-1] = '\0';
          break;
      }
  }

  // Copiar nome e compositor 
  strncpy(musica.nome, nome, sizeof(musica.nome)-1);
  musica.nome[sizeof(musica.nome)-1] = '\0';
  strncpy(musica.compositor, compositor, sizeof(musica.compositor)-1);
  musica.compositor[sizeof(musica.compositor)-1] = '\0';

  // Inserir na árvore principal
  insereBin(raiz, musica, str_limpa);

  fclose(arq);
}

void leitura_ArquivoBin(ArvBin* raiz, char* str1) {
    printf("Entrando na leitura de arquivo");
    char palavra[100];

    FILE *arquivo = fopen(str1, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo"); 
        return; 
    }

    // Pular as duas primeiras linhas (nome e compositor)
    fgets(palavra, 100, arquivo);
    fgets(palavra, 100, arquivo);

    while(fscanf(arquivo, "%99s", palavra)==1){
        if(strlen(palavra)>=3 && buscaBin(raiz, palavra)==NULL){
            salvarPalavraBin(raiz, palavra, str1);  
        }
    }


    fclose(arquivo);
}

