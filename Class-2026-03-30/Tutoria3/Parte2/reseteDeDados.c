#include <stdio.h>

typedef struct {
    int id;
    float preco;
} Produto;

void reset_estoque(Produto *p) {
    p->id = 0;
    p->preco = 0.0f;
}

int main() {
    Produto prod = {101, 59.90};

    reset_estoque(&prod);

    printf("Produto Zerado: ID %d, Preco %.2f\n", prod.id, prod.preco);

    return 0;
}