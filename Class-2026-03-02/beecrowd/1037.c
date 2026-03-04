#include <stdio.h>
#include <math.h>

int main() {
    double NUMBER;

    scanf("%lf", &NUMBER);

    if (NUMBER >= 0.0 && NUMBER <= 25.00) {
        printf("Intervalo [0,25]\n");
    } else if (NUMBER > 25.00 && NUMBER <= 50.00) {
        printf("Intervalo (25,50]\n");
    } else if (NUMBER > 50.00 && NUMBER <= 75.00) {
        printf("Intervalo (50,75]\n");
    } else if (NUMBER > 75.00 && NUMBER <= 100.00) {
        printf("Intervalo (75,100]\n");
    } else {
        printf("Fora de intervalo\n");
    }

    return 0;
}