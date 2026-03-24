#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor, i, capacidade = 5;

    printf("Escolha a capacidade do VETOR: ");
    scanf("%d", &capacidade);

    vetor = (int *) malloc(sizeof(int) * capacidade);

    if (vetor == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < capacidade; i++)
    {
        vetor[i] = (i + 1) * 10;
    }
    
    printf("Conteudo do vetor: ");

    for (i = 0; i < capacidade; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Lembrete: Toda memória alocada com malloc deve ser liberada
    free(vetor);

    return 0;
}