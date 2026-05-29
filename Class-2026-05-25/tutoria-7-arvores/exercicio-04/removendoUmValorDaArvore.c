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

No* encontrarMinimo(No* raiz) {
    No* atual = raiz;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

No* remover(No *raiz, int valor) {
    if (raiz == NULL) return raiz;

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        No* temp = encontrarMinimo(raiz->direita);
        
        raiz->valor = temp->valor;
        
        raiz->direita = remover(raiz->direita, temp->valor);
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

int main() {
    No* arvoreVazia = NULL;

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

    remover(arvoreVazia, 20);
    emOrdem(arvoreVazia);
    printf("\n");

    remover(arvoreVazia, 30);
    emOrdem(arvoreVazia);
    printf("\n");

    remover(arvoreVazia, 50);
    emOrdem(arvoreVazia);
    printf("\n");

    return 0;
}