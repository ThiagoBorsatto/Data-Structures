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

int buscaArvore(No* raiz, int valorBuscado, int *comparacoes) {
    if (raiz == NULL) {
        return 0; 
    }
    
    (*comparacoes)++;
    if (raiz->valor == valorBuscado) {
        return 1; 
    } else if (valorBuscado < raiz->valor) {
        return buscaArvore(raiz->esquerda, valorBuscado, comparacoes);
    } else {
        return buscaArvore(raiz->direita, valorBuscado, comparacoes);
    }
}

int buscaSequencial(int vetor[], int tamanho, int valorBuscado, int *comparacoes) {
    *comparacoes = 0;
    for (int i = 0; i < tamanho; i++) {
        (*comparacoes)++;
        if (vetor[i] == valorBuscado) {
            return 1; 
        }
    }
    return 0;
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
    int vetor[] = {15, 8, 25, 4, 12, 20, 30, 2, 6, 10, 14, 18, 22, 28, 35, 75, 90, 1};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valorBuscado = 75;
    int compVetor = 0;
    int compArvore = 0;

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


    int achouVetor = buscaSequencial(vetor, tamanho, valorBuscado, &compVetor);
    printf("Busca sequencial:\n");
    if (achouVetor) {
        printf("Encontrado.\n"); 
    } else {
        printf("Nao encontrado.\n");
    }

    printf("Comparacoes: %d\n\n", compVetor);

    int achouArvore = buscaArvore(arvoreVazia, valorBuscado, &compArvore);
    printf("Busca na arvore:\n");
    if (achouArvore) {
        printf("Encontrado.\n");
     } else {
        printf("Nao encontrado.\n");
     }
     
    printf("Comparacoes: %d\n", compArvore);

    return 0;
}