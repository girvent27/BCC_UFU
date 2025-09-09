#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// Alunos: Ana Luiza Moreira Silva 12411BCC053, Jean Luc girvent Deu 12411BCC101

typedef struct funcionario
{
    char nome[100];
    char naturalidade[100];
    int idade;
    float salario;
} Funcionario;

void OrdemSalarioBolha(Funcionario vet[], int n)
{
    int troca;
    Funcionario temp;
    int i, j;
    for (i = 0; i < n; i++)
    {
        troca = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (vet[j].salario > vet[j + 1].salario)
            {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                troca = 1;
            }
        }
        if (troca == 0)
            break;
    }
}

void OrdemIdadeBolha(Funcionario vet[], int n)
{
    int troca;
    Funcionario temp;
    int i, j;
    for (i = 0; i < n; i++)
    {
        troca = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (vet[j].idade < vet[j + 1].idade)
            {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                troca = 1;
            }
        }
        if (troca == 0)
            break;
    }
}

void OrdemNomeBolha(Funcionario vet[], int n)
{
    int troca;
    Funcionario temp;
    int i, j;
    for (i = 0; i < n; i++)
    {
        troca = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(vet[j].nome, vet[j + 1].nome) > 0)
            {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                troca = 1;
            }
        }
        if (troca == 0)
            break;
    }
}

void OrdemSalarioSelection(Funcionario vet[], int n)
{
    int menor;
    Funcionario temp;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < n; j++)
        {
            if (vet[j].salario < vet[menor].salario)
                menor = j;
        }
        if (vet[menor].salario < vet[i].salario)
        {
            temp = vet[i];
            vet[i] = vet[menor];
            vet[menor] = temp;
        }
    }
}

void OrdemIdadeSelection(Funcionario vet[], int n)
{
    int maior;
    Funcionario temp;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        maior = i;
        for (j = i + 1; j < n; j++)
        {
            if (vet[j].idade > vet[maior].idade)
                maior = j;
        }
        if (vet[maior].idade > vet[i].idade)
        {
            temp = vet[i];
            vet[i] = vet[maior];
            vet[maior] = temp;
        }
    }
}

void OrdemNomeSelection(Funcionario vet[], int n)
{
    int menor;
    Funcionario temp;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(vet[j].nome, vet[menor].nome) < 0)
                menor = j;
        }
        if (strcmp(vet[menor].nome, vet[i].nome) < 0)
        {
            temp = vet[i];
            vet[i] = vet[menor];
            vet[menor] = temp;
        }
    }
}

Funcionario criaFunciTeste()
{
    Funcionario funcionario;
    char nomes[10][100] = {"Luana Camara", "Ana Luiza", "Matheus Martins", "Vinicius Morais", "Lucas Rodrigues", "Lucas Nascimento", "Davi Schutz", "Brunno Oliveira", "Philipe Souza", "Jean Luc"};

    funcionario.idade = rand() % 100;
    funcionario.salario = ((float)rand() / (float)(RAND_MAX)) * 10000;
    strcpy(funcionario.naturalidade, "Brasileiro");
    strcpy(funcionario.nome, nomes[rand() % 10]);

    return funcionario;
}

void criaFunciManual(Funcionario vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        setbuf(stdin, NULL);
        printf("\n| Funcionario %d: \n", i + 1);
        printf("| Informe o nome do funcionario: ");
        fgets(vet[i].nome, sizeof(vet[i].nome), stdin);
        printf("| Informe a naturalidade do funcionario: ");
        fgets(vet[i].naturalidade, sizeof(vet[i].naturalidade), stdin);
        printf("| Informe a idade do funcionario: ");
        scanf("%d", &vet[i].idade);
        printf("| Informe o salario do funcioanario: ");
        scanf("%f", &vet[i].salario);
        printf("===========================================\n");
    }
}

void listarFuncionarios(Funcionario vet[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n| Funcionario %d: \n", i + 1);
        printf("|   Nome: %s\n|   Naturalidade: \"%s\"\n|   Idade: %d\n|   Salario: R$ %.2f\n=============================\n", vet[i].nome, vet[i].naturalidade, vet[i].idade, vet[i].salario);
    }
}

int main()
{
    const int n = 10;

    Funcionario vet[n];
    int valor, i, opcao;
    srand(time(NULL));

    do
    {
        printf("\nComo deseja usar o codigo?\n1 | Inserir Manualmente\n2 | Criar lista teste\nOpcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            criaFunciManual(vet, n);
            break;

        case 2:
            for (i = 0; i < n; i++)
            {
                vet[i] = criaFunciTeste();
            }
            break;
        default:
            printf("Opcao invalida!!\n");
            break;
        }
    } while (opcao > 2 || opcao < 1);
    listarFuncionarios(vet, n);
    opcao = 0;

    do
    {
        printf("\n# | Menu \n");
        printf("1 | Ordenacao por Bubble Sort digite 1 \n");
        printf("2 | Ordenacao por Selection Sort digite 2 \n");
        printf("3 | Sair \nEcolha: ");
        scanf("%d", &valor);

        switch (valor)
        {
        case 1:
        {
            do
            {
                printf("\n\n# | Menu Bubble Sort \n");
                printf("1 | Em ordem crescente de salario\n");
                printf("2 | Em ordem decrescente de idade\n");
                printf("3 | Em ordem alfabetica\n");
                printf("4 | Voltar \nEcolha: ");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    OrdemSalarioBolha(vet, n);
                    listarFuncionarios(vet, n);
                    break;
                case 2:
                    OrdemNomeBolha(vet, n);
                    listarFuncionarios(vet, n);

                    break;
                case 3:
                    OrdemNomeBolha(vet, n);
                    listarFuncionarios(vet, n);

                    break;
                case 4:
                    printf("Voltando...\n");
                    break;
                default:
                {
                    printf("Opcao invalida\n");
                    break;
                }
                }
            } while (opcao != 4);
        }
        case 2:
            do
            {
                printf("\n\n# | Menu Selection Sort\n");
                printf("1 | Em ordem crescente de salario\n");
                printf("2 | Em ordem decrescente de idade\n");
                printf("3 | Em ordem alfabetica\n");
                printf("4 | Voltar \nEcolha: ");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    OrdemSalarioSelection(vet, n);
                    listarFuncionarios(vet, n);

                    break;
                case 2:
                    OrdemIdadeSelection(vet, n);
                    listarFuncionarios(vet, n);

                    break;
                case 3:
                    OrdemNomeSelection(vet, n);
                    listarFuncionarios(vet, n);

                    break;
                case 4:
                    printf("Voltando...\n");
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }
            } while (opcao != 4);
        case 3:
            printf("Saindo...\n");
            break;
        default:
        {
            printf("Opcao invalida\n");
            break;
        }
        }
    } while (valor != 3);

    return 0;
}
