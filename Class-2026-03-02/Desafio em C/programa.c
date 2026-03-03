#include <stdio.h>

double media(double media1, double media2, double media3);

int main() {
    double media1, media2, media3;
    char nome[50];
    int idade, idadeValida = 0, vetorNumeros[5], maiorNumero, somaDoVetor = 0;

    printf("Digite seu nome: \n");
    scanf("%s", &nome);

    printf("Digite sua idade: \n");
    while (idadeValida == 0)
    {
        scanf("%d", &idade);
        if (idade >= 0) {
            printf("Idade valida!\n");
            idadeValida = 1;
        } else {
            printf("Idade invaida, digite sua idade novamente: \n");
        }
    }
    
    printf("Digite sua primeira nota: \n");
    scanf("%lf", &media1); 
    printf("Digite sua segunda nota: \n");
    scanf("%lf", &media2); 
    printf("Digite sua terceira nota: \n");
    scanf("%lf", &media3);

    media(media1, media2, media3);

    printf("Digite 5 numeros inteiros: \n");
    for (int i = 0; i <= 4; i++)
    {
        printf("numero %d: ", i + 1);
        scanf("%d", &vetorNumeros[i]);

        if(i == 0 || vetorNumeros[i] > maiorNumero)
            maiorNumero = vetorNumeros[i];

        somaDoVetor += vetorNumeros[i];
    }
    printf("Soma do vetor: %d\n", somaDoVetor);
    return 0;
}

double media(double media1, double media2, double media3) {
    double mediaTotal;
    mediaTotal = (media1 + media2 + media3)/3;
    if (mediaTotal >= 7)
    {
        printf("Voce foi Aprovado!\n");
    } else
    {
        printf("Voce foi Reprovado!\n");
    }
}