#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_CLIENTES 6

typedef struct Cliente_ {
    int codigo;
    char nome[50];
    char telefone[20];
} Cliente;

int buscar_cliente_por_codigo(Cliente *vetorDeClientes, int tamanhaDoVetor, int codigoDoCliente) {
    Cliente cliente;
    
    for (int i = 0; i < tamanhaDoVetor; i++) {
        cliente = vetorDeClientes[i];

        if (cliente.codigo == codigoDoCliente) {
            printf("Cliente com o Codigo: %d e Nome: %s, foi encontrado na possicao: %d e no index do vetor: %d.\n", cliente.codigo, cliente.nome, i + 1, i);
            return i;
        }
    }
    printf("Cliente com o Codigo: %d, nao foi encontrado no vetor.\n", codigoDoCliente);
    return -1;
}

int buscar_cliente_por_nome(Cliente *vetorDeClientes, int tamanhaDoVetor, char nomeDoCliente[50]) {
    Cliente cliente;
    
    for (int i = 0; i < tamanhaDoVetor; i++) {
        cliente = vetorDeClientes[i];

        if (strcmp(cliente.nome, nomeDoCliente) == 0) {
            printf("Cliente com o Nome: %s e Codigo: %d, foi encontrado na possicao: %d e no index do vetor: %d.\n", cliente.nome, cliente.codigo, i + 1, i);
            return i;
        }
    }
    printf("Cliente com o Nome: %s, nao foi encontrado no vetor.\n", nomeDoCliente);
    return -1;
}

int buscar_cliente_por_telefone(Cliente *vetorDeClientes, int tamanhaDoVetor, char telefoneDoCliente[20]) {
    Cliente cliente;
    
    for (int i = 0; i < tamanhaDoVetor; i++) {
        cliente = vetorDeClientes[i];

        if (strcmp(cliente.telefone, telefoneDoCliente) == 0) {
            printf("Cliente com o Telefone: %s, Nome: %s e Codigo: %d, foi encontrado na possicao: %d e no index do vetor: %d.\n", cliente.telefone, cliente.nome, cliente.codigo, i + 1, i);
            return i;
        }
    }
    printf("Cliente com o Telefone: %s, nao foi encontrado no vetor.\n", telefoneDoCliente);
    return -1;
}

int main() {
    Cliente vetorDeClientes[TOTAL_CLIENTES] = {
        {101, "Ana","111"},
        {205, "Bruno","222"},
        {310, "Carla","333"},
        {412, "Diego","444"},
        {578, "Eduarda","555"},
        {699, "Felipe","666"}
    };
 
    char nomeDoCliente1[50] = "Diego";
    char nomeDoCliente2[50] = "diego";
    char telefoneDoCliente1[20] = "555";
    char telefoneDoCliente2[20] = "777";

    buscar_cliente_por_codigo(vetorDeClientes, TOTAL_CLIENTES, 412);

    buscar_cliente_por_nome(vetorDeClientes, TOTAL_CLIENTES, nomeDoCliente1);
    buscar_cliente_por_nome(vetorDeClientes, TOTAL_CLIENTES, nomeDoCliente2);

    buscar_cliente_por_telefone(vetorDeClientes, TOTAL_CLIENTES, telefoneDoCliente1);
    buscar_cliente_por_telefone(vetorDeClientes, TOTAL_CLIENTES, telefoneDoCliente2);

    return 0;
}