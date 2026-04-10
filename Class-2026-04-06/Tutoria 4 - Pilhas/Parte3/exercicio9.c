#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int placaDoCarro;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
    int quantidadeDeCarros;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = NULL;
    p->quantidadeDeCarros = 0;
}

int push(Pilha *p, int placaDoCarro) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Sem espaco no estacionamento, espere ser liberado um novo espaco!");
        return 0;
    }

    novo->placaDoCarro = placaDoCarro;
   // printf("%d\n", novo->placaDoCarro);

    novo->proximo = p->topo;

    if (p->topo != NULL) {
        No *noTemporario;
        noTemporario = p->topo;

        if (novo->placaDoCarro < noTemporario->placaDoCarro) {
            printf("O carro do topo tem o numero de placa: %d\n", novo->placaDoCarro);
            p->topo = novo;
            // printf("%d\n", p->topo->placaDoCarro);

            p->quantidadeDeCarros++;

            return 1;
        }
        printf("Placa do carro no topo: %d\n", noTemporario->placaDoCarro);
    }

    p->topo = novo;
    p->quantidadeDeCarros++;

    return 1;    
}

int main() {
    Pilha p;

    inicializar(&p);
    push(&p, 10);
    push(&p, 20);
    
    return 0;
}