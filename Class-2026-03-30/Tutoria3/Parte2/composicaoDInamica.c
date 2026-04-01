#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char rua[50];
    int numero;
} Endereco;

typedef struct {
    char nome[50];
    Endereco *end;
} Pessoa;

int main() {
    Pessoa *p = (Pessoa *) malloc(sizeof(Pessoa));
    if (p == NULL) return 1;

    strcpy(p->nome, "Douglas Nolli");

    p->end = (Endereco *) malloc(sizeof(Endereco));
    if (p->end == NULL) {
        free(p);
        return 1;
    }

    strcpy(p->end->rua, "Av. Jaraguá");
    p->end->numero = 1000;

    printf("Nome: %s\n", p->nome);
    printf("Endereco: %s, %d\n", p->end->rua, p->end->numero);

    free(p->end); 
    free(p);

    return 0;
}