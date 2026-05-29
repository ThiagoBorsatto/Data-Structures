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

void emOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    emOrdem(raiz->esquerda);

    printf("Valor: %d\n", raiz->valor);

    emOrdem(raiz->direita);
}

int menorValor(No *raiz) {
    No* atual = raiz;
    
    if (raiz == NULL) {
        return 0;
    }
    
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual->valor;
}

int maiorValor(No *raiz) {
    No* atual = raiz;

    if (raiz == NULL) {
        return -1;
    }
    
    while (atual->direita != NULL) {
        atual = atual->direita;
    }
    return atual->valor;
}

int main() {
    No* arvoreVazia = NULL;
    int menorValorDaArvore = 0;
    int maiorValorDaArvore = 0;
    
    arvoreVazia = inserir(arvoreVazia, 50);
    arvoreVazia = inserir(arvoreVazia, 30);
    arvoreVazia = inserir(arvoreVazia, 70);
    arvoreVazia = inserir(arvoreVazia, 20);
    arvoreVazia = inserir(arvoreVazia, 40);
    arvoreVazia = inserir(arvoreVazia, 90);
    arvoreVazia = inserir(arvoreVazia, 60);
    arvoreVazia = inserir(arvoreVazia, 80);
    arvoreVazia = inserir(arvoreVazia, 100);
    arvoreVazia = inserir(arvoreVazia, 10);

    emOrdem(arvoreVazia);
    printf("\n");

    menorValorDaArvore = menorValor(arvoreVazia);
    maiorValorDaArvore = maiorValor(arvoreVazia);

    printf("Menor valor da arvore: %d\n", menorValorDaArvore);
    printf("Maior valor da arvore: %d\n", maiorValorDaArvore);

    return 0;
}