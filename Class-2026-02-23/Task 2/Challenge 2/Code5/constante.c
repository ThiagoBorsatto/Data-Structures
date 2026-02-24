#include <stdio.h>

#define FATOR 10;

int main() {
    int numero;

    printf("Digite um numero com casas decimais: ");
    scanf("%d", &numero);

    int resultado = numero * FATOR;

    printf("Seu numero multiplicado por 10: %d\n", resultado);

    return 0;
}
