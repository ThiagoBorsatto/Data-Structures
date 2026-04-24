#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "requisicao.h"

typedef struct No
{
    Paciente dadosDoPaciente;
    struct No* proximo;
} No;

typedef struct
{
    No* inicioDaFila;
    No* finalDaFila;
    int quantidadeDePacientes;
} Fila;

void inicializarFila(Fila *f);
int inserirPacienteNaFila(Fila *f, Paciente p);
int removerPacienteNaFila(Fila *f, Paciente* p);
void chamarPaciente(Paciente* p);
int quantidadeDePacientesNaFila(Fila* f);
void destruirFila(Fila* f);

#endif