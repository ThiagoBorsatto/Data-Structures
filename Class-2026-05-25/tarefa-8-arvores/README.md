# Tarefa 8: Árvore Binária de Busca

Thiago Borsatto Dutra   

Apenas a atividade 10 e 11 tem códigos para execultar, já que as funções para o seu funcionamento foi gerada no exercício de 1 até 9.
O código foi compilado usando `gcc nome_do_arquivo.c -o saida_para_execucao.exe`, para a execução basta colocar no cmd `.\teste.exe`

Sobre as atividades:
1. Observe a árvore abaixo e responder algumas perguntas:

        10
       /  \
      5    20
     / \     \
    3   7     30

2. Desenho da árvore binária de busca formada pela inserção dos seguintes valores:
    8, 4, 12, 2, 6, 10, 14

3. Criação da estrutura Nó:
    typedef struct No {
        int valor;
        struct No *esquerda;
        struct No *direita;
    } No;

4. Função para criar e colocar valor dentro da estrutura de Nó

5. Responder algumas perguntas em relação a inserção de uma árvore binária

6. Completar os campos em brancos de uma função de inserir em árvore binária

7. Explicar como a árvore binária direciona seus valores para alocação

8. Implementação da função de busca.

9. Implementação da função de imprimir os valores em ordem crescente: esquerda -> raiz -> direita

10. Criação do um programa básico que usando os códigos das atividades anteriores, para ver a execução das funções use o CMD para viajar até a pasta do arquivo e execute o comando `.\teste.exe`, já deixei meus teste compilados:
    crie uma árvore vazia;
    insira os valores 50, 30, 70, 20, 40, 60, 80;
    imprima os valores em ordem crescente;
    busque o valor 40;
    busque o valor 90;
    mostre na tela se cada valor foi encontrado ou não.

11. Criação e execução das funções, para ver a execução das funções use o CMD para viajar até a pasta do arquivo e execute o comando `.\teste.exe`, já deixei meus teste compilados:
    No* inserir(No *raiz, int valor);
    int buscar(No *raiz, int valor);
    No* remover(No *raiz, int valor);
    void emOrdem(No *raiz);
    void liberarArvore(No *raiz);

Uma árvore binária faz a inserção de dados comparando o valor que vai ser adcionado com o ROOT/RAIZ, se o valor que eu estou tentando adicionar for menor que o do ROOT o valor vai ser adicionado na subarvore esquerda do ROOT, caso seja maior o valor para o lado direito.