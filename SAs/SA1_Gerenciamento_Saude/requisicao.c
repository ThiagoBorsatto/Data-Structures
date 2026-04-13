#include "requisicao.h"
#include <string.h>

Paciente criarPaciente(const char* nomeDoPaciente, int codigoDeInscricao, const char* codigoDoProcedimento) {
    Paciente p;
    strncpy(p.nomeDoPaciente, nomeDoPaciente, 39);
    p.nomeDoPaciente[39] = '\0';

    p.codigoDeInscricao = codigoDeInscricao;

    strncpy(p.codigoDoProcedimento, codigoDoProcedimento, 9);
    p.codigoDoProcedimento[9] = '\0';
    return p;
}
