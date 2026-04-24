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
int inserir_triagem(Fila *f, Paciente p);
int removerPacienteNaFila(Fila *f, Paciente* p);
void chamarPaciente(No *noPaciente);
int quantidadeDePacientesNaFila(Fila* f);
void destruirFila(Fila* f);

#endif