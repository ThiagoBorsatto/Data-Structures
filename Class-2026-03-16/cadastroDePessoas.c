#include <stdio.h>

int main() {
    
    char nome[50];
    char sexo;
    char cpf[15];
    int dia, mes, ano;
    float peso, altura;

    printf("Digite seu nome:\n");
    scanf("%s", nome);
    
    printf("Digite seu sexo (M/F):\n");
    scanf(" %c", &sexo);
    
    printf("Digite seu CPF:\n");
    scanf("%s", cpf);

    printf("Digite o dia do seu nascimento:\n");
    scanf("%d", &dia);
    
    printf("Digite o mes do seu nascimento:\n");
    scanf("%d", &mes);

    printf("Digite o ano do seu nascimento:\n");
    scanf("%d", &ano);

    printf("Digite seu peso:\n");
    scanf("%f", &peso);
   
    printf("Digite sua altura:\n");
    scanf("%f", &altura);
    
    printf("Nome: %s\n", nome);
    printf("Sexo: %c\n", sexo);
    printf("CPF: %s\n", cpf);
    printf("Data de nascimento: %02d/%02d/%04d\n", dia, mes, ano);
    printf("Peso: %.2f\n", peso);
    printf("Altura: %.2f\n", altura);
    return 0;
}