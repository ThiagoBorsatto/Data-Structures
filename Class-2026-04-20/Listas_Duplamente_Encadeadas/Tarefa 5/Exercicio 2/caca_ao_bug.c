// 'atual' é o paciente que será removido do meio da lista
// free(atual);
// atual->previous->next = atual->next;
// atual->next->previous = atual->previous;
// list->size--;

// Qual é o erro fatal neste código? O que acontecerá com a lista na memória (Heap) ao executar essas linhas nessa exata ordem? Reescreva o trecho corrigindo o problema. 
// Resposta:
// O erro foi que os código está usando a função de libarar a memória antes de fazer suas operações.
// Fazendo que a função acesse algo que não deveria.
// A solução é liberar a memória no final da operação.

// atual->previous->next = atual->next;
// atual->next->previous = atual->previous;
// list->size--;
// free(atual);