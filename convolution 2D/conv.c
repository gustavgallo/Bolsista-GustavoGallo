#include <stdio.h>
#include <stdlib.h>

#define TAM_ENTRADA 3
#define TAM_KERNEL 2


int main()
{
   
int entrada[TAM_ENTRADA][TAM_ENTRADA] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};

int kernel[TAM_KERNEL][TAM_KERNEL] ={
    {1, 0},
    {0,-1},
};

int tamSaida = TAM_ENTRADA - TAM_KERNEL + 1;
int saida[tamSaida][tamSaida];

  for (int i = 0; i < tamSaida; i++) {
        for (int j = 0; j < tamSaida; j++) {
            saida[i][j] = 0;
        }
    }

       // Exibir as matrizes para verificar
    printf("Matriz de Entrada:\n");
    for (int i = 0; i < TAM_ENTRADA; i++) {
        for (int j = 0; j < TAM_ENTRADA; j++) {
            printf("%d ", entrada[i][j]);
        }
        printf("\n");
    }

    printf("\nFiltro:\n");
    for (int i = 0; i < TAM_KERNEL; i++) {
        for (int j = 0; j < TAM_KERNEL; j++) {
            printf("%d ", kernel[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz de Saida (inicializada com zeros):\n");
    for (int i = 0; i < tamSaida; i++) {
        for (int j = 0; j < tamSaida; j++) {
            printf("%d ", saida[i][j]);
        }
        printf("\n");
    }




} 