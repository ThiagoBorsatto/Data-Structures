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