#include <stdio.h>

int main() {
    int hours, speed;
    double liters, basicCon=12.0;

    scanf("%d", &hours);
    scanf("%d", &speed);

    liters = (hours * speed) / basicCon;
    
    printf("%.3lf\n", liters);
    
    return 0;
}