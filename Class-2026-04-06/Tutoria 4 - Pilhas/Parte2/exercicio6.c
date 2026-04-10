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
    int tamanhoDaMensagem = strlen(mensagem);
    // printf("Tamanho da mensagem: %d\n", tamanhoDaMensagem);
    
    for (int i = 0; i < tamanhoDaMensagem; i++) {
        No *novo = (No *) malloc(sizeof(No));
        if (novo == NULL) {
            printf("Sem memoria disponivel, libere espaco e tente novamente!");
            return 0;
        }
        
        novo->proximo = p->topo;
        novo->letra = mensagem[i];
        
        p->topo = novo;
        p->quantidade++;
    }
    return 1;
}

int criptografiaReversa(Pilha *p) {
    No *noTemporario;
    noTemporario = p->topo;

    printf("Mensagem reversa: ");
    for (size_t i = 0; i < p->quantidade; i++) {
        printf("%c", noTemporario->letra);
        noTemporario = noTemporario->proximo;
    }    
    return 1;
}

int main() {
    Pilha p;

    inicializar(&p);
    
    push(&p, "thiago borsatto");

    criptografiaReversa(&p);

    return 0;
}