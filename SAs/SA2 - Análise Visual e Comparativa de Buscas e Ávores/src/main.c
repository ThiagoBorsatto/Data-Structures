#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "buscas.h"
#include "arvore.h"

void executarExperimento(int tamanho, int dadosOrdenados) {
    No *raiz = NULL;
    
    printf("\n=== Experimento: %d elementos | Dados %s ===\n", tamanho, dadosOrdenados ? "Ordenados" : "Embaralhados");

    int *vetor = (int*)malloc(tamanho * sizeof(int));

    if (!vetor) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i + 1;
    }

    if (!dadosOrdenados) {
        srand(time(NULL));
        embaralharVetor(vetor, tamanho);
    }

    printf("Inserindo dados na arvore (aguarde...)...\n");
    
    for (int i = 0; i < tamanho; i++) {
        raiz = inserirNaArvore(raiz, vetor[i]);
    }

    if (tamanho <= 10000 || !dadosOrdenados) {
        printf("Altura da arvore: %d\n", calcularAltura(raiz));
    } else {
        printf("Altura da arvore: [Omitida para evitar Stack Overflow em O(N)]\n");
    }

    int valoresParaBuscar[] = {
        vetor[0],                     
        vetor[tamanho / 2],           
        vetor[tamanho - 1],           
        tamanho + 100                 
    };

    if (!dadosOrdenados) {
        for (int i = 0; i < tamanho; i++) vetor[i] = i + 1;
    }

    long long comparacoes;
    clock_t inicio, fim;
    double tempo;

    for (int i = 0; i < 4; i++) {
        int valor = valoresParaBuscar[i];
        printf("\nBuscando valor: %d\n", valor);

        inicio = clock();
        buscaSequencial(vetor, tamanho, valor, &comparacoes);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("  Seq   -> Comp: %lld | Tempo: %f s\n", comparacoes, tempo);

        inicio = clock();
        buscaBinaria(vetor, tamanho, valor, &comparacoes);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("  Bin   -> Comp: %lld | Tempo: %f s\n", comparacoes, tempo);

        inicio = clock();
        buscarNaArvore(raiz, valor, &comparacoes);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("  Arvore-> Comp: %lld | Tempo: %f s\n", comparacoes, tempo);
    }

    liberarArvore(raiz);
    free(vetor);
}

int main() {
    int tamanhos[] = {1000, 10000}; 

    for (int i = 0; i < 2; i++) {
        executarExperimento(tamanhos[i], 1); 
        executarExperimento(tamanhos[i], 0); 
    }

    return 0;
}