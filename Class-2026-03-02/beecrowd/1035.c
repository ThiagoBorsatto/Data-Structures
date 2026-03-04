#include <stdio.h>

int main() {
    int A, B, C, D, CD, AB, EVEN;

    scanf("%d %d %d %d", &A, &B, &C, &D);

    AB = A + B;
    CD = C + D;

    if (B > C && D > A && CD > AB && C > 0 && D > 0 && (A % 2) == 0)
    {
        printf("Valores aceitos\n");
    } else {
        printf("Valores nao aceitos\n");
    }

    return 0;
}