#include <stdio.h>

void bubble_sort(int vetor[], int tamanho, int *comparacoes, int *trocas) {
    printf("Bubble Sort\n");
    int houve_troca = 1;

    while (houve_troca == 1) {
        houve_troca = 0;

        for (int i = 0; i < tamanho -1; i++) {
            (*comparacoes)++;

            if (vetor[i] > vetor[i + 1]) {
                int auxiliar = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = auxiliar;

                (*trocas)++;

                houve_troca = 1;
            }
        }
    }
    
}

void insertion_sort(int vetor[], int tamanho, int *comparacoes, int *trocas) {
    printf("Insertion Sort\n");
    for (int i = 1; i < tamanho; i++) {
        int valor_atual = vetor[i];
        int j = i - 1;

        while (j >= 0) {
            (*comparacoes)++;

            if (vetor[j] > valor_atual) {
                vetor[j + 1] = vetor[j];
                j--;
                (*trocas)++;
            } else {
                break;
            }
        }
        vetor[j + 1] = valor_atual;
    }
}

void selection_sort(int vetor[], int tamanho, int *comparacoes, int *trocas) {
    printf("Selection Sort\n");
    for (int posicao_atual = 0; posicao_atual < tamanho - 1; posicao_atual++) {
        int posicao_menor = posicao_atual;

        for (int i = posicao_atual + 1; i < tamanho; i++) {
            if (vetor[i] < vetor[posicao_atual]) {
                posicao_menor = i;
            }
            (*comparacoes)++;
        }

        if(posicao_menor != posicao_atual) {
            int auxiliar = vetor[posicao_atual];
            vetor[posicao_atual] = vetor[posicao_menor];
            vetor[posicao_menor] = auxiliar;
            (*trocas)++;
        }
    }
}

int main() {
    int vetor[] = {6, 8, 28, 15, 3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int comparacoes = 0;
    int trocas = 0;

    // bubble_sort(vetor, tamanho, &comparacoes, &trocas);
    // selection_sort(vetor, tamanho, &comparacoes, &trocas);
    insertion_sort(vetor, tamanho, &comparacoes, &trocas);
    
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    printf("Numero de comparacoes: %d\n", comparacoes);
    printf("Numero de trocas: %d\n", trocas);
    printf("\n");

    return 0;
}