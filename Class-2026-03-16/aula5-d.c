#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10;
    int *p;
    p = &x; // Ponteiro recebe endereço de X

    printf("Valor de x: %d\n", x);
    printf("Endereco de x: %p\n", &x);
    printf("Valor usando ponteiro: %d\n", *p);

    int *p2;
    p2 = (int *) malloc(sizeof(int)); // aloca memoria para um inteiro
    *p2 = 10;

    printf("Valor guardado em p2: %d\n", *p2);
    printf("Endereco de x mémoria: %p\n", p2);
    
    free(p2);

    int *vetor;
    int n = 5;
    vetor = malloc(n * sizeof(int));

    return 0;
}