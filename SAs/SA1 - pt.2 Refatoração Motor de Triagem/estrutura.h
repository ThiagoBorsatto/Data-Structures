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

void inicializarFila(Fila *f);
void chamarPaciente(No *noPaciente);
void imprimir_auditoria(Fila *f);

int inserir_triagem(Fila *f, Paciente p);
int inserir_emergencia(Fila *f, Paciente p);
int atender_paciente(Fila *f);
int quantidadeDePacientesNaFila(Fila* f);

#endif