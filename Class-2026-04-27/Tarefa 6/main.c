#include <stdio.h>
#include <time.h>

int busca_binaria(int vetor[], int tamanho, int valor_procurado) {
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

int busca_inteira(int vetor[], int tamanho, int valor_procurado) {
    for(int i = 0; i < 100000; i++) {
        
    }
}

void gerarOsValoresParaOVetor(int vetor[]) {
    for(int i = 0; i < 100000; i++) {
        int valorParaOVetor = i;
        vetor[i] = valorParaOVetor;
    }
}

int main() {
    int dados[100000];
    gerarOsValoresParaOVetor(dados);
    int tamanho = sizeof(dados)/sizeof(dados[0]);
    int valorDesejado = 88;

    int posicao = busca_binaria(dados, tamanho, valorDesejado);

    if (posicao == -1) {
        printf("O valor %d não foi encontrado\n", valorDesejado);
    } else {
        printf("O valor %d foi encontrado na posicao %d\n", valorDesejado, posicao);
    }

    return 0;
}