#include <stdio.h>

int main() {
    int NUMBER, HOURS;
    double PERHOURS, SALARY;

    scanf("%d", &NUMBER);
    scanf("%d", &HOURS);
    scanf("%lf", &PERHOURS);
    
    SALARY = HOURS * PERHOURS;
    printf("NUMBER = %d\n", NUMBER);
    printf("SALARY = U$ %.2lf\n", SALARY);
    
    return 0;
}