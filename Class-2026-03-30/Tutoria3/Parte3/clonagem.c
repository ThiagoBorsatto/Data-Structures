#include <stdio.h>
#include <stdlib.h>

typedef struct { 
    int id; 
    float preco; 
} Produto;

typedef struct { 
    char nome[50]; 
    float nota; 
} Aluno;

Produto* clonar(Produto *origem) {
    if (origem == NULL) return NULL;
    Produto *novo = (Produto *) malloc(sizeof(Produto));
    *novo = *origem; 
    return novo;
}