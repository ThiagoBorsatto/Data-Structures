#include <stdio.h>

int main() {
    char nome;
    int inteiro;
    float decimal;
    double inteiroMaior;


    printf("O tamanho em bytes do char: %zu bytes\n", sizeof(nome));
    printf("O tamanho em bytes do int: %zu bytes\n", sizeof(inteiro));
    printf("O tamanho em bytes float: %zu bytes\n", sizeof(decimal));
    printf("O tamanho em bytes double: %zu bytes\n", sizeof(inteiroMaior));
    return 0;
}
