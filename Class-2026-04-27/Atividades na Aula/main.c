#include <stdio.h>
#include <time.h>

int busca_inteiro(int vetor[], int tamanho, int valor_procurado) {
    int inicio = 0;
    int fim = tamanho - 1;
    int comparacoes = 0;
    clock_t inicioTempo = clock();

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        comparacoes++;
        printf("Inicio: %d, Meio: %d, Fim: %d, Valor Procurado: %d\n", inicio, meio, fim, valor_procurado);

        if(vetor[meio] == valor_procurado) {
            clock_t fimTempo = clock();
            double tempo_ms = ((double)(fimTempo - inicioTempo) / CLOCKS_PER_SEC) * 1000.0;
            printf("Tempo decorrido: %.2f ms\n", tempo_ms);
            printf("Quantidade de Operacoes: %d\n", comparacoes);
            
            return meio;
        }

        if (valor_procurado < vetor[meio]) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}

int main() {
    int dados[] = {3, 7, 19, 42, 55, 88, 100, 142};
    int tamanho = sizeof(dados)/sizeof(dados[0]);
    int valor = 88;

    int posicao = busca_inteiro(dados, tamanho, valor);

    if (posicao == -1) {
        printf("O valor %d não foi encontrado\n", valor);
    } else {
        printf("O valor %d foi encontrado na posicao %d\n", valor, posicao);
    }
    

    return 0;
}