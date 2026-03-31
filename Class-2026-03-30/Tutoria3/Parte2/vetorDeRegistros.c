#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float nota;
} Aluno;

int main() {
    int n = 3; 

    Aluno *lista_alunos = (Aluno *) malloc(n * sizeof(Aluno));

    if (lista_alunos == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %[^\n]", lista_alunos[i].nome); 
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &lista_alunos[i].nota);
    }

    printf("\n--- Lista de Alunos ---\n");
    for (int i = 0; i < n; i++) {
        printf("Aluno: %s | Nota: %.1f\n", lista_alunos[i].nome, lista_alunos[i].nota);
    }

    free(lista_alunos);

    return 0;
}