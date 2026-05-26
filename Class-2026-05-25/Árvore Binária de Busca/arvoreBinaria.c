#include <stdlib.h>
#include <stdio.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int valor) {
    No* nodo = (No*)malloc(sizeof(No));
    if (nodo != NULL) {
        nodo->valor = valor;
        nodo->esquerda = NULL;
        nodo->direita = NULL;
    }

    printf("No criado: %d\n", valor);
    return nodo;
}

No* inserir(No* raiz, int valor) {
    printf("Teste para Inserir do valor %d\n", valor);

    if (raiz == NULL) { 
        raiz = criarNo(valor);
        printf("Teste Raiz == NULL %d\n", raiz->valor);
        return raiz;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
        printf("Teste Raiz Esquerda %d\n", raiz->valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
        printf("Teste Raiz Direita %d\n", raiz->valor);
    }
    return raiz;
}

No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;
    if (raiz->valor > valor)
        return buscar(raiz->esquerda, valor);
    return buscar(raiz->direita, valor);
}

No* encontrarMinimo(No* encontrarMenorValor) {
    No* atual = encontrarMenorValor;

    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }

    return atual;
}

No* remover(No* raiz, int valor) {
    if (raiz == NULL) return NULL;

    if (valor < raiz->valor)
        raiz->esquerda = remover(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover(raiz->direita, valor);
    else {
        if (raiz->esquerda == NULL) return raiz->direita;
        if (raiz->direita == NULL) return raiz->esquerda;

        No* succ = encontrarMinimo(raiz->direita);
        raiz->valor = succ->valor;
        raiz->direita = remover(raiz->direita, succ->valor);
    }
    return raiz;
}

int main() {
    No* arvoreTeste = NULL;

    inserir(arvoreTeste, 10);

    printf("-----");
    printf("Valor do root: %d", arvoreTeste->valor);
    
    return 0;
}