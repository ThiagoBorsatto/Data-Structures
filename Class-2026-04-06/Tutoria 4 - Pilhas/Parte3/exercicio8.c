#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char tokenDaFormula;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = NULL;
}

int push(Pilha *p, const char *formula) {
    int tamanhoDaMensagem = strlen(formula);
    // printf("Tamanho da mensagem: %d\n", tamanhoDaMensagem);
    
    for (int i = 0; i < tamanhoDaMensagem; i++) {
        No *novo = (No *) malloc(sizeof(No));
        if (novo == NULL) {
            printf("Sem memoria disponivel, libere espaco e tente novamente!");
            return 0;
        }
        

        if (formula[i] == '(' || formula[i] ==  '[' || formula[i] ==  '{') {
            novo->proximo = p->topo;
            novo->tokenDaFormula = formula[i];
           
            // printf("%c\n", novo->tokenDaFormula);

            p->topo = novo;
        } else if (formula[i] == ')' || formula[i] ==  ']' || formula[i] ==  '}') {
            No *noTemporario;

            novo->proximo = p->topo;
            noTemporario = novo->proximo;

            novo->tokenDaFormula = formula[i];
            
            // printf("%c\n", novo->tokenDaFormula);

            if (novo->tokenDaFormula == ')' && noTemporario->tokenDaFormula == '(' ||
                novo->tokenDaFormula == ']' && noTemporario->tokenDaFormula == '[' ||
                novo->tokenDaFormula == '}' && noTemporario->tokenDaFormula == '{'
            ) {
                // printf("Eles sao pares!");
                p->topo = novo->proximo;
            }
            p->topo = novo;
        }
    }
    return 1;
}

int main() {
    Pilha p;

    inicializar(&p);
    push(&p, "2*[3-1)-1{2-1}");

    return 0;
}