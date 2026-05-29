#include "buscas.h"
#include <stdlib.h>

int buscaSequencial(int *vetor, int tamanho, int valor, long long *comparacoes) {
    *comparacoes = 0;
    for (int i = 0; i < tamanho; i++) {
        (*comparacoes)++;
        if (vetor[i] == valor) {
            return i; 
        }
    }
    return -1; 
}

int buscaBinaria(int *vetor, int tamanho, int valor, long long *comparacoes) {
    int inicio = 0;
    int fim = tamanho - 1;
    *comparacoes = 0;

    while (inicio <= fim) {
        (*comparacoes)++;
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == valor) return meio;
        
        (*comparacoes)++;
        if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

void embaralharVetor(int *vetor, int tamanho) {
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}