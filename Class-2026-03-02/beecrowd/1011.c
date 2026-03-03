#include <stdio.h>

int main() {
    double R, VOLUMESPHERE, RCUBE, pi=3.14159;

    scanf("%lf", &R);

    VOLUMESPHERE = (4/3.0) * pi * (R * R * R);
    
    printf("VOLUME = %.3lf\n", VOLUMESPHERE);
    
    return 0;
}