#include "head.h"
//Criação da arvore para frequencias
ArvAVL2* cria_arv2(){
    ArvAVL2* raiz2 = (ArvAVL2*)malloc(sizeof(ArvAVL2));
    if(raiz2 != NULL)
        *raiz2 = NULL;
    return raiz2;
}

//Liberar cada nó
void libera_No2(struct No2* no){
    if(no == NULL)
        return;
    libera_No2(no->esq);
    libera_No2(no->dir);
    free(no);
    no = NULL;
}

//Liberar a arvore
void libera_Arv2(ArvAVL2* raiz){
    if(raiz == NULL)
        return;
    libera_No2(*raiz); //liberar cada nó
    free(raiz); //liberar a raiz
}

//Calculo da altura de um nó
int altura2(struct No2* no){
    if(no == NULL)
        return -1;
    else 
        return no->alt;
}


//Calcular o balanceamento de um nó
int balanceamento2(struct No2* no){
    if (no==NULL) return 0;
    return (altura2(no->esq)-altura2(no->dir));
}

//Rotação Simples a direita
void rotacaoLL2(ArvAVL2 *raiz){
    struct No2* no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir=*raiz;
    (*raiz)->alt = maior(altura2((*raiz)->esq), altura2((*raiz)->dir))+1;
    no->alt=maior(altura2(no->esq), (*raiz)->alt)+1;
    *raiz = no;
}

//Rotacao Simples a esquerda
void rotacaoRR2(ArvAVL2 *raiz){
    struct No2* no;
    no = (*raiz)->dir;
    (*raiz)->dir=no->esq;
    no->esq=(*raiz);
    (*raiz)->alt = maior(altura2((*raiz)->esq), altura2((*raiz)->dir))+1;
    no->alt=maior(altura2(no->dir), (*raiz)->alt)+1;
    (*raiz)=no;
}

//Rotacao dupla, primeiro a esquerda e depois a direita
void rotacaoLR2(ArvAVL2 *raiz){
    rotacaoRR2(&(*raiz)->esq);
    rotacaoLL2(raiz);
}

//Rotacao Dupla, primeiro a direita e depois a esquerda
void rotacaoRL2(ArvAVL2 *raiz){
    rotacaoLL2(&(*raiz)->dir);
    rotacaoRR2(raiz);
}

//Procurar menor nó para auxiliar na remoção
struct No2* procuraMenor(struct No2* atual){
    if(atual==NULL) return NULL;

    struct No2* no2 = atual;
    while(no2->esq!=NULL){
        no2=no2->esq;
    }
    return no2;
}

//Remoção de palavra repetida
struct No2* remove_ArvFreq(ArvAVL2 *raiz, int freq, char* palavra) {
    if (raiz == NULL || *raiz == NULL) {
        return NULL;
    }

    struct No2* temp;
    int cmp;

    if (freq < (*raiz)->freq) {
        (*raiz)->esq = remove_ArvFreq(&(*raiz)->esq, freq, palavra);
    } else if (freq > (*raiz)->freq) {
        (*raiz)->dir = remove_ArvFreq(&(*raiz)->dir, freq, palavra);
    } else {
        cmp = strcmp(palavra, (*raiz)->palavra);
        if (cmp < 0) {
            (*raiz)->esq = remove_ArvFreq(&(*raiz)->esq, freq, palavra);
        } else if (cmp > 0) {
            (*raiz)->dir = remove_ArvFreq(&(*raiz)->dir, freq, palavra);
        } else {
            // nó encontrado
            if (((*raiz)->esq == NULL) || ((*raiz)->dir == NULL)) {
                temp = *raiz;
                if ((*raiz)->esq != NULL)
                    *raiz = (*raiz)->esq;
                else
                    *raiz = (*raiz)->dir;
                free(temp);
            } else {
                temp = procuraMenor((*raiz)->dir);
                strcpy((*raiz)->palavra, temp->palavra);
                (*raiz)->freq = temp->freq;
                (*raiz)->dir = remove_ArvFreq(&(*raiz)->dir, temp->freq, temp->palavra);
            }
        }
    }

    if (*raiz == NULL) return NULL;

    // rebalancear
    (*raiz)->alt = maior(altura2((*raiz)->esq), altura2((*raiz)->dir)) + 1;
    int balanco = balanceamento2(*raiz);

    if (balanco > 1 && balanceamento2((*raiz)->esq) >= 0)
        rotacaoLL2(raiz);
    else if (balanco > 1 && balanceamento2((*raiz)->esq) < 0)
        rotacaoLR2(raiz);
    else if (balanco < -1 && balanceamento2((*raiz)->dir) <= 0)
        rotacaoRR2(raiz);
    else if (balanco < -1 && balanceamento2((*raiz)->dir) > 0)
        rotacaoRL2(raiz);

    return *raiz;
}

//Busca por palavra na arvore de frequencia
struct No2* buscaPalavra (ArvAVL2 raiz, char* palavra){
    if(raiz == NULL) {
        return NULL;
    }

    int cmp = strcmp(palavra, raiz->palavra);
    if(cmp == 0) {
       return raiz;
    } else if(cmp<0) {
        return buscaPalavra(raiz->esq, palavra);
    } else {
        return buscaPalavra(raiz->dir,palavra);
    } 
}

//Inserção na arvore de frequencias
void insereFreq(ArvAVL2 *raiz, char* palavra, int freq){
    if(raiz == NULL) return;

    if(*raiz == NULL){ // árvore vazia ou nó folha
        struct No2 *novo = (struct No2*)malloc(sizeof(struct No2));
        if(novo == NULL) return; // falha na alocação

        strncpy(novo->palavra, palavra, sizeof(novo->palavra)-1);
        novo->palavra[sizeof(novo->palavra)-1] = '\0';
        novo->freq = freq;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;

        *raiz = novo;
        return;
    }

    // Inserção recursiva
    if(freq < (*raiz)->freq){
        insereFreq(&((*raiz)->esq), palavra, freq);
    }
    else if(freq > (*raiz)->freq){
        insereFreq(&((*raiz)->dir), palavra, freq);
    }
    else { 
        // Frequência igual → ordenar por palavra
        int cmp = strcmp(palavra, (*raiz)->palavra);
        if(cmp < 0){
            insereFreq(&((*raiz)->esq), palavra, freq);
        }
        else if(cmp > 0){
            insereFreq(&((*raiz)->dir), palavra, freq);
        }
        else{
            // Palavra já existe, atualizar frequência
            (*raiz)->freq = freq; 
            return;
        }
    }

    // Atualizar altura
    (*raiz)->alt = maior(altura2((*raiz)->esq), altura2((*raiz)->dir)) + 1;

    int balanco = balanceamento2(*raiz);
    if(balanco > 1){
        if(balanceamento2((*raiz)->esq) >= 0)
            rotacaoLL2(raiz);
        else
            rotacaoLR2(raiz);
    }
    else if(balanco < -1){
        if(balanceamento2((*raiz)->dir) <= 0)
            rotacaoRR2(raiz);
        else
            rotacaoRL2(raiz);
    }
}


void insereOuAtualiza(ArvAVL2 *raiz, char *palavra, int freq) {
    if (raiz == NULL) return;

    struct No2* encontrado = buscaPalavra(*raiz, palavra);

    if (encontrado != NULL) {
        int freq_antiga = encontrado->freq;
        int freq_nova   = freq; 

        // remover o nó antigo
        *raiz = remove_ArvFreq(raiz, freq_antiga, palavra);

        // reinserir com a frequência atualizada
        insereFreq(raiz, palavra, freq_nova);

    } else {
        // se não existir, insere normalmente
        insereFreq(raiz, palavra, freq);
    }
}

void buscaAVLFreq(ArvAVL2* raiz, int freq) {
    if(raiz == NULL || *raiz == NULL) {
        return;
    }

   if((*raiz)->freq == freq) {
        printf("%s (%d)\n", (*raiz)->palavra, (*raiz)->freq);
    }

    buscaAVLFreq(&((*raiz)->esq), freq);
    buscaAVLFreq(&((*raiz)->dir), freq);
}

