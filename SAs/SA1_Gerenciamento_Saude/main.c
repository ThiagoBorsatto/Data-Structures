#include <stdio.h>
#include "estrutura.h"

int main() {
    Fila filaDePacientes;
    Paciente paciente1, paciente2;

    inicializarFila(&filaDePacientes);

    paciente1 = criarPaciente("Thiago Borsatto", 101, "Processo1");
    paciente2 = criarPaciente("Gustavo Borsatto", 102, "Processo2");
    
    inserirPacienteNaFila(&filaDePacientes, paciente1);
    inserirPacienteNaFila(&filaDePacientes, paciente2);

    printf("Tamanho da fila: %d\n", quantidadeDePacientesNaFila(&filaDePacientes));
    printf("\n");

    removerPacienteNaFila(&filaDePacientes, &paciente1);
    printf("\n");

    printf("Tamanho da fila: %d\n", quantidadeDePacientesNaFila(&filaDePacientes));
    printf("\n");

    destruirFila(&filaDePacientes);
    return 0;
}