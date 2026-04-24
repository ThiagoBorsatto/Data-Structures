#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

void inicializarFila(Fila *f) {
    f->inicioDaFila = NULL;
    f->finalDaFila = NULL;
    f->quantidadeDePacientes = 0;
}

int inserirPacienteNaFila(Fila *f, Paciente p) {
    No* novo = (No *) malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Sem espaco na memoria, libere espaco e tente novamente");
        return 0;
    }
    
    novo->dadosDoPaciente = p;
    novo->proximo = NULL;

    if (f->finalDaFila == NULL)
    {
        f->inicioDaFila = novo;
    } else {
        f->finalDaFila->proximo = novo;
    }
    
    f->finalDaFila = novo;
    f->quantidadeDePacientes++;

    return 1;
}

int removerPacienteNaFila(Fila *f, Paciente* p) {
    if (f == NULL)
    {
        printf("A fila esta vazia");
        return 0;
    }

    No *noTemporario;
    noTemporario = f->inicioDaFila;
    *p = noTemporario->dadosDoPaciente;

    chamarPaciente(p);

    f->inicioDaFila = f->inicioDaFila->proximo;

    if (f->inicioDaFila == NULL)
    {
        f->finalDaFila == NULL;
    }

    free(noTemporario);
    f->quantidadeDePacientes--;
    return 1;
}

void chamarPaciente(Paciente* p) {
    printf("--CHAMANDO PACIENTE---\n");
    printf("Nome: %s\n", p->nomeDoPaciente);
    printf("Codigo: %d\n", p->codigoDeInscricao);
    printf("Procedimento: %s\n", p->codigoDoProcedimento);
}

int quantidadeDePacientesNaFila(Fila *f) {
    return f->quantidadeDePacientes;
}
