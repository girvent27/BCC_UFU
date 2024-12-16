#include <stdio.h>
#include <string.h>

int main()
{

    FILE *fp;
    char s[50], c;
    /* Lê um nome para o arquivo a ser aberto:
     */
    printf("\n\n Digite o caminho completo inclusive o nome para o arquivo:\n");
    gets(s);
    /* Caso ocorra algum erro na abertura do
    arquivo o programa será finalizado */
    if (!(fp = fopen("teste.txt", "w")))
    {
        printf("Erro! Impossível abrir o arquivo!\n");
        exit(1);
    }
    /* Se não houve erro, escreve no arquivo...*/
    fprintf(fp, "Este e um arquivo chamado:\n%s\n", s);
    fclose(fp); /* fecha o arquivo */
    /* abre novamente para a leitura */
    fp = fopen(s, "r");
    while (!feof(fp))
    {
        fscanf(fp, "%c", &c);
        printf("%c", c);
    }
    fclose(fp);
    return (0);
}