#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct Ponto {
    float x, y;
};

Ponto* ponto_criar(float x, float y) {
    Ponto *p = (Ponto *) malloc(sizeof(Ponto));
    if (p) { p->x = x; p->y = y; }
    return p;
}

float ponto_distancia(Ponto *p1, Ponto *p2) {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

void ponto_destruir(Ponto *p) {
    free(p);
}