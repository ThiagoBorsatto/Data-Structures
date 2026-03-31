#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Escolha a quantidade de NOTAS: ");
    scanf("%d", &n);

    int *vetorDeInteiros = (int *) malloc(sizeof(int));
    float notaFinal = 0; 

    for (int i = 0; i < n ; i++)
    {
        printf("Digite a nota %d: ", i + 1);
        scanf("%d", &vetorDeInteiros[i]);
        notaFinal += vetorDeInteiros[i];
    }

    notaFinal = notaFinal/n;
    printf("Nota Final: %.2f", notaFinal);

    free(vetorDeInteiros);
    return 0;
}