#include <stdio.h>

int main() {
    int X;
    double Y, AVERAGECONSUM;

    scanf("%d", &X);
    scanf("%lf", &Y);

    AVERAGECONSUM = X / Y;
    
    printf("%.3lf km/l\n", AVERAGECONSUM);
    
    return 0;
}