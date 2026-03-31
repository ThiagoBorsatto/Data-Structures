#include <stdio.h>
#include <stdlib.h>

int main() {
    float *valor;    
    valor = (float *) malloc(sizeof(float));

    printf("Digite um valor com casas decimais: ");
    scanf("%f", valor);

    printf("Valor do float: %.2f\n", *valor);

    return 0;
}