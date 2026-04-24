#ifndef REQUISICAO_H
#define REQUISICAO_H

typedef struct
{
    char nomeDoPaciente[40];
    int codigoDeInscricao;
    char codigoDoProcedimento[10];
} Paciente;

Paciente criarPaciente(const char* nome, int codigoDeInscricao, const char* codigoDoProcedimento);

#endif