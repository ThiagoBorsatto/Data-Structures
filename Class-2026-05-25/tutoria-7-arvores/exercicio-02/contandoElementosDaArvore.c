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

void liberarArvore(No *raiz) {
    if (raiz == NULL) {
        return;
    }

    liberarArvore(raiz->esquerda);

    liberarArvore(raiz->direita);

    free(raiz);
}

int contarNos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

int contarFolhas(No *raiz) {
    if (raiz == NULL ) {
        return 0;
    }
   
    if (raiz->direita == NULL && raiz->esquerda == NULL) {
        return 1;
    }

    return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}

int contarNosComDoisFilhos(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->esquerda != NULL && raiz->direita != NULL) {
        return 1 + contarNosComDoisFilhos(raiz->esquerda) + contarNosComDoisFilhos(raiz->direita);
    } else {
        return contarNosComDoisFilhos(raiz->esquerda) + contarNosComDoisFilhos(raiz->direita);
    }

}

int altura(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int niveisEsquerda = altura(raiz->esquerda);
    int niveisDireita = altura(raiz->direita);

    if (niveisEsquerda > niveisDireita) {
        return 1;
    } else {
        return 1;
    }
}

int main() {
    No* arvoreVazia = NULL;
    int numeroDeNos = 0;
    int numeroDeFolhas = 0;
    int numeroDeNosComDoisFilhos = 0;
    int alturaDaArvore = 0;

    arvoreVazia = inserir(arvoreVazia, 50);
    arvoreVazia = inserir(arvoreVazia, 30);
    arvoreVazia = inserir(arvoreVazia, 70);
    arvoreVazia = inserir(arvoreVazia, 20);
    arvoreVazia = inserir(arvoreVazia, 40);
    arvoreVazia = inserir(arvoreVazia, 60);

    numeroDeNos = contarNos(arvoreVazia);
    numeroDeFolhas = contarFolhas(arvoreVazia);
    numeroDeNosComDoisFilhos = contarNosComDoisFilhos(arvoreVazia);
    alturaDaArvore = altura(arvoreVazia);


    printf("Total de nos: %d\n", numeroDeNos);
    printf("Total de folhas: %d\n", numeroDeFolhas);
    printf("Nos com dois filhos: %d\n", numeroDeNosComDoisFilhos);
    printf("Altura: %d\n", altura);

    return 0;
}