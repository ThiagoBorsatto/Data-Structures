#include <stdio.h>

int main() {
    int N, NConst, NOTA100, NOTA50, NOTA20, NOTA10, NOTA5, NOTA2, NOTA1;

    scanf("%d", &N);
    NConst = N;

    NOTA100 = N / 100;
    N = N - (100 * NOTA100);
    
    NOTA50 = N / 50;
    N = N - (50 * NOTA50);

    NOTA20 = N / 20;
    N = N - (20 * NOTA20);

    NOTA10 = N / 10;
    N = N - (10 * NOTA10);
    
    NOTA5 = N / 5;
    N = N - (5 * NOTA5);
    
    NOTA2 = N / 2;
    N = N - (2 * NOTA2);
    
    NOTA1 = N / 1;
    N = N - (1 * NOTA1);
    
    printf("%d\n", NConst);
    printf("%d nota(s) de R$ 100,00\n", NOTA100);
    printf("%d nota(s) de R$ 50,00\n", NOTA50);
    printf("%d nota(s) de R$ 20,00\n", NOTA20);
    printf("%d nota(s) de R$ 10,00\n", NOTA10);
    printf("%d nota(s) de R$ 5,00\n", NOTA5);
    printf("%d nota(s) de R$ 2,00\n", NOTA2);
    printf("%d nota(s) de R$ 1,00\n", NOTA1);
    
    return 0;
}