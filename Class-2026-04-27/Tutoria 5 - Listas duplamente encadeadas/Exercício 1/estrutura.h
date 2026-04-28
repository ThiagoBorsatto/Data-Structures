#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "requisicao.h"

typedef struct Nodo
{
    int valor;
    struct Nodo *anterior;
    struct Nodo *proximo;
} Nodo;

typedef struct
{
    Nodo* head;
    Nodo* tail;
    int size;
} Fila;

Nodo* criar_nodo(int valor);
int obter_valor(Nodo *nodo);
void definir_valor(Nodo *nodo, int valor);
Nodo* obter_anterior(Nodo *nodo);
Nodo* obter_proximo(Nodo *nodo);
void definir_anterior(Nodo *nodo, Nodo *anterior);
void definir_proximo(Nodo *nodo, Nodo *proximo);
void destruir_nodo(Nodo *nodo);

#endif