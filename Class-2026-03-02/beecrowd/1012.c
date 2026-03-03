#include <stdio.h>

int main() {
    double A, B, C, pi = 3.14159, TRIANGLE, AREAC, AREAT, SQUARE, RECTANGLE;

    scanf("%lf %lf %lf", &A, &B, &C);
    
    TRIANGLE = (A * C)/2;
    AREAC = pi * (C * C);
    AREAT = ((A + B) / 2) * C;
    SQUARE = B * B;
    RECTANGLE = A * B;

    printf("TRIANGULO: %.3lf\n", TRIANGLE);
    printf("CIRCULO: %.3lf\n", AREAC);
    printf("TRAPEZIO: %.3lf\n", AREAT);
    printf("QUADRADO: %.3lf\n", SQUARE);
    printf("RETANGULO: %.3lf\n", RECTANGLE);
    
    return 0;
}