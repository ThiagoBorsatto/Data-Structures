#include <stdio.h>

struct Pessoa
{
    char nome[50];
    char sexo;
    char cpf[15];
    int dia, mes, ano;
    float peso, altura;
};

int main() {
    struct Pessoa strPessoa;

    printf("Digite seu nome: ");
    scanf("%s", strPessoa.nome);
    
    printf("Digite seu sexo (M/F): ");
    scanf(" %c", &strPessoa.sexo);
    
    printf("Digite seu CPF: ");
    scanf("%s", strPessoa.cpf);

    printf("Digite o dia do seu nascimento: ");
    scanf("%d", &strPessoa.dia);
    
    printf("Digite o mes do seu nascimento: ");
    scanf("%d", &strPessoa.mes);

    printf("Digite o ano do seu nascimento: ");
    scanf("%d", &strPessoa.ano);

    printf("Digite seu peso: ");
    scanf("%f", &strPessoa.peso);
   
    printf("Digite sua altura: ");
    scanf("%f", &strPessoa.altura);
    
    printf("Nome: %s\n", strPessoa.nome);
    printf("Sexo: %c\n", strPessoa.sexo);
    printf("CPF: %s\n", strPessoa.cpf);
    printf("Data de nascimento: %02d/%02d/%04d\n", strPessoa.dia, strPessoa.mes, strPessoa.ano);
    printf("Peso: %.2f\n", strPessoa.peso);
    printf("Altura: %.2f\n", strPessoa.altura);
    return 0;
}