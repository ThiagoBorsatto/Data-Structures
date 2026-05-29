Compilar: gcc src/main.c src/buscas.c src/arvore.c -o teste.exe
Execultar: .\teste.exe

1. Qual algoritmo teve menos comparações na maioria dos testes?
A Busca Binária.

2. A busca em árvore foi sempre melhor que a busca sequencial? Explique.
Não. Quando os dados foram inseridos já em ordem, a busca na árvore ficou muito ruim.

3. O que aconteceu com a árvore quando os valores foram inseridos em ordem crescente?
Em vez de crescer abrindo galhos para a esquerda e para a direita, ela formou uma única "linha reta" pendendo só para o lado direito.

4. Por que a altura da árvore influencia diretamente a quantidade de comparações?
Porque cada "andar" (nível) que você desce na árvore representa uma comparação que o computador faz. Se a árvore for muito alta e esticada, você terá que fazer muito mais comparações para chegar até a ponta (folha) onde o dado está escondido.

5. Por que a busca binária exige dados ordenados?
Porque ela confia na lógica de que tudo à esquerda é menor e tudo à direita é maior.

6. Qual estrutura você escolheria para um sistema que precisa buscar dados com frequência? Justifique.
Eu escolheria uma Árvore, desde que ela seja inteligente e saiba se organizar sozinha.

7. Qual é a relação entre esta atividade e o uso de índices em bancos de dados?
O banco de dados cria "índices", que funcionam exatamente como árvores invisíveis, permitindo que o sistema encontre o dado certo em milissegundos pulando caminhos, mesmo que existam milhões de registros.

8. O que uma árvore balanceada resolveria neste experimento?
Ela consertaria o problema crônico dos dados ordenados. Uma árvore balanceada percebe quando está ficando "torta" (virando uma linha reta) e faz rotações automáticas para se reorganizar, mantendo os galhos sempre curtos e bem divididos. Isso garantiria que a busca continuasse ultrarrápida em qualquer situação.