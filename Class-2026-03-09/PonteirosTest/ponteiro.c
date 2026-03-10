#include <stdio.h>
 
int main() {
    // Marcar Var com o *
    int *p;
    int x = 42;

    p = &x;
 
    int soma = 0;

    soma = somar(soma, 5);
    soma = somar(soma, 5);

    printf("%d\n", x); // Valor da VAR
    printf("%d\n", p); // Endereço na Memoria 
    printf("%d\n", *p); // Valor da VAR
    printf("%d\n", &p); // Endereço na Memoria
    printf("%d\n", soma);

    return 0;
}