#include <stdio.h>

int main() {
    int AGE, YEARS, MOUTH, DAYS, REST;

    scanf("%d", &AGE);

    YEARS = AGE / 365;
    REST = AGE % 365;
    MOUTH = REST / 30;
    DAYS = REST % 30;

    printf("%d ano(s)\n", YEARS);
    printf("%d mes(es)\n", MOUTH);
    printf("%d dia(s)\n", DAYS);
    
    return 0;
}