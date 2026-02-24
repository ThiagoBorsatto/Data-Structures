#include <stdio.h>

int main() {
    float numero;

    printf("Digite um numero com casas decimais: ");
    scanf("%f", &numero);
    printf("Seu número foi %.2f\n", numero);
    return 0;
}
