#include <stdio.h>
#include <stdlib.h>

typedef struct { 
    char nome[50]; 
    float nota; 
} Aluno;

Aluno* filtrar_aprovados(Aluno *lista, int tam, int *qtd_aprovados) {
    Aluno **aprovados = (Aluno **) malloc(tam * sizeof(Aluno *));
    *qtd_aprovados = 0;
    for (int i = 0; i < tam; i++) {
        if (lista[i].nota > 7.0) {
            aprovados[(*qtd_aprovados)++] = &lista[i];
        }
    }
    return aprovados;
}