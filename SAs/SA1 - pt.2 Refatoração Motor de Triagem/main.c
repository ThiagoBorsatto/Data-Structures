#include <stdio.h>
#include "estrutura.h"

int main() {
    Fila filaDePacientes;
    Paciente paciente1, paciente2, paciente3;

    inicializarFila(&filaDePacientes);

    paciente1 = criarPaciente("Thiago Borsatto", 101, "Processo1");
    paciente2 = criarPaciente("Gustavo Borsatto", 102, "Processo2");
    paciente3 = criarPaciente("Douglas Nolli", 103, "Processo3");

    
    inserir_triagem(&filaDePacientes, paciente1);
    inserir_triagem(&filaDePacientes, paciente2);

    inserir_emergencia(&filaDePacientes, paciente3);

    imprimir_auditoria(&filaDePacientes);

    return 0;
}