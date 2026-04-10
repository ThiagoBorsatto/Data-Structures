#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char utimaUrl[100];
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

int push(Pilha *p, const char *url) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Sem memoria disponivel, libere espaco e tente novamente");
        return 0;
    }

    strcpy(novo->utimaUrl, url);
    novo->proximo = p->topo; 

    p->topo = novo;
    p->quantidade++;

    printf("Ultima URL salva: %s\n", novo->utimaUrl);

    return 1;
}

int main() {
    Pilha p;

    inicializar(&p);
    
    push(&p, "https://www.exemplo1.com");
    push(&p, "https://www.exemplo2.com");
    
    return 0;
}