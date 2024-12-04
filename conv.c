#include <stdio.h>

void invertvet(int tam, int vet[]) {
    for (int i = 0; i < tam / 2; i++) {
        int tmp = vet[i];
        vet[i] = vet[tam - i - 1];
        vet[tam - i - 1] = tmp;
    }
}

int main() {
    int sinal[] = {1, 2, 3, 4, 5};
    int filtro[] = {-1, 0, 1};
    int tamFiltro = sizeof(filtro) / sizeof(filtro[0]);
    int tamSinal = sizeof(sinal) / sizeof(sinal[0]);


    int tamanhoSaida = tamSinal + tamFiltro - 1;
    int saida[tamanhoSaida];


    for (int i = 0; i < tamanhoSaida; i++) {
        saida[i] = 0;
    }


    for (int i = 0; i < tamanhoSaida; i++) {
        int elementosFiltro = (i < tamFiltro) ? i + 1 : tamFiltro; 
        for (int j = 0; j < elementosFiltro; j++) {
            if (i - j >= 0 && i - j < tamSinal) {
                saida[i] += filtro[j] * sinal[i - j];
            }
        }
    }

   
    for (int i = 0; i < tamanhoSaida; i++) {
        printf("%d ", saida[i]);
    }
    printf("\n");

    return 0;
}
