#include <stdlib.h>
#include <stdio.h>

struct Fila {
    int *dados;
    int inicio;
    // int capacidade;
    // int tamanho;
    // int fim;
};

Fila* criar_fila(int capacidade) {
    Fila *f;

    if (capacidade == NULL)
    {
        print("Capacidade: \n");
        return NULL;
    }
    
};

void destruir_fila(Fila *f);
void imprimir_fila(Fila *f);