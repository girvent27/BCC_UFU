#include "head.h"

int pontuacao_vet(char c)
{
    return (c == ',' || c == '.' || c == '!' || c == '?' || c == ';' || c == ':' ||
            c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' ||
            c == '"' || c == '\'');
}

void removerPontuacao_Vet(char *str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (!pontuacao_vet(str[i]))
        {
            str[j++] = tolower((unsigned char)str[i]); // converte para minúsculo
        }
        i++;
    }
    str[j] = '\0';
}

// ----------------------------
// Lê uma música de arquivo
// ----------------------------
Musicas ler_Musica(const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo)
    {
        perror("Erro ao abrir arquivo");
        Musicas m = {NULL, {"", "", 0}, 0};
        return m;
    }

    Musicas m;
    m.freq = NULL;
    m.qtd = 0;
    m.info.freq = 0;
    int capacidade = 0;
    char buffer[512], palavra[100];

    // primeira linha = nome da música
    if (fgets(buffer, sizeof(buffer), arquivo))
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(m.info.nome, buffer);
    }

    // segunda linha = compositor
    if (fgets(buffer, sizeof(buffer), arquivo))
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(m.info.compositor, buffer);
    }

    // ler palavras
    while (fscanf(arquivo, "%99s", palavra) == 1)
    {
        removerPontuacao_Vet(palavra);
        if (strlen(palavra) < 3)
            continue;

        int encontrada = 0;
        for (int i = 0; i < m.qtd; i++)
        {
            if (strcmp(m.freq[i].palavra, palavra) == 0)
            {
                m.freq[i].freq++;
                if (m.freq[i].freq > m.info.freq)
                    m.info.freq = m.freq[i].freq;
                encontrada = 1;
                break;
            }
        }

        if (!encontrada)
        {
            if (m.qtd >= capacidade)
            {
                capacidade = (capacidade == 0) ? 10 : capacidade * 2;
                m.freq = realloc(m.freq, capacidade * sizeof(Frequencia));
                if (!m.freq)
                {
                    perror("Erro de memória");
                    fclose(arquivo);
                    exit(1);
                }
            }
            strcpy(m.freq[m.qtd].palavra, palavra);
            m.freq[m.qtd].freq = 1;
            if (m.info.freq < 1)
                m.info.freq = 1;
            m.qtd++;
        }
    }

    if (m.qtd > 0)
        m.freq = realloc(m.freq, m.qtd * sizeof(Frequencia));

    fclose(arquivo);
    return m;
}

// ----------------------------
// Ordenação por frequência decrescente
// ----------------------------
void shellSort(Frequencia *vetor, int n)
{
    int h = n / 2;
    while (h > 0)
    {
        for (int i = h; i < n; i++)
        {
            Frequencia temp = vetor[i];
            int j = i;
            while (j >= h && strcmp(vetor[j - h].palavra, temp.palavra) > 0)
            {
                vetor[j] = vetor[j - h];
                j -= h;
            }
            vetor[j] = temp;
        }
        h /= 2;
    }
}

// ----------------------------
// Adiciona música ao vetor dinâmico
// ----------------------------
void adicionarMusica(Musicas **vet, int *qtd, char *nomeArquivo)
{
    Musicas nova = ler_Musica(nomeArquivo);
    if (!nova.freq)
        return;

    shellSort(nova.freq, nova.qtd);

    *vet = (int *)realloc(*vet, (*qtd + 1) * sizeof(Musicas));
    if (!*vet)
    {
        perror("Erro de realocamento memória");
        // exit(1);
    }

    (*vet)[*qtd] = nova;
    (*qtd)++;
}

// ----------------------------
// Função que busca palavra nas músicas
// ----------------------------

int buscaBinaria_vet(Frequencia *vetor, int n, const char *palavra)
{
    int ini = 0, fim = n - 1;
    while (ini <= fim)
    {
        int meio = (ini + fim) / 2;
        int cmp = strcmp(vetor[meio].palavra, palavra);
        if (cmp == 0)
            return meio; // encontrou
        else if (cmp < 0)
            ini = meio + 1;
        else
            fim = meio - 1;
    }
    return -1; // não encontrado
}

void buscarPalavra(Musicas *vet, int qtd, char *palavra)
{
    removerPontuacao_Vet(palavra);

    if (strlen(palavra) < 1)
    {
        printf("Palavra invalida!\n");
        return;
    }

    int maiorFreq = 0;
    int indiceMusica = -1;

    for (int i = 0; i < qtd; i++)
    {
        int pos = buscaBinaria_vet(vet[i].freq, vet[i].qtd, palavra);
        if (pos != -1)
        {
            if (vet[i].freq[pos].freq > maiorFreq)
            {
                maiorFreq = vet[i].freq[pos].freq;
                indiceMusica = i;
            }
        }
    }

    if (indiceMusica != -1)
    {
        printf("Vetor Dinâmico em Busca Binária:\n %s -- %s\nFrequencia: %d\n",
               vet[indiceMusica].info.nome, vet[indiceMusica].info.compositor, maiorFreq);
    }
    else
    {
        printf("A palavra nao encontrada.\n");
    }
}
