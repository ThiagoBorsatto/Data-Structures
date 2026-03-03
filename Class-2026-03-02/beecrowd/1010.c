#include <stdio.h>

int main() {
    int CODE1, CODE2, UNITS1, UNITS2;
    double PRICE1, PRICE2, TOTALPRICE;

    scanf("%d %d %lf", &CODE1, &UNITS1, &PRICE1);
    scanf("%d %d %lf", &CODE2, &UNITS2, &PRICE2);
    TOTALPRICE = (UNITS1 * PRICE1) + (UNITS2 * PRICE2);
    
    printf("VALOR A PAGAR: R$ %.2lf\n", TOTALPRICE);
    
    return 0;
}