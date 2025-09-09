#include "head.h"
int main()
{
    int op, qtd = 0;
    struct No *resul;
    struct No3 *resul3;
    char str1[100], palavra[100];
    int freq;
    ArvAVL *raiz = cria_arv();
    ArvAVL2 *raiz2 = cria_arv2();
    ArvBin *raiz3 = cria_arvBin();
    Musicas *vet_musicas = NULL;
    do
    {
        printf("Informe a opcao desejada:\n");
        printf("1 para adicionar novo arquivo\n");
        printf("2 para busca por palavra\n");
        printf("3 para busca por frequencia\n");
        printf("4 para sair\n");
        scanf("%d", &op);
        getchar(); // Limpar buffer

        switch (op)
        {
        // Armazenar nos três modos
        case 1:
            setbuf(stdin, NULL);
            printf("Informe o arquivo:");
            fgets(str1, 100, stdin);
            str1[strcspn(str1, "\n")] = '\0';
            strcat(str1, ".txt");

            // Leitura por AVL
            leitura_arquivo(raiz, raiz2, str1);

            // Leitura por Arv Bin
            leitura_ArquivoBin(raiz3, str1);

            // Leitura por Vetor dinamico
            adicionarMusica(&vet_musicas, &qtd, str1);

            break;

        // Busca nos três modos
        case 2:
            setbuf(stdin, NULL);
            printf("Informe a palavra que deseja buscar:");
            fgets(palavra, 100, stdin);
            palavra[strcspn(palavra, "\n")] = '\0';

            // Busca Avl
            resul = buscaAVL(raiz, palavra);
            if (resul == NULL)
            {
                printf("Palavra não encontrada\n");
            }
            else
            {
                printf("\n");
                printf("Arvore AVL:\n");
                printf("%s -- ", resul->info.nome);
                printf("%s -- ", resul->info.compositor);
                printf("%s ... \n ", resul->info.estrofe);
                printf("frequencia: %d \n ", resul->info.freq);
                printf(" \n ");
            }

            // busca Arv Bin
            resul3 = buscaBin(raiz3, palavra);
            if (resul3 == NULL)
            {
                printf("Palavra não encontrada\n");
            }
            else
            {
                printf("\n");
                printf("Arvore Binaria:\n");
                printf("%s -- ", resul3->info.nome);
                printf("%s -- ", resul3->info.compositor);
                printf("%s ... \n ", resul3->info.estrofe);
                printf("frequencia: %d \n ", resul3->info.freq);
                printf(" \n ");
            }

            // buscarPalavra(vet_musicas, qtd, palavra);
            break;

        case 3:
            printf("Informe a frequencia que deseja encontrar:");
            scanf("%d", &freq);
            getchar(); // Limpar buffer
            buscaAVLFreq(raiz2, freq);
            break;

        case 4:
            printf("Saindo...");
            break;

        default:
            printf("Opcao invalida");
            break;
        }
    } while (op != 4);

    libera_Arv(raiz);
    libera_Arv2(raiz2);
    for (int i = 0; i < qtd; i++)
        free(vet_musicas[i].freq);
    free(vet_musicas);

    return 0;
}