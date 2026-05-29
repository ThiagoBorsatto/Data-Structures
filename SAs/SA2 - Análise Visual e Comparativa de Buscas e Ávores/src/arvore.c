#include "arvore.h"
#include <stdlib.h>

No* criarNo(int valor) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo) {
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    return novo;
}

No* inserirNaArvore(No *raiz, int valor) {
    No *atual = raiz;
    No *pai = NULL;
    
    if (raiz == NULL) return criarNo(valor);

    while (atual != NULL) {
        pai = atual;
        if (valor < atual->valor) {
            atual = atual->esquerda;
        } else if (valor > atual->valor) {
            atual = atual->direita;
        } else {
            return raiz; 
        }
    }

    if (valor < pai->valor) {
        pai->esquerda = criarNo(valor);
    } else {
        pai->direita = criarNo(valor);
    }

    return raiz;
}

int buscarNaArvore(No *raiz, int valor, long long *comparacoes) {
    No *atual = raiz;
    *comparacoes = 0;

    while (atual != NULL) {
        (*comparacoes)++;
        if (atual->valor == valor) {
            return 1; 
        }    
        
        (*comparacoes)++;
        if (valor < atual->valor) {
            atual = atual->esquerda;
        } else {
            atual = atual->direita;
        }
    }
    return 0; 
}

int calcularAltura(No *raiz) {
    if (raiz == NULL) return -1;
    
    int altEsq = calcularAltura(raiz->esquerda);
    int altDir = calcularAltura(raiz->direita);
    
    return (altEsq > altDir ? altEsq : altDir) + 1;
}

void liberarArvore(No *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}