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

    if (f->head == NULL && f->tail == NULL)
    {
        f->head = novo;
        f->tail = novo;
        printf("Paciente inserido no HEAD da fila\n");
        chamarPaciente(novo);
    } else {
        f->tail->next = novo;
        novo->previous = f->tail;
        printf("Paciente inserido no TAIL da fila\n");
        chamarPaciente(novo);
    }
    
    f->tail = novo;
    f->size++;

    int numero = quantidadeDePacientesNaFila(f);
    printf("Pessoas na fila: %d\n", numero);
    printf("\n");

    return 1;
}

// int removerPacienteNaFila(Fila *f, Paciente* p) {
//     if (f == NULL)
//     {
//         printf("A fila ja esta vazia\n");
//         return 0;
//     }

//     No *noTemporario;
//     noTemporario = f->inicioDaFila;
//     *p = noTemporario->dadosDoPaciente;

//     chamarPaciente(p);

//     f->inicioDaFila = f->inicioDaFila->proximo;

//     if (f->inicioDaFila == NULL)
//     {
//         f->finalDaFila == NULL;
//     }

//     free(noTemporario);
//     f->quantidadeDePacientes--;
//     return 1;
// }

void chamarPaciente(No* noPaciente) {
    printf("--CHAMANDO PACIENTE---\n");
    printf("Nome: %s\n", noPaciente->dadosDoPaciente.nomeDoPaciente);
    printf("Codigo: %d\n", noPaciente->dadosDoPaciente.codigoDeInscricao);
    printf("Procedimento: %s\n", noPaciente->dadosDoPaciente.codigoDoProcedimento);
    
    if (noPaciente->next == NULL && noPaciente->previous == NULL) {
        printf("\n");
        printf("Sem chamados anteriores e proximas, fila esta vazia.\n");
        printf("\n");
    } else if (noPaciente->next == NULL && noPaciente->previous != NULL) {
        printf("\n");
        printf("Paciente Anterior: %s, Inscricao: %d\n", noPaciente->previous->dadosDoPaciente.nomeDoPaciente, noPaciente->previous->dadosDoPaciente.codigoDeInscricao);
        printf("\n");
    } else {
        printf("\n");
        printf("Paciente Anterior: %s, Inscricao: %d\n", noPaciente->previous->dadosDoPaciente.nomeDoPaciente, noPaciente->previous->dadosDoPaciente.codigoDeInscricao);
        printf("Proximo Paciente: %s, Inscricao: %d\n", noPaciente->next->dadosDoPaciente.nomeDoPaciente, noPaciente->next->dadosDoPaciente.codigoDeInscricao);
        printf("\n");
    }
}

int quantidadeDePacientesNaFila(Fila *f) {
    return f->size;
}
