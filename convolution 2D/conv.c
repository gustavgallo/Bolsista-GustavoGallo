#include <stdio.h>

#define TAM_ENTRADA 3
#define TAM_KERNEL 2
#define TAM_SAIDA (TAM_ENTRADA - TAM_KERNEL + 1)

void convolucao2D(int entrada1D[], int kernel1D[], int tamEntrada, int tamKernel, int saida[]);
void lerMatriz2D(const char *nomeArquivo, int *matriz, int linhas, int colunas);

int main()
{

    int entrada1D[TAM_ENTRADA * TAM_ENTRADA];
    int kernel1D[TAM_KERNEL * TAM_KERNEL];

    lerMatriz2D("entrada.txt", entrada1D, TAM_ENTRADA, TAM_ENTRADA);
    lerMatriz2D("kernel.txt", kernel1D, TAM_KERNEL, TAM_KERNEL);

    int saida[TAM_SAIDA * TAM_SAIDA] = {0};

    convolucao2D(entrada1D, kernel1D, TAM_ENTRADA, TAM_KERNEL, saida);

    printf("Matriz de saída:\n");
    for (int i = 0; i < TAM_SAIDA; i++)
    {
        for (int j = 0; j < TAM_SAIDA; j++)
        {
            printf("%d ", saida[i * TAM_SAIDA + j]);
        }
        printf("\n");
    }

    return 0;
}

//  feita convolução 2D, utilizando vetores unidimensionais
void convolucao2D(int entrada1D[], int kernel1D[], int colEntrada, int colKernel, int saida[])
{
    for (int i = 0; i < TAM_SAIDA; i++)
    {
        for (int j = 0; j < TAM_SAIDA; j++)
        {
            int soma = 0;
            for (int l = 0; l < TAM_KERNEL; l++)
            {
                for (int c = 0; c < TAM_KERNEL; c++)
                {
                    soma += kernel1D[l * colKernel + c] * entrada1D[(i + l) * colEntrada + (j + c)];
                }
            }
            saida[i * TAM_SAIDA + j] = soma;
        }
    }
}

// faz a leitura de uma matriz 2D de um arquivo, e cria uma 1D
void lerMatriz2D(const char *nomeArquivo, int *matriz, int linhas, int colunas)
{
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo: %s\n", nomeArquivo);
        return;
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            fscanf(arquivo, "%d", &matriz[i * colunas + j]);
        }
    }

    fclose(arquivo);
}