#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int ID, nivelDeUrgencia;
    char nomeDoTecnico[50];
    struct No *proximo;
} No;

typedef struct {
    No *topo;
    int quantidadeDeChamados;
} Chamados;

void inicializar(Chamados *p) {
    p->topo = NULL;
    p->quantidadeDeChamados = 0;
}

int push(Chamados *p, int ID, int nivelDeUrgencia, const char *nomeDoTecnico) {
    No *novoChamado = (No *) malloc(sizeof(No));
    if (novoChamado == NULL) {
        printf("Sem memoria disponivel, libere espaco e tente novamente");
        return 0;
    }

    novoChamado->ID = ID;
    novoChamado->nivelDeUrgencia = nivelDeUrgencia;
    strcpy(novoChamado->nomeDoTecnico, nomeDoTecnico);
    novoChamado->proximo = p->topo;
    p->quantidadeDeChamados++;

    printf("ID: %d\n",novoChamado->ID);
    printf("Nivel de Urgencia: %d\n",novoChamado->nivelDeUrgencia);
    printf("Nome do Tecnico: %s\n",novoChamado->nomeDoTecnico);
    if (p->topo != NULL) {
        printf("ID do proximo: %d\n",novoChamado->proximo->ID);
    }
    printf("Quantidade de chamados: %d\n",p->quantidadeDeChamados);
    printf("\n");

    p->topo = novoChamado;

    return 1;
}

int filtroDeChamdosUrgentes(Chamados *p, Chamados *pm) {
    No *noTemporario;
    noTemporario = p->topo;

    for (int i = 0; i < p->quantidadeDeChamados; i++) {
        
        if (noTemporario->nivelDeUrgencia == 5) {
            pm->topo = noTemporario;
            pm->quantidadeDeChamados++;

            printf("ID do chamado urgente: %d\n", pm->topo->ID);
        }
        noTemporario = noTemporario->proximo;
        p->topo = noTemporario;
    }
    
    printf("\n");
    return 0;
}

int main() {
    Chamados chamados;
    Chamados prioridadeMaxima;

    inicializar(&chamados);
    inicializar(&prioridadeMaxima);

    push(&chamados, 10, 5, "Thiago");
    push(&chamados, 20, 4, "Gustavo");
    push(&chamados, 30, 5, "Douglas");

    filtroDeChamdosUrgentes(&chamados, &prioridadeMaxima);
    return 0;
}