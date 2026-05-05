#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente_ {
    int codigo;
    char nome[50];
    char telefone[15];
} Cliente;

void insertion_sort(Cliente vetor_de_clientes[], int tamanho, int *comparacoes, int *trocas) {
    printf("Insertion Sort\n");

    for (int i = 1; i < tamanho; i++) {
        Cliente cliente_atual = vetor_de_clientes[i];
        int j = i - 1;

        while (j >= 0) {
            (*comparacoes)++;
            Cliente cliente_auxiliar = vetor_de_clientes[j];

            if (cliente_atual.codigo < cliente_auxiliar.codigo) {
                vetor_de_clientes[j + 1] = vetor_de_clientes[j];
                j--;
                (*trocas)++;
            } else {
                break;
            }
        }
        vetor_de_clientes[j + 1] = cliente_atual;
    }
}

int main() {
    Cliente vetor_de_clientes[] = {
        {20, "Thiago B", "1111-1111"},
        {10, "Douglas N", "1111-2222"},
        {12, "Teste 1", "1111-3333"},
        {5, "Teste 2", "1111-4444"},
        {24, "Teste 3", "1111-5555"},
        {22, "Teste 4", "1111-6666"},
        {1, "Teste 5", "1111-7777"},
        {30, "Teste 6", "1111-8888"},
        {13, "Teste 7", "1111-9999"},
        {8, "Teste 8", "1111-1010"},
        {873, "Teste 9", "1111-1111"},
        {2, "Teste 10", "1111-1111"},
        {2, "Teste 10", "1111-1111"}
    };
    int tamanho = sizeof(vetor_de_clientes)/sizeof(vetor_de_clientes[0]);
    int comparacoes = 0;
    int trocas = 0;

    insertion_sort(vetor_de_clientes, tamanho, &comparacoes, &trocas);

    for (int i = 0; i < tamanho; i++) {
        Cliente cliente = vetor_de_clientes[i];
        printf("%d ", cliente.codigo);
    }

    printf("\n");
    printf("Numero de comparacoes: %d\n", comparacoes);
    printf("Numero de trocas: %d\n", trocas);
    printf("\n");

    return 0;
}