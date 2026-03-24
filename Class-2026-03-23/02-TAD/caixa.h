#ifndef CAIXA_H
#define CAIXA_H

typedef struct Caixa_ Caixa;

Caixa* criar_caixa(int valor_inicial);
void destruir_caixa(Caixa* c);
void escrever_valor(Caixa* c, int valor);
int ler_valor(Caixa* c);

#endif