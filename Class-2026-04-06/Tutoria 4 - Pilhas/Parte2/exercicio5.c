#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int log;
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

int push(Pilha *p, int log) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Sem memoria disponivel, libere espaco e tente novamente");
        return 0;
    }

    novo->log = log;
    novo->proximo = p->topo; 

    p->topo = novo;
    p->quantidade++;

    return 1;
}

int comparandoPilhas(Pilha *p1, Pilha *p2) {
    No *noTemporario1;
    No *noTemporario2;

    if (p1->quantidade != p2->quantidade) {
        printf("Erro: as pilhas tem quantidades de logs diferente\n");
        return 0;
    }
    
    noTemporario1 = p1->topo;
    noTemporario2 = p2->topo;
    for (int i = 0; i < p1->quantidade; i++) {
        if (noTemporario1->log != noTemporario2->log) {
            printf("O conteudo ou ordem das pilhas sao diferente!\n");
            return 0;
        }
        noTemporario1 = noTemporario1->proximo;
        noTemporario2 = noTemporario2->proximo;
    }

    printf("As pilhas sao iguais, mesmo conteudo e ordem!\n");
    return 1;
}

int main() {
    Pilha p1;
    Pilha p2;

    inicializar(&p1);
    inicializar(&p2);
    
    push(&p1, 1);
    push(&p2, 1);
   
    push(&p1, 2);
    push(&p2, 2);

    comparandoPilhas(&p1, &p2);

    push(&p1, 3);
    push(&p2, 4);

    comparandoPilhas(&p1, &p2);

    return 0;
}