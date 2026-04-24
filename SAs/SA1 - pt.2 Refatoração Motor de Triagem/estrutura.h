#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "requisicao.h"

typedef struct No
{
    Paciente dadosDoPaciente;
    struct No* previous;
    struct No* next;
} No;

typedef struct
{
    No* head;
    No* tail;
    int size;
} Fila;

void inicializarFila(Fila *fila);
void chamarPaciente(No *noPaciente);
void imprimir_auditoria(Fila *fila);

int inserir_triagem(Fila *fila, Paciente paciente);
int inserir_emergencia(Fila *fila, Paciente paciente);
int atender_paciente(Fila *fila);
int remover_paciente_id(Fila *fila, int id);
int quantidadeDePacientesNaFila(Fila* fila);

#endif