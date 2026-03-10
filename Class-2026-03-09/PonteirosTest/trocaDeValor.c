#include <stdio.h>

void troca(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 5, b = 10;

    printf("Antes da troca: a = %d, b = %d\n", a, b);
    troca(&a, &b);
    printf("Depois da troca: a = %d, b = %d\n", a, b);
    return 0;
}