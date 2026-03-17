#include <stdio.h>

struct Pessoa
{
    char nome[50];
    char sexo;
    char cpf[15];
    int dia, mes, ano;
    float peso, altura;
};

void cadastrarPessoa(struct Pessoa *p) {
    printf("Digite seu nome: ");
    scanf("%s", p->nome);
    
    printf("Digite seu sexo (M/F): ");
    scanf(" %c", &p->sexo);
    
    printf("Digite seu CPF: ");
    scanf("%s", p->cpf);

    printf("Digite o dia do seu nascimento: ");
    scanf("%d", &p->dia);
    
    printf("Digite o mes do seu nascimento: ");
    scanf("%d", &p->mes);

    printf("Digite o ano do seu nascimento: ");
    scanf("%d", &p->ano);

    printf("Digite seu peso: ");
    scanf("%f", &p->peso);
   
    printf("Digite sua altura: ");
    scanf("%f", &p->altura);
}

void mostrarOsDados(struct Pessoa *p) {
    printf("=== Cadastro Pessoas ===\n");
    printf("Nome: %s\n", p->nome);
    printf("Sexo: %c\n", p->sexo);
    printf("CPF: %s\n", p->cpf);
    printf("Data de nascimento: %02d/%02d/%04d\n", p->dia, p->mes, p->ano);
    printf("Peso: %.2f\n", p->peso);
    printf("Altura: %.2f\n", p->altura);
}

int main() {
    struct Pessoa pessoa;

    cadastrarPessoa(&pessoa);
    mostrarOsDados(&pessoa);

    return 0;
}