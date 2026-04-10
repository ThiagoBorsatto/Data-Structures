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

    printf("Meus TESTES\n");
    printf("Ultima URL salva: %s\n", novo->utimaUrl);
    printf("Quantidade de URLs: %d\n", p->quantidade);
    printf("URL no topo da pilha: %s\n", p->topo->utimaUrl);
    printf("\n");

    return 1;
}

int limpar_pilha(Pilha *p) {
    No *proximoNo;
    int quantidadeDeBytesLiberados;

    if (p->topo == NULL) {
        printf("Erro: pilha vazia\n");
        return 0;
    }

    while (p->topo != NULL)
    {
        proximoNo = p->topo->proximo;
    
        quantidadeDeBytesLiberados += sizeof(p->topo);
        free(p->topo);

        p->topo = proximoNo;
        p->quantidade--;
    }

    printf("Quantidade de BYTES liberados: %d\n", quantidadeDeBytesLiberados);
    printf("Quantidade de URLs: %d\n", p->quantidade);

    return 1;
}

int main() {
    Pilha p;

    inicializar(&p);
    
    push(&p, "https://www.exemplo1.com");
    push(&p, "https://www.exemplo2.com");
    push(&p, "https://www.exemplo3.com");
    
    limpar_pilha(&p);

    return 0;
}