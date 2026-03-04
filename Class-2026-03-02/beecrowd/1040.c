#include <stdio.h>

int main() {
    double N1, N2, N3, N4, AVERAGE, EXAMESCORE;

    scanf("%lf %lf %lf %lf", &N1, &N2, &N3, &N4);

    AVERAGE = ((2 * N1) + (3 * N2) + (4 * N3) + (1 * N4)) / 10;
    printf("Media: %.1lf\n", AVERAGE);

    if (AVERAGE >= 7.0)
    {
        printf("Aluno aprovado.\n");
    }
    else if (AVERAGE < 5.0)
    {
        printf("Aluno reprovado.\n");
    }
    else if (AVERAGE >= 5.0 && AVERAGE <= 6.9)
    {
        printf("Aluno em exame.\n");
        scanf("%lf", &EXAMESCORE);

        printf("Nota do exame: %.1lf\n", EXAMESCORE);
        AVERAGE = (AVERAGE + EXAMESCORE) / 2;

        if (AVERAGE >= 5.0)
        {
            printf("Aluno aprovado.\n");
            printf("Media final: %.1lf\n", AVERAGE);
        }
        else if (AVERAGE < 4.9)
        {
            printf("Aluno reprovado.\n");
            printf("Media final: %.1lf\n", AVERAGE);
        }
    }

    return 0;
}