#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char letra;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
    int quantidade;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = NULL;
    p->quantidade = 0;
}

int push(Pilha *p, const char *mensagem) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Sem memoria disponivel, libere espaco e tente novamente!");
        return 0;
    }

    for (int i = 0; i < strlen(mensagem); i++) {
        novo->letra = mensagem[i];
        printf("letra: %c\n", novo->letra);
        novo->proximo = p->topo;

        p->topo = novo;
        p->quantidade++;
    }
    return 1;
}

int main() {
    Pilha p;

    inicializar(&p);
    
    push(&p, "thiago");

    return 0;
}