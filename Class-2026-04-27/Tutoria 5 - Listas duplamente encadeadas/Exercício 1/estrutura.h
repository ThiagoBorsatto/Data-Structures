#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo *anterior;
    struct Nodo *proximo;
} Nodo;

typedef struct {
    Nodo *inicio;
    Nodo *fim;
    int tamanho;
} Lista;

Nodo* criar_nodo(int valor);
int obter_valor(Nodo *nodo);
void definir_valor(Nodo *nodo, int valor);
Nodo* obter_anterior(Nodo *nodo);
Nodo* obter_proximo(Nodo *nodo);
void definir_anterior(Nodo *nodo, Nodo *anterior);
void definir_proximo(Nodo *nodo, Nodo *proximo);
void destruir_nodo(Nodo *nodo);

Lista* criar_lista();
int esta_vazia(Lista *lista);
int obter_tamanho(Lista *lista);
void destruir_lista(Lista *lista);

#endif