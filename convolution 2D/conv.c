#include <stdio.h>
#include <stdlib.h>


void convolucao2D(int entrada1D[], int kernel1D[], int tamEntrada, int tamKernel, int saida[], int tamSaida);
int * lerMatriz2D(const char *nomeArquivo, int *linhas, int *colunas);

int main()
{
int tamEntrada, tamKernel;

    int *entrada1D = lerMatriz2D("entrada.txt", &tamEntrada, &tamEntrada);
    int *kernel1D = lerMatriz2D("kernel.txt", &tamKernel, &tamKernel);

      if (entrada1D == NULL || kernel1D == NULL)
    {
        free(entrada1D);
        free(kernel1D);
        return 1; // Saída em caso de erro
    }

    int tamSaida = tamEntrada - tamKernel + 1; 
    int *saida = (int *)malloc(tamSaida * tamSaida * sizeof(int));
  
        

    convolucao2D(entrada1D, kernel1D, tamEntrada, tamKernel, saida, tamSaida);

    printf("Matriz de saída:\n");
    for (int i = 0; i < tamSaida; i++)
    {
        for (int j = 0; j < tamSaida; j++)
        {
            printf("%d ", saida[i * tamSaida + j]);
        }
        printf("\n");
    }

    free(entrada1D);
    free(kernel1D);
    free(saida);

    return 0;
}

//  feita convolução 2D, utilizando vetores unidimensionais
void convolucao2D(int entrada1D[], int kernel1D[], int colEntrada, int colKernel, int saida[],int tamSaida)
{
    for (int i = 0; i < tamSaida; i++)
    {
        for (int j = 0; j < tamSaida; j++)
        {
            int soma = 0;   
            for (int l = 0; l < colKernel; l++)
            {
                for (int c = 0; c < colKernel; c++)
                {
                    soma += kernel1D[l * colKernel + c] * entrada1D[(i + l) * colEntrada + (j + c)];
                }
            }
            saida[i * tamSaida + j] = soma;
        }
    }
}

// faz a leitura de uma matriz 2D de um arquivo, e cria uma 1D
int * lerMatriz2D(const char *nomeArquivo, int *linhas, int *colunas)
{
    
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo: %s\n", nomeArquivo);
        return NULL;
    }

   // Le as dimensoes da matriz do inicio do arquivo
    fscanf(arquivo, "%d %d", linhas, colunas);

    int *matriz = (int *)malloc((*linhas) * (*colunas) * sizeof(int));

    //aloca os valores na matriz
    for (int i = 0; i < *linhas; i++)
    {
        for (int j = 0; j < *colunas; j++)
        {
            fscanf(arquivo, "%d", &matriz[i * (*colunas) + j]);
        }
    }

    fclose(arquivo);
    return matriz;
}