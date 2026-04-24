#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

void inicializarFila(Fila *fila) {
    fila->head = NULL;
    fila->tail = NULL;
    fila->size = 0;
}

int inserir_triagem(Fila *fila, Paciente paciente) {
    No* novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Sem espaco na memoria, libere espaco e tente novamente\n");
        return 0;
    }
    
    novo->dadosDoPaciente = paciente;
    novo->previous = NULL;
    novo->next = NULL;

    if (fila->head == NULL && fila->tail == NULL) {
        fila->head = novo;
        fila->tail = novo;
    } else {
        fila->tail->next = novo;
        novo->previous = fila->tail;
    }
    
    fila->tail = novo;
    fila->size++;

    return 1;
}

int inserir_emergencia(Fila *fila, Paciente paciente) {
    No* novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Sem espaco na memoria, libere espaco e tente novamente\n");
        return 0;
    }

    novo->dadosDoPaciente = paciente;
    novo->previous = NULL;
    novo->next = fila->head;

    fila->head->previous = novo;
    fila->head = novo;
    fila->size++;

    return 1;
}

int atender_paciente(Fila *fila) {
    No* noTemporario;

    if (fila == NULL) {
        printf("A fila ja esta vazia\n");
        return 0;
    }
    
    noTemporario = fila->head;
    chamarPaciente(noTemporario);

    fila->head = noTemporario->next;
    fila->size--;
    
    free(noTemporario);
    noTemporario = NULL;
    return 1;
}

int remover_paciente_id(Fila *fila, int id) {
    No* noTemporario = (No *) malloc(sizeof(No));
    
    if (fila == NULL) {
        printf("A fila ja esta vazia\n");
        return 0;
    }
    
    noTemporario = fila->head;
    for (int i = 0; i < fila->size; i++) {
        if (noTemporario->dadosDoPaciente.codigoDeInscricao == id) {
            noTemporario->previous->next = noTemporario->next;
            noTemporario->next->previous = noTemporario->previous;
            fila->size--;
            
            printf("Paciente com o ID %d foi removido com sucesso\n", id);
            printf("\n");

            free(noTemporario);
            noTemporario = NULL;
            return 1;
        }
        noTemporario = noTemporario->next;
    }

    free(noTemporario);
    noTemporario = NULL;
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
        printf("\n");
    } else if (noPaciente->next == NULL && noPaciente->previous != NULL) {
        printf("\n");
        printf("Paciente Anterior: %s, Inscricao: %d\n", noPaciente->previous->dadosDoPaciente.nomeDoPaciente, noPaciente->previous->dadosDoPaciente.codigoDeInscricao);
        printf("----------------------\n");
        printf("\n");
    } else if (noPaciente->next != NULL && noPaciente->previous == NULL) {
        printf("\n");
        printf("Proximo Paciente: %s, Inscricao: %d\n", noPaciente->next->dadosDoPaciente.nomeDoPaciente, noPaciente->next->dadosDoPaciente.codigoDeInscricao);
        printf("----------------------\n");
        printf("\n");
    } else {
        printf("\n");
        printf("Paciente Anterior: %s, Inscricao: %d\n", noPaciente->previous->dadosDoPaciente.nomeDoPaciente, noPaciente->previous->dadosDoPaciente.codigoDeInscricao);
        printf("Proximo Paciente: %s, Inscricao: %d\n", noPaciente->next->dadosDoPaciente.nomeDoPaciente, noPaciente->next->dadosDoPaciente.codigoDeInscricao);
        printf("-------------------------\n");
        printf("\n");
    }
}

void imprimir_auditoria(Fila *fila) {
    No* noTemporario = fila->head;

    printf("--- FILA DO COMECO AO FIM ---\n");
    for (int i = 0; i < fila->size; i++) {
        printf("POSSICAO NA FILA: %d\n", i + 1);
        printf("Nome: %s\n", noTemporario->dadosDoPaciente.nomeDoPaciente);
        printf("Codigo: %d\n", noTemporario->dadosDoPaciente.codigoDeInscricao);
        printf("Procedimento: %s\n", noTemporario->dadosDoPaciente.codigoDoProcedimento);
        printf("--------------------------\n");
        printf("\n");
        noTemporario = noTemporario->next;
    }

    noTemporario = fila->tail;
    printf("--- FILA DO FIM AO COMECO ---\n");
    for (int i = 0; i < fila->size; i++) {
        printf("POSSICAO NA FILA: %d\n", fila->size - i);
        printf("Nome: %s\n", noTemporario->dadosDoPaciente.nomeDoPaciente);
        printf("Codigo: %d\n", noTemporario->dadosDoPaciente.codigoDeInscricao);
        printf("Procedimento: %s\n", noTemporario->dadosDoPaciente.codigoDoProcedimento);
        printf("--------------------------\n");
        printf("\n");
        noTemporario = noTemporario->previous;
    }
}

int quantidadeDePacientesNaFila(Fila *fila) {
    return fila->size;
}
