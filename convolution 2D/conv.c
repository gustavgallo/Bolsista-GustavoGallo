#include <stdio.h>

#define TAM_ENTRADA 3
#define TAM_KERNEL 2
#define TAM_SAIDA (TAM_ENTRADA - TAM_KERNEL + 1)

void convolucao2D(int entrada1D[], int kernel1D[], int tamEntrada, int tamKernel, int saida[]);

int main()
{
    int entrada[TAM_ENTRADA][TAM_ENTRADA] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}};

    int kernel[TAM_KERNEL][TAM_KERNEL] = {
        {1, 0},
        {0, -1}};

//criei as versóes 1D das matrizes 
    int entrada1D[TAM_ENTRADA * TAM_ENTRADA];
    int kernel1D[TAM_KERNEL * TAM_KERNEL];

// transferi a 2D da entrada para 1D
    for(int i = 0; i < TAM_ENTRADA; i++){
        for(int j = 0 ; j < TAM_ENTRADA; j++){
            entrada1D[i * TAM_ENTRADA + j] = entrada[i][j];

        }
    }
// transferi a 2D do kernel para 1D
    for(int i = 0; i < TAM_KERNEL; i++){
        for(int j = 0 ; j < TAM_KERNEL; j++){
            kernel1D[i * TAM_KERNEL + j] = kernel[i][j];

        }
    }
    

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
