#include <stdio.h>

int main() {
    char NAME[50];
    double FIXSALARY, SALETOTAL, DISCOUNTSALARY;

    scanf("%s", &NAME);
    scanf("%lf", &FIXSALARY);
    scanf("%lf", &SALETOTAL);
    
    DISCOUNTSALARY = ((SALETOTAL * 0.15) + FIXSALARY);
    printf("TOTAL = R$ %.2lf\n", DISCOUNTSALARY);
    
    return 0;
}