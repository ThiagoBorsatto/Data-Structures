#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char binario;
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

int push(Pilha *p, int resto) {
    No *novo = (No *) malloc(sizeof(No));
    
    if (novo == NULL) {
        printf("Sem memoria disponivel, libere espaco e tente novamente!");
        return 0;
    }
        
    novo->proximo = p->topo;
    novo->binario = resto + '0';
    // printf("Numero binario salvo na pilha: %c\n", novo->binario);
        
    p->topo = novo;
    p->quantidade++;
    return 1;
}

void decimalParaBinario(Pilha *p,int decimal) {
    int resto;

    printf("Decimal: %d\n", decimal);

    while (decimal != 0) {
        resto = decimal % 2;
        decimal = decimal / 2;
        push(p, resto);
        // printf("Decimal: %d\n", decimal);
        // printf("Resto: %d\n", resto);
    }
}

void imprimirValorBinario(Pilha *p) {
    No *noTemporario;
    printf("Valor decimal em binario: ");

    noTemporario = p->topo;
    // printf("%c\n", noTemporario->binario);

    for (int i = 0; i < p->quantidade; i++) {
        printf("%c", noTemporario->binario);
        noTemporario = noTemporario->proximo;
    }
    
}

int main() {
    Pilha p;

    inicializar(&p);
    decimalParaBinario(&p, 32);
    imprimirValorBinario(&p);

    return 0;
}