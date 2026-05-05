#include <stdio.h>

void selection_sort(int vetor[], int tamanho) {
    for (int posicao_atual = 0; posicao_atual < tamanho - 1; posicao_atual++) {
        int posicao_menor = posicao_atual;

        for (int i = posicao_atual + 1; i < tamanho; i++) {
            if (vetor[i] < vetor[posicao_atual]) {
                posicao_menor = i;
            }
        }
        if(posicao_menor != posicao_atual) {
            int auxiliar = vetor[posicao_atual];
            vetor[posicao_atual] = vetor[posicao_menor];
            vetor[posicao_menor] = auxiliar;
        }
    }
}

int main() {
    int vetor[] = {6, 8, 15, 28, 3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    selection_sort(vetor, tamanho);

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}