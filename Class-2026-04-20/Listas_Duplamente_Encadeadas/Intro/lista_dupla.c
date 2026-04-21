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

void print_list_forward() {
    
}

int main() {
    
    return 0;
}