Thiago Borsatto Dutra

Exercício 1 — Cadastro de alunos com árvore binária de busca
    Era para criar um programa em C que armazene alunos em uma árvore binária de busca.
Compilar: gcc cadastroDeAlunos.c -o teste.exe
Execultar: .\teste.exe
Dificuldades: Precisava colocar o Aluno dentro de uma turma, então foi um pouco difícil de definir as novas comparações no código. 

Exercício 2 — Contando elementos da árvore
    A partir de uma árvore binária de busca de inteiros, implemente funções para calcular:
Compilar:  gcc contandoElementosDaArvore.c -o teste.exe
Execultar: .\teste.exe
Dificuldades: Foi bem complicado para entender as mudanças para contar os valores, precisei de ajudar de IAs e outras coisas, e ainda assim ficou confuso.

Exercício 3 — Menor e maior valor da árvore
Implemente duas funções:
    int menorValor(No *raiz);
    int maiorValor(No *raiz);
Compilar: gcc menorEMaiorValorDaArvore.c -o teste.exe
Execultar: .\teste.exe
Dificuldades: A parte de como a estrutura se comporta foi confuso, definir quem começa e que termina.
Desafio Extra: Não precisa ir na árvore toda por que sabemos que o maior valor vai estar mais a direita e o menor no nó mais a esquerda.

Exercício 4 — Removendo um valor da árvore
    Implemente a remoção de um nó em uma árvore binária de busca.
    A função deve lidar com os três casos principais:
Compilar: gcc removendoUmValorDaArvore.c -o teste.exe
Execultar: .\teste.exe
Dificuldades: Construção da lógica, e do buscar nos diferentes níveis.

Exercício 5 — Comparando busca sequencial e busca em árvore
    Crie um programa que compare duas formas de busca:
    busca sequencial em vetor;
    busca em árvore binária de busca.
Compilar: gcc comparandoBuscaSequencialEBuscaEmArvore.c -o teste.exe
Execultar: .\teste.exe
Dificuldades: Mesma coisa de antes, a comparação e a busca sequencial e busca em árvore
