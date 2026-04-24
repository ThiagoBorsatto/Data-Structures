#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

void inicializarFila(Fila *f) {
    f->head = NULL;
    f->tail = NULL;
    f->size = 0;
}

int inserir_triagem(Fila *f, Paciente p) {
    No* novo = (No *) malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Sem espaco na memoria, libere espaco e tente novamente\n");
        return 0;
    }
    
    novo->dadosDoPaciente = p;
    novo->previous = NULL;
    novo->next = NULL;

    if (f->head == NULL && f->tail == NULL) {
        f->head = novo;
        f->tail = novo;
    } else {
        f->tail->next = novo;
        novo->previous = f->tail;
    }
    
    f->tail = novo;
    f->size++;
    free(novo);

    return 1;
}

int inserir_emergencia(Fila *f, Paciente p) {
    No* novo = (No *) malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Sem espaco na memoria, libere espaco e tente novamente\n");
        return 0;
    }

    novo->dadosDoPaciente = p;
    novo->previous = NULL;
    novo->next = f->head;

    f->head->previous = novo;
    f->head = novo;
    f->size++;

    free(novo);

    return 1;
}

int atender_paciente(Fila *f) {
    if (f == NULL)
    {
        printf("A fila ja esta vazia\n");
        return 0;
    }
    
    No* noTemporario = (No *) malloc(sizeof(No));
    


    free(noTemporario);
    return 1;
}

void chamarPaciente(No* noPaciente) {
    printf("--- CHAMANDO PACIENTE ---\n");
    printf("Nome: %s\n", noPaciente->dadosDoPaciente.nomeDoPaciente);
    printf("Codigo: %d\n", noPaciente->dadosDoPaciente.codigoDeInscricao);
    printf("Procedimento: %s\n", noPaciente->dadosDoPaciente.codigoDoProcedimento);
    
    if (noPaciente->next == NULL && noPaciente->previous == NULL) {
        printf("\n");
        printf("Sem chamados anteriores e proximas.\n");
        printf("----------------------\n");
    } else if (noPaciente->next == NULL && noPaciente->previous != NULL) {
        printf("\n");
        printf("Paciente Anterior: %s, Inscricao: %d\n", noPaciente->previous->dadosDoPaciente.nomeDoPaciente, noPaciente->previous->dadosDoPaciente.codigoDeInscricao);
        printf("----------------------\n");
    } else if (noPaciente->next != NULL && noPaciente->previous == NULL) {
        printf("\n");
        printf("Proximo Paciente: %s, Inscricao: %d\n", noPaciente->next->dadosDoPaciente.nomeDoPaciente, noPaciente->next->dadosDoPaciente.codigoDeInscricao);
        printf("----------------------\n");
    } else {
        printf("\n");
        printf("Paciente Anterior: %s, Inscricao: %d\n", noPaciente->previous->dadosDoPaciente.nomeDoPaciente, noPaciente->previous->dadosDoPaciente.codigoDeInscricao);
        printf("Proximo Paciente: %s, Inscricao: %d\n", noPaciente->next->dadosDoPaciente.nomeDoPaciente, noPaciente->next->dadosDoPaciente.codigoDeInscricao);
        printf("-------------------------\n");
    }
}

void imprimir_auditoria(Fila *f) {
    No* noTemporario = (No *) malloc(sizeof(No));
    noTemporario = f->head;

    printf("--- FILA DO COMECO AO FIM ---\n");
    for (int i = 0; i < f->size; i++) {
        printf("--- POSSICAO NA FILA: %d ---\n", i + 1);
        printf("Nome: %s\n", noTemporario->dadosDoPaciente.nomeDoPaciente);
        printf("Codigo: %d\n", noTemporario->dadosDoPaciente.codigoDeInscricao);
        printf("Procedimento: %s\n", noTemporario->dadosDoPaciente.codigoDoProcedimento);
        printf("--------------------------\n");
        printf("\n");
        noTemporario = noTemporario->next;
    }

    noTemporario = f->tail;
    printf("--- FILA DO FIM AO COMECO ---\n");
    for (int i = 0; i < f->size; i++) {
        printf("--- POSSICAO NA FILA: %d ---\n", f->size - i);
        printf("Nome: %s\n", noTemporario->dadosDoPaciente.nomeDoPaciente);
        printf("Codigo: %d\n", noTemporario->dadosDoPaciente.codigoDeInscricao);
        printf("Procedimento: %s\n", noTemporario->dadosDoPaciente.codigoDoProcedimento);
        printf("--------------------------\n");
        printf("\n");
        noTemporario = noTemporario->previous;
    }
    free(noTemporario);
}

int quantidadeDePacientesNaFila(Fila *f) {
    return f->size;
}
