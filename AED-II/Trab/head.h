#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct No *ArvAVL;
typedef struct No2 *ArvAVL2;
typedef struct No3 *ArvBin;

struct musica
{
    char nome[100];
    char compositor[100];
    char estrofe[100];
    int freq; // frequencia na musica em que a palavra mais se repete
};
struct No
{
    char palavra[100];
    struct musica info;
    int freq; // frequencia total em todas as musicas
    int alt;
    struct No *esq;
    struct No *dir;
};

struct No2
{
    char palavra[100];
    int freq; // frequencia total em todas as musicas
    int alt;
    struct No2 *esq;
    struct No2 *dir;
};

struct No3
{
    char palavra[100];
    struct musica info;
    int freq;
    struct No3 *esq;
    struct No3 *dir;
};

struct freq_pal
{
    char palavra[100];
    int freq;
};
typedef struct freq_pal Frequencia;

struct musicas
{
    Frequencia *freq;
    struct musica info;
    int qtd;
};
typedef struct musicas Musicas;

// Funções Vetor
void adicionarMusica(Musicas **vet, int *qtd, char *);
void buscarPalavra(Musicas *vet, int qtd, char *palavra);

// Funções para árvore binária de palavras
ArvBin *cria_arvBin();
void libera_ArvBin(ArvBin *raiz);
void libera_NoBin(struct No3 *no);
void insereBin(ArvBin *raiz, struct musica valor, char *str);
struct No3 *buscaBin(ArvBin *raiz, char *palavra);
void leitura_ArquivoBin(ArvBin *raiz, char *str1);
void salvarPalavraBin(ArvBin *raiz, char *str, char *nomeArq);

// Funções para árvore AVL de palavras
ArvAVL *cria_arv();
int maior(int x, int y);
int altura(struct No *no);
int balanceamento(struct No *no);
void libera_No(struct No *no);
void libera_Arv(ArvAVL *raiz);
void rotacaoLL(ArvAVL *raiz);
void rotacaoRR(ArvAVL *raiz);
void rotacaoLR(ArvAVL *raiz);
void rotacaoRL(ArvAVL *raiz);
int insere(ArvAVL *raiz, ArvAVL2 *raiz2, struct musica valor, char *str);
struct No *buscaAVL(ArvAVL *raiz, char *palavra);
void leitura_arquivo(ArvAVL *raiz, ArvAVL2 *raiz2, char *str1);
void salvarPalavra(ArvAVL *raiz, ArvAVL2 *raiz2, char *str, char *nomeArq);
int pontuacao(char c);
void removerPontuacao(char *str);

// Funções para árvore AVL de frequências
ArvAVL2 *cria_arv2();
int altura2(struct No2 *no);
int balanceamento2(struct No2 *no);
void libera_No2(struct No2 *no);
void libera_Arv2(ArvAVL2 *raiz);
void rotacaoLL2(ArvAVL2 *raiz);
void rotacaoRR2(ArvAVL2 *raiz);
void rotacaoLR2(ArvAVL2 *raiz);
void rotacaoRL2(ArvAVL2 *raiz);
struct No2 *procuraMenor(struct No2 *atual);
struct No2 *remove_ArvFreq(ArvAVL2 *raiz, int freq, char *palavra);
struct No2 *buscaPalavra(ArvAVL2 raiz, char *palavra);
void insereFreq(ArvAVL2 *raiz, char *palavra, int freq);
void insereOuAtualiza(ArvAVL2 *raiz, char *palavra, int freq);
void buscaAVLFreq(ArvAVL2 *raiz, int freq);
#endif