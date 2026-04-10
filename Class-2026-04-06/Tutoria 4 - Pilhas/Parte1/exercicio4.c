#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int caixaNumero;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = NULL;
}

int push(Pilha *p, int numeroDaCaixa) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Sem memoria disponivel, libere espaco e tente novamente");
        return 0;
    }

    novo->caixaNumero = numeroDaCaixa;
    novo->proximo = p->topo; 

    p->topo = novo;

    printf("---TESTES---\n");
    printf("Numero da caixa registrado: %d\n", novo->caixaNumero);
    printf("\n");

    return 1;
}

int contarNumeroDeCaixas(Pilha *p) {
    No *noTemporario;
    int quantidadeDeCaixas = 1;
    
    if (p == NULL) {
        printf("Pilha de caixas vazia!\n");
        return 0;
    }

    noTemporario = p->topo;
    while (noTemporario->proximo != NULL) {
        noTemporario = noTemporario->proximo;
        quantidadeDeCaixas++;
    }

    printf("Quantidade de caixas: %d\n", quantidadeDeCaixas);
    return 1;
}

int main() {
    Pilha p;

    inicializar(&p);
    
    push(&p, 1);
    push(&p, 10);
    push(&p, 7);
    
    contarNumeroDeCaixas(&p);

    return 0;
}