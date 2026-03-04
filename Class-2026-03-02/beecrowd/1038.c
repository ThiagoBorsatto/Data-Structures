#include <stdio.h>

int main() {
    int X, Y;
    double TOTALVALUE;

    scanf("%d %d", &X, &Y);

    if (X == 1) {
        TOTALVALUE = Y * 4.00;
        printf("Total: R$ %.2lf\n", TOTALVALUE);
    } 
    else if (X == 2) {
        TOTALVALUE = Y * 4.50;
        printf("Total: R$ %.2lf\n", TOTALVALUE);
    } 
    else if (X == 3) {
        TOTALVALUE = Y * 5.00;
        printf("Total: R$ %.2lf\n", TOTALVALUE);
    } 
    else if (X == 4) {
        TOTALVALUE = Y * 2.00;
        printf("Total: R$ %.2lf\n", TOTALVALUE);
    } 
    else if (X == 5) {
        TOTALVALUE = Y * 1.50;
        printf("Total: R$ %.2lf\n", TOTALVALUE);
    } 
    else {
        printf("Fora de intervalo\n");
    }

    return 0;
}