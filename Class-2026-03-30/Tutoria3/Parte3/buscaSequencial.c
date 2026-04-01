#include <stdio.h>
#include <stdlib.h>

typedef struct { 
    int id; 
    float preco; 
} Produto;

Produto* buscar_id(Produto *vetor, int tam, int id_busca) {
    for (int i = 0; i < tam; i++) {
        if (vetor[i].id == id_busca) return &vetor[i];
    }
    return NULL;
}