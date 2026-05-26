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

No* remover(No *raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

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

        No* temp = raiz->direita;
        
        while (temp != NULL && temp->esquerda != NULL) {
            temp = temp->esquerda;
        }

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

void liberarArvore(No *raiz) {
    if (raiz == NULL) {
        return;
    }

    liberarArvore(raiz->esquerda);

    liberarArvore(raiz->direita);

    free(raiz);
}

int main() {
    No* arvoreVazia = NULL;

    arvoreVazia = inserir(arvoreVazia, 50);
    arvoreVazia = inserir(arvoreVazia, 30);
    arvoreVazia = inserir(arvoreVazia, 70);
    arvoreVazia = inserir(arvoreVazia, 20);
    arvoreVazia = inserir(arvoreVazia, 40);
    arvoreVazia = inserir(arvoreVazia, 60);
    arvoreVazia = inserir(arvoreVazia, 80);

    emOrdem(arvoreVazia);

    printf("\n");
    buscar(arvoreVazia, 40);
    buscar(arvoreVazia, 90);

    printf("\n");
    remover(arvoreVazia, 60);
    
    emOrdem(arvoreVazia);
    
    printf("\n");
    liberarArvore(arvoreVazia);

    return 0;
}