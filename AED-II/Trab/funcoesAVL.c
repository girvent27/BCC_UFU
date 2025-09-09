#include "head.h"
// Criação da árvore
ArvAVL *cria_arv()
{
    ArvAVL *raiz = (ArvAVL *)malloc(sizeof(ArvAVL));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

// Calculo da altura de um nó
int altura(struct No *no)
{
    if (no == NULL)
        return -1;
    else
        return no->alt;
}

// Liberar cada nó
void libera_No(struct No *no)
{
    if (no == NULL)
        return;
    libera_No(no->esq);
    libera_No(no->dir);
    free(no);
    no = NULL;
}

// Liberar a arvore
void libera_Arv(ArvAVL *raiz)
{
    if (raiz == NULL)
        return;
    libera_No(*raiz); // liberar cada nó
    free(raiz);       // liberar a raiz
}

// Calcular o balanceamento de um nó
int balanceamento(struct No *no)
{
    if (no == NULL)
        return 0;
    return (altura(no->esq) - altura(no->dir));
}

// Calcula o maior valor
int maior(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

// Rotação Simples a direita
void rotacaoLL(ArvAVL *raiz)
{
    struct No *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(altura((*raiz)->esq), altura((*raiz)->dir)) + 1;
    no->alt = maior(altura(no->esq), (*raiz)->alt) + 1;
    *raiz = no;
}

// Rotacao Simples a esquerda
void rotacaoRR(ArvAVL *raiz)
{
    struct No *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(altura((*raiz)->esq), altura((*raiz)->dir)) + 1;
    no->alt = maior(altura(no->dir), (*raiz)->alt) + 1;
    (*raiz) = no;
}

// Rotação Dupla (Simples a esquerda, depois simples a direita)
void rotacaoLR(ArvAVL *raiz)
{
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

// Rotação Dupla (Simples a direita, depois simples a esquerda)
void rotacaoRL(ArvAVL *raiz)
{
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}

// Insercao na arvore de palavras
int insere(ArvAVL *raiz, ArvAVL2 *raiz2, struct musica valor, char *str)
{
    if (raiz == NULL)
        return 0;

    if (*raiz == NULL)
    {
        struct No *novo = (struct No *)malloc(sizeof(struct No));
        if (novo == NULL)
            return 0;

        strcpy(novo->palavra, str);
        strcpy(novo->info.nome, valor.nome);
        strcpy(novo->info.compositor, valor.compositor);
        strcpy(novo->info.estrofe, valor.estrofe);
        novo->info.freq = valor.freq;
        novo->freq = valor.freq;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;

        *raiz = novo;
        insereOuAtualiza(raiz2, str, valor.freq);
        return 1;
    }

    struct No *atual = *raiz;
    int cmp = strcmp(str, atual->palavra);
    int resultado = 0;

    if (cmp < 0)
    {
        resultado = insere(&(atual->esq), raiz2, valor, str);
        if (resultado == 1)
        {
            if (balanceamento(atual) >= 2)
            {
                if (strcmp(str, atual->esq->palavra) < 0)
                    rotacaoLL(raiz);
                else
                    rotacaoLR(raiz);
            }
        }
    }
    else if (cmp > 0)
    {
        resultado = insere(&(atual->dir), raiz2, valor, str);
        if (resultado == 1)
        {
            if (balanceamento(atual) <= -2)
            {
                if (strcmp(str, atual->dir->palavra) > 0)
                    rotacaoRR(raiz);
                else
                    rotacaoRL(raiz);
            }
        }
    }
    else
    {
        // Palavra já existe
        if (valor.freq > atual->info.freq)
        {
            // Atualizar dados
            strcpy(atual->info.nome, valor.nome);
            strcpy(atual->info.compositor, valor.compositor);
            strcpy(atual->info.estrofe, valor.estrofe);
            atual->info.freq = valor.freq;
            atual->freq += valor.freq;
            insereOuAtualiza(raiz2, str, atual->freq);
        }

        return 0;
    }

    atual->alt = maior(altura(atual->esq), altura(atual->dir)) + 1;
    return resultado;
}

// Busca na arvore por palavra
struct No *buscaAVL(ArvAVL *raiz, char *palavra)
{
    if (raiz == NULL || *raiz == NULL)
    {
        return NULL;
    }

    char palavra_limpa[100];
    strcpy(palavra_limpa, palavra);
    size_t len = strlen(palavra_limpa);
    if (len > 0 && palavra_limpa[len - 1] == '\n')
    {
        palavra_limpa[len - 1] = '\0';
    }

    int cmp = strcmp(palavra_limpa, (*raiz)->palavra);
    if (cmp == 0)
    {
        return (*raiz);
    }
    else if (cmp < 0)
    {
        return buscaAVL(&((*raiz)->esq), palavra_limpa);
    }
    else
    {
        return buscaAVL(&((*raiz)->dir), palavra_limpa);
    }
}

int pontuacao(char c)
{
    return (c == ',' || c == '.' || c == '!' || c == '?' || c == ';' || c == ':' ||
            c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' ||
            c == '"' || c == '\'');
}

void removerPontuacao(char *str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (!pontuacao(str[i]))
        {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

void salvarPalavra(ArvAVL *raiz, ArvAVL2 *raiz2, char *str, char *nomeArq)
{
    struct musica musica;
    int resultado;
    char nome[100], compositor[100], linha[256], palavra[100];
    musica.freq = 0; // frequência na música

    FILE *arq = fopen(nomeArq, "r");
    if (arq == NULL)
        return;

    // Ler nome e compositor (duas primeiras linhas)
    if (!fgets(nome, sizeof(nome), arq) || !fgets(compositor, sizeof(compositor), arq))
    {
        fclose(arq);
        return;
    }

    // Remover newlines
    nome[strcspn(nome, "\n")] = '\0';
    compositor[strcspn(compositor, "\n")] = '\0';

    // Limpar palavra a ser inserida
    char str_limpa[100];
    strncpy(str_limpa, str, sizeof(str_limpa) - 1);
    str_limpa[sizeof(str_limpa) - 1] = '\0';
    for (int i = 0; str_limpa[i]; i++)
        str_limpa[i] = tolower(str_limpa[i]);
    removerPontuacao(str_limpa);

    if (strlen(str_limpa) < 3)
    {
        fclose(arq);
        return;
    }

    // Contar frequência da palavra na música
    rewind(arq);
    fgets(linha, sizeof(linha), arq); // pular duas primeiras linhas
    fgets(linha, sizeof(linha), arq);

    while (fscanf(arq, "%99s", palavra) == 1)
    {
        for (int i = 0; palavra[i]; i++)
            palavra[i] = tolower(palavra[i]);
        removerPontuacao(palavra);

        if (strcmp(str_limpa, palavra) == 0)
            musica.freq++;
    }

    // Armazenar estrofe onde a palavra aparece
    rewind(arq);
    fgets(linha, sizeof(linha), arq); // pular duas primeiras linhas
    fgets(linha, sizeof(linha), arq);

    musica.estrofe[0] = '\0';
    while (fgets(linha, sizeof(linha), arq))
    {
        char linha_limpa[256];
        strncpy(linha_limpa, linha, sizeof(linha_limpa) - 1);
        linha_limpa[sizeof(linha_limpa) - 1] = '\0';
        for (int i = 0; linha_limpa[i]; i++)
            linha_limpa[i] = tolower(linha_limpa[i]);
        removerPontuacao(linha_limpa);

        if (strstr(linha_limpa, str_limpa) != NULL)
        {
            strncpy(musica.estrofe, linha, sizeof(musica.estrofe) - 1);
            musica.estrofe[sizeof(musica.estrofe) - 1] = '\0';
            break;
        }
    }

    // Copiar nome e compositor
    strncpy(musica.nome, nome, sizeof(musica.nome) - 1);
    musica.nome[sizeof(musica.nome) - 1] = '\0';
    strncpy(musica.compositor, compositor, sizeof(musica.compositor) - 1);
    musica.compositor[sizeof(musica.compositor) - 1] = '\0';

    // Inserir na árvore principal
    resultado = insere(raiz, raiz2, musica, str_limpa);
    if (resultado == 1)
    {
        printf("");
    }
    else
    {
        printf("");
    }

    fclose(arq);
}

void leitura_arquivo(ArvAVL *raiz, ArvAVL2 *raiz2, char *str1)
{
    printf("Entrando na leitura de arquivo");
    char palavra[100];

    FILE *arquivo = fopen(str1, "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Pular as duas primeiras linhas (nome e compositor)
    fgets(palavra, 100, arquivo);
    fgets(palavra, 100, arquivo);

    while (fscanf(arquivo, "%99s", palavra) == 1)
    {
        if (strlen(palavra) >= 3 && buscaAVL(raiz, palavra) == NULL)
        {
            salvarPalavra(raiz, raiz2, palavra, str1);
        }
    }

    fclose(arquivo);
}
