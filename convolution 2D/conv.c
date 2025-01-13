#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convolucao2D(int entrada1D[], int kernel1D[], int tamEntrada, int tamKernel,int tamCamadas, int saida[], int tamSaida);
int *lerMatriz2D(const char *nomeArquivo, int *linhas, int *colunas);

int main()
{
    int tamEntrada, tamEntrada2, tamEntrada3, tamKernel, tamKernel2, tamKernel3;
    int tamCamadas = 3;

    int *entrada1 = lerMatriz2D("entrada1.txt", &tamEntrada, &tamEntrada);
    int *entrada2 = lerMatriz2D("entrada2.txt", &tamEntrada2, &tamEntrada2);
    int *entrada3 = lerMatriz2D("entrada3.txt", &tamEntrada3, &tamEntrada3);
    int *kernel1 = lerMatriz2D("kernel1.txt", &tamKernel, &tamKernel);
    int *kernel2 = lerMatriz2D("kernel2.txt", &tamKernel2, &tamKernel2);
    int *kernel3 = lerMatriz2D("kernel3.txt", &tamKernel3, &tamKernel3);


    if (entrada1 == NULL || entrada2 == NULL || entrada3 == NULL || kernel1 == NULL || kernel2 == NULL || kernel3 == NULL)
    {
        free(entrada1);
        free(entrada2);
        free(entrada3);
        free(kernel1);
        free(kernel2);
        free(kernel3);
        return 1;
    }
   
    if (tamEntrada != tamEntrada2 || tamEntrada != tamEntrada3)
    {
        printf("As camadas de entrada devem ter o mesmo tamanho.\n");
        free(entrada1);
        free(entrada2);
        free(entrada3);
        free(kernel1);
        free(kernel2);
        free(kernel3);

        return 1;
    }

    // Combina as 3 camadas em um unico vetor
    int *entradaCombinada = (int *)malloc(tamCamadas * tamEntrada * tamEntrada * sizeof(int));
    for (int i = 0; i < tamEntrada * tamEntrada; i++)
    {
        entradaCombinada[i] = entrada1[i];
        entradaCombinada[i + tamEntrada * tamEntrada] = entrada2[i];
        entradaCombinada[i + 2 * tamEntrada * tamEntrada] = entrada3[i];
    }

    // Combina os 3 kernels em um unico vetor
    int *kernel1D = (int *)malloc(tamCamadas * tamKernel * tamKernel * sizeof(int));
    for (int i = 0; i< tamKernel * tamKernel; i++){
        kernel1D[i] = kernel1[i];
        kernel1D[i + tamKernel * tamKernel] = kernel2[i];
        kernel1D[i + 2 * tamKernel * tamKernel] = kernel3[i];   

    }


    int tamSaida = tamEntrada - tamKernel + 1;
    int *saida = (int *)malloc(tamSaida * tamSaida * sizeof(int));
    //zera todos valores
    memset(saida, 0, tamSaida * tamSaida * sizeof(int));

    convolucao2D(entradaCombinada, kernel1D, tamEntrada, tamKernel,tamCamadas, saida, tamSaida);

    printf("Matriz de saída:\n");
    for (int i = 0; i < tamSaida; i++)
    {
        for (int j = 0; j < tamSaida; j++)
        {
            printf("%d ", saida[i * tamSaida + j]);
        }
        printf("\n");
    }

    free(entrada1);
    free(entrada2);
    free(entrada3);
    free(entradaCombinada);
    free(kernel1); 
    free(kernel2);
    free(kernel3);
    free(kernel1D);
    free(saida);

    return 0;
}

//  feita convolução 2D, utilizando vetores unidimensionais
void convolucao2D(int entrada1D[], int kernel1D[], int colEntrada, int colKernel, int tamCamadas, int saida[], int tamSaida)
{
    for (int i = 0; i < tamSaida; i++)
    {
        for (int j = 0; j < tamSaida; j++)
        {
            int soma = 0;

            for (int camada = 0; camada < tamCamadas; camada++)
            {
                for(int kernels = 0; kernels < tamCamadas; kernels++){

                for (int l = 0; l < colKernel; l++)
                {
                    for (int c = 0; c < colKernel; c++)
                    {
                        int indexEntrada = camada * colEntrada * colEntrada + (i + l) * colEntrada + (j + c);
                        int indexKernel = kernels * colKernel * colKernel + l * colKernel + c;
                        
                          soma += kernel1D[indexKernel] * entrada1D[indexEntrada];
                    }
                }
                }
            }
            saida[i * tamSaida + j] = soma;
        }
    }
}

// faz a leitura de uma matriz 2D de um arquivo, e cria uma 1D
int *lerMatriz2D(const char *nomeArquivo, int *linhas, int *colunas)
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

    // aloca os valores na matriz
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