#include <stdlib.h>
#include <stdio.h>

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

int buscar(No *raiz, int valor) {
    if (raiz == NULL) {
        printf("Nao encontramos o %d\n", valor);
        return 0;
    }
    
    if (raiz->valor == valor) {
        printf("Encontramos o %d\n", valor);
        return 1;
    }
    
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    }
    
    if (valor > raiz->valor) {
        return buscar(raiz->direita, valor);
    }
}