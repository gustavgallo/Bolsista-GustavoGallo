#include <stdio.h>
#include <stdlib.h>

void invertvet(int tam, int vet[])
{
    for (int i = 0; i < tam / 2; i++)
    {
        int tmp = vet[i];
        vet[i] = vet[tam - i - 1];
        vet[tam - i - 1] = tmp;
    }
}

void convolution(int *sinal, int tamSinal, int *filtro, int tamFiltro, int *saida)
{

    int tamanhoSaida = tamSinal + tamFiltro - 1;

    for (int i = 0; i < tamanhoSaida; i++)
    {
        saida[i] = 0;
    }

    for (int i = 0; i < tamanhoSaida; i++)
    {
        int elementosFiltro = (i < tamFiltro) ? i + 1 : tamFiltro;

        for (int j = 0; j < elementosFiltro; j++)
        {

            if (i - j >= 0 && i - j < tamSinal)
            {

                saida[i] += filtro[j] * sinal[i - j];
            }
        }
    }
}

int lerArquivo(const char *nomeArquivo, int **vetor)
{
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo: %s\n", nomeArquivo);
        exit(1);
    }

    int tamanho;
    fscanf(arquivo, "%d", &tamanho); // Primeiro número é o tamanho do vetor

    *vetor = malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++)
    {
        fscanf(arquivo, "%d", &(*vetor)[i]);
    }

    fclose(arquivo);
    return tamanho;
}

int main()
{
    int *sinal, *filtro;
    int tamFiltro = lerArquivo("filtro.txt", &filtro);
    int tamSinal = lerArquivo("sinal.txt", &sinal);

    int tamanhoSaida = tamSinal + tamFiltro - 1;
    int saida[tamanhoSaida];

    convolution(sinal, tamSinal, filtro, tamFiltro, saida);

    for (int i = 0; i < tamanhoSaida; i++)
    {
        printf("%d ", saida[i]);
    }
    printf("\n");

    free(sinal);
    free(filtro);

    return 0;
}
