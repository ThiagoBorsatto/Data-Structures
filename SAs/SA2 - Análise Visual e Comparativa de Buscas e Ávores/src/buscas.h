#ifndef BUSCAS_H
#define BUSCAS_H

int buscaSequencial(int *vetor, int tamanho, int valor, long long *comparacoes);
int buscaBinaria(int *vetor, int tamanho, int valor, long long *comparacoes);
void embaralharVetor(int *vetor, int tamanho);

#endif