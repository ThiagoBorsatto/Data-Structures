#include <stdio.h>

int main() {
    int fila[5];
    int tamanho = 0;
    int i;

    // inserções ao fim da fila

    fila[tamanho] = 10;
    tamanho++;

    fila[tamanho] = 20;
    tamanho++;

    fila[tamanho] = 30;
    tamanho++;

    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", fila[i]);
    }

    printf("\n");

    printf("Removido do inicio: %d\n", fila[0]);

    for (i = 0; i < tamanho - 1; i++)
    {
        fila[i] = fila[i + 1];
    }

    tamanho--;

    printf("Apos a remocao:\n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", fila[i]);
    }
    
    return 0;
}