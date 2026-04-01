#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
} Usuario;

int main() {
    Usuario *usuario = (Usuario *) malloc(sizeof(Usuario));
    if (usuario == NULL) {
        return 1;
    }

    char nome[100];
    printf("Digite o nome do usuario: ");
    scanf(" %[^\n]", nome); 

    usuario->nome = (char *) malloc((strlen(nome) + 1) * sizeof(char));

    if (usuario->nome != NULL) {
        strcpy(usuario->nome, nome);
    }

    free(usuario->nome); 

    return 0;
}