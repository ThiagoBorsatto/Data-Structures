#include <stdio.h>
#include <stdlib.h>

typedef struct DNode_ DNode;
struct DNode_ {
    int info;
    DNode *next;
    DNode *previous;
};

typedef struct DList_ {
    DNode *head;
    DNode *tail;
    int size;
} DList;

DList* creat_list() {
    DList *list = (DList *) malloc(sizeof(DList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void insert_head(DList *list, int value) {
    DNode *new_node = (DNode *) malloc(sizeof(DNode));
    new_node->info = value;
    new_node->previous = NULL;
    new_node->next = list->head;

    if (list->size == 0) {
        list->tail = new_node;
    } else {
        list->head->previous = new_node;
    }
    
    list->head = new_node;
    list->size++;
}

void insert_tail(DList *list, int value) {
    DNode *new_node = (DNode *) malloc(sizeof(DNode));
    new_node->info = value;
    new_node->previous = list->tail;
    new_node->next = NULL;

    if (list->size == 0) {
        list->head = new_node;
    } else {
        list->tail->next = new_node;
    }
    
    list->tail = new_node;
    list->size++;
}

int buscar_paciente_reverso(DList *list, int id_procurado) {
    DNode *new_node = (DNode *) malloc(sizeof(DNode));

    if (list == NULL) {
        printf("Fila vazia, sem pacientes para atender!\n");
        return 0;
    }
    new_node = list->tail;
    while (new_node->previous != NULL) {
        printf("%d\n", new_node->info);
        new_node = new_node->previous;
    }

    printf("Paciente encontrado: %d\n", new_node->info);
    free(new_node);
    return 1;
}

void insert_on_the_middle(DNode *current_node, DNode *new_node) {
    new_node->next = current_node->next;
    new_node->previous = current_node;

    current_node->next->previous = new_node;
    current_node->next = new_node;
}

// Resposta: Nesse caso como nos já temos as funções de remoção e adição de pacientes, podemos usar a duas combinadas para remover o paciente desejado, e já adicionalo no começo da Lista.
// Nossa função de promover_paciente já recebe a LISTA eo Id do paciente, assim podemos passar a lista e o paciente desejado para as funções, a função de remoção vai encotrar o paciente que queremos passar para frente, e vai tiralo da lista, 
// e também já arrumar o relacionamento dos nós que ficaram, se não a lista vai se perder.
// Depois da remoção como ainda temos o paciente passamos para a função de inserir na frente(HEAD) para que este paciente fique na primeira possição da lista, no caso o HEAD.
// Como o professor não tinha passado o código eu fiz minha própria função de remoção.

void promover_paciente(DList *list, int id) {
    remove_from_the_list(list, id);
    insert_head(list, id);
}

void remove_from_the_list(DList *list, int id_procurado) {
    DNode *new_node = (DNode *) malloc(sizeof(DNode));

    if (list == NULL) {
        printf("Fila vazia, sem pacientes para atender!\n");
        return 0;
    }
    new_node = list->head;
    while (new_node->next != NULL) {
        if (new_node->info == id_procurado) {
            new_node->previous->next = new_node->next;
            new_node->next->previous = new_node->previous;

            free(new_node);
            return 0;
        }
        
        new_node = new_node->next;
    }
    free(new_node);
}

int main() {
    return 0;
}
