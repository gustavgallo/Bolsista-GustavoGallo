#include <stdio.h>

#define TAM_ENTRADA 3
#define TAM_KERNEL 2
#define TAM_SAIDA (TAM_ENTRADA - TAM_KERNEL + 1)

void convolucao2D(int entrada[][TAM_ENTRADA], int kernel[][TAM_KERNEL], int tamEntrada, int tamKernel, int saida[][TAM_SAIDA]);

int main()
{
    int entrada[TAM_ENTRADA][TAM_ENTRADA] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}};

    int kernel[TAM_KERNEL][TAM_KERNEL] = {
        {1, 0},
        {0, -1}};

    int saida[TAM_SAIDA][TAM_SAIDA] = {0};

    convolucao2D(entrada, kernel, TAM_ENTRADA, TAM_KERNEL, saida);

    printf("Matriz de saída:\n");
    for (int i = 0; i < TAM_SAIDA; i++)
    {
        for (int j = 0; j < TAM_SAIDA; j++)
        {
            printf("%d ", saida[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// não é necessário colocar o tamanho das linhas, apenas colunas, por conta do compilador
void convolucao2D(int entrada[][TAM_ENTRADA], int kernel[][TAM_KERNEL], int tamEntrada, int tamKernel, int saida[][TAM_SAIDA])
{
    for (int i = 0; i < TAM_SAIDA; i++)
    {
        for (int j = 0; j < TAM_SAIDA; j++)
        {
            int soma = 0;
            for (int k = 0; k < tamKernel; k++)
            {
                for (int l = 0; l < tamKernel; l++)
                {
                    soma += kernel[k][l] * entrada[i + k][j + l];// o que altera é a região que o filtro está "observando"
                }
            }
            saida[i][j] = soma;
        }
    }
}
