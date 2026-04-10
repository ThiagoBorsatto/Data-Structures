#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char texto[100];
    struct No *proximo;
} No;

typedef struct {
    No *topo;
    int ultimaAcao;
    int quantidade;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = NULL;
    p->ultimaAcao = 0;
    p->quantidade = 0;
}

int push(Pilha *p, char acao) {
    No *novo = (No *) malloc(sizeof(No)); 

    if (novo == NULL) {
        printf("Erro: Sem memoria disponivel!");
        return 0;
    }

    novo->texto[p->ultimaAcao] = acao;
    novo->proximo = p->topo; 

    p->topo = novo;
    p->ultimaAcao++;
    p->quantidade++;

    return 1;
}

int pop(Pilha *p,int *ultimaAcao) {
    No *temp;

    if (p->topo == NULL) {
        printf("Erro: Nao ha acoes para desfazer");
        return 0;
    }

    temp = p->topo;

    p->topo = temp->proximo;

    free(temp);
    p->quantidade--;
    p->ultimaAcao--;

    return 1;
}

int main() {
    Pilha p;
    int removido;

    inicializar(&p);
    
    push(&p, "O");
    push(&p, "Ol");
    push(&p, "Ola");

    while (pop(&p, &removido)) {
        printf("Valor removido: %d\n", removido);
    }
    
    return 0;
}