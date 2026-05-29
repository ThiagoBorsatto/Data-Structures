#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor) {
    No* noDaArvore = (No *)malloc(sizeof(No));

    noDaArvore->valor = valor;
    noDaArvore->esquerda = NULL;
    noDaArvore->direita = NULL;

    return noDaArvore;
}

No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

void emOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    emOrdem(raiz->esquerda);

    printf("Valor: %d\n", raiz->valor);

    emOrdem(raiz->direita);
}

int buscarArvoreBinaria(No *raiz, int valor) {
    if (raiz == NULL) {
        printf("Nao encontramos o %d\n", valor);
        return 0;
    }
    
    if (raiz->valor == valor) {
        printf("Encontramos o %d\n", valor);
        return 1;
    }
    
    if (valor < raiz->valor) {
        return buscarArvoreBinaria(raiz->esquerda, valor);
    }
    
    if (valor > raiz->valor) {
        return buscarArvoreBinaria(raiz->direita, valor);
    }
}

int buscarSequencial(int vetorParaBusca[], int tamanhoDoVetor, int valorParaEncontrar) {
    for (int i = 0; i < tamanhoDoVetor; i++) {
        if (valorParaEncontrar == i) {
            printf("Encontramos o numero: %d\n", valorParaEncontrar);
            return 1;
        }
    }
}

int buscarBinaria() {
    return 1;
}

int main() {
    No* arvoreParaBusca = NULL;

    int vetorDesordenado[100000];
    int vetorOrdenado[100000];
    int tamanhoDoVetor = sizeof(vetorDesordenado) / sizeof(vetorDesordenado[0]);
    
    for (int i = 0; i < 100000; i++) {
        int numerosAleatorios = rand() % 100000;
        
        arvoreParaBusca = inserir(arvoreParaBusca, numerosAleatorios);
        vetorDesordenado[i] = numerosAleatorios;
        vetorOrdenado[i] = i;
    }

    printf("--- Busca em Arvore Binaria ---\n");
    
    clock_t inicio = clock();
    buscarArvoreBinaria(arvoreParaBusca, 99498);
    clock_t fim = clock();
    double tempo_decorrido = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    printf("Tempo de execucao: %.4f segundos\n", tempo_decorrido);
    printf("\n");


    printf("--- Busca Sequencial ---\n");
    int valorParaEncontrar = 55555;
    
    inicio = clock();
    buscarSequencial(vetorDesordenado, tamanhoDoVetor, valorParaEncontrar);
    fim = clock();
    tempo_decorrido = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    printf("Tempo de execucao: %.4f segundos\n", tempo_decorrido);
    printf("\n");

    // emOrdem(arvoreParaBusca);

    return 0;
}