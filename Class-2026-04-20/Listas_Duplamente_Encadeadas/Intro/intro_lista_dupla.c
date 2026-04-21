#include <stdio.h>
#include <stdlib.h>

typedef struct DNode_ DNode;

struct DNode_ {
    int info;
    DNode *next;
    DNode *previous;
};

int main() {
    DNode *node1 = (DNode *) malloc(sizeof(DNode));
    DNode *node2 = (DNode *) malloc(sizeof(DNode));
    DNode *node3 = (DNode *) malloc(sizeof(DNode));


    // Colocar as INFO nos NODEs.
    node1->info = 10;
    node2->info = 20;
    node3->info = 30;

    // Configurar os NODE com o encadeamento duplo.
    node1->previous = NULL;
    node1->next = node2;

    node2->previous = node1;
    node2->next =node3;

    node3->previous = node2;
    node3->next = NULL;

    // Navegar para frente (HEAD -> TAIL).
    printf("HEAD -> TAIL\n");
    DNode *atual = node1;
    while (atual != NULL) {
        printf("%d -> ", atual->info);
        atual = atual->next;
    }
    printf("NULL\n");
    
    // Navegar para frente (TAIL -> HEAD).
    printf("TAIL -> HEAD\n");
    atual = node3;
    while (atual != NULL) {
        printf("%d -> ", atual->info);
        atual = atual->previous;
    }
    printf("NULL\n");

    free(node1);
    free(node2);
    free(node3);

    return 0;
}