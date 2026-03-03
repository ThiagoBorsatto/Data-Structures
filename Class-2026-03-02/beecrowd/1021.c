#include <stdio.h>

int main() {
    double valor_input;
    scanf("%lf", &valor_input);

    int total_centavos = (int)(valor_input * 100 + 0.5);

    printf("NOTAS:\n");
    
    int notas[] = {10000, 5000, 2000, 1000, 500, 200};
    for (int i = 0; i < 6; i++) {
        int qtd = total_centavos / notas[i];
        printf("%d nota(s) de R$ %.2f\n", qtd, (float)notas[i] / 100);
        total_centavos %= notas[i];
    }

    printf("MOEDAS:\n");
    
    int moedas[] = {100, 50, 25, 10, 5, 1};
    for (int i = 0; i < 6; i++) {
        int qtd = total_centavos / moedas[i];
        printf("%d moeda(s) de R$ %.2f\n", qtd, (float)moedas[i] / 100);
        total_centavos %= moedas[i];
    }

    return 0;
}