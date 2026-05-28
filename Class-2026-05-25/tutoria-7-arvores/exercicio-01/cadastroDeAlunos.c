#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Aluno {
    int matricula;
    char nome[50];
    float nota;
} Aluno;

typedef struct Turma {
    Aluno *aluno;
    struct Turma *esquerda;
    struct Turma *direita;
} Turma;

Turma* criarTurma(Aluno *aluno) {
    Turma* noDaTurma = (Turma *)malloc(sizeof(Turma));

    noDaTurma->aluno = aluno;
    noDaTurma->esquerda = NULL;
    noDaTurma->direita = NULL;

    return noDaTurma;
}

Aluno* criarAluno(int matricula, char nome[], float nota) {
    Aluno* aluno = (Aluno *)malloc(sizeof(Aluno));

    aluno->matricula = matricula; 
    strcpy(aluno->nome, nome);
    aluno->nota = nota;

    return aluno;
}

Turma* inserir(Turma *turma, Aluno *aluno) {
    if (turma == NULL) {
        printf("Inserindo aluno %d - %s\n",aluno->matricula, aluno->nome);
        return criarTurma(aluno);
    }

    if (aluno->matricula < turma->aluno->matricula) {
        turma->esquerda = inserir(turma->esquerda, aluno);
    } else if (aluno->matricula > turma->aluno->matricula) {
        turma->direita = inserir(turma->direita, aluno);
    }

    return turma;
}

int buscar(Turma *turma, int matricula) {
    if (turma == NULL) {
        printf("Nao encontramos o aluno(a) com a matricula: %d\n", matricula);
        return 0;
    }
    
    if (turma->aluno->matricula == matricula) {
        printf("Encontramos o aluno(a) com a matricula: %d\n", matricula);
        return 1;
    }
    
    if (matricula < turma->aluno->matricula) {
        return buscar(turma->esquerda, matricula);
    }
    
    if (matricula > turma->aluno->matricula) {
        return buscar(turma->direita, matricula);
    }
}

void emOrdem(Turma* turma) {
    if (turma == NULL) {
        return;
    }

    emOrdem(turma->esquerda);

    printf("%d - %s - Nota: %.1f\n", turma->aluno->matricula, turma->aluno->nome, turma->aluno->nota);

    emOrdem(turma->direita);
}

int main() {
    Turma* turmaC303 = NULL;

    Aluno* ana = criarAluno(102, "Ana", 9.0);
    Aluno* bruno = criarAluno(55, "Bruno", 8.5);
    Aluno* carla =  criarAluno(180, "Carla", 7.5);

    printf("--- Insercao dos alunos ---\n");
    turmaC303 = inserir(turmaC303, ana);
    turmaC303 = inserir(turmaC303, bruno);
    turmaC303 = inserir(turmaC303, carla);
    printf("\n");
    
    printf("Buscar Alunos com a matricula 55 e a 100\n");
    buscar(turmaC303, 55);
    buscar(turmaC303, 100);
    printf("\n");

    printf("--- Alunos em ordem ---\n");
    emOrdem(turmaC303);

    return 0;
}