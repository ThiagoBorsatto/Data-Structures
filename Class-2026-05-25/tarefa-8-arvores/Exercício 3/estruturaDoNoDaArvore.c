#include <stdlib.h>
#include <stdio.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;