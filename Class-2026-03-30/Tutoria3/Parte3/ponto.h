#ifndef PONTO_H
#define PONTO_H

typedef struct Ponto Ponto;

Ponto* ponto_criar(float x, float y);
float ponto_distancia(Ponto *p1, Ponto *p2);
void ponto_destruir(Ponto *p);

#endif