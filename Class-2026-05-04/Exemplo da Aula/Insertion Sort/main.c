#include <stdio.h>

void insertion_sort(int vetor[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int valor_atual = vetor[i];
        int j = i - 1;

        while (j >= 0) {
            if (vetor[j] > valor_atual) {
                vetor[j + 1] = vetor[j];
                j--;
            } else {
                break;
            }
        }
        vetor[j + 1] = valor_atual;
    }
}

int main() {
    int vetor[] = {6, 8, 15, 28, 3, 13};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    insertion_sort(vetor, tamanho);

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}