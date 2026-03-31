typedef struct {
    int id;
    float preco;
} Produto;

void reset_estoque(Produto *p) {
    p->id = 0;
    p->preco = 0.0;
}

void exemplo_produto() {
    Produto *p = (Produto *) malloc(sizeof(Produto));
    p->id = 101;
    p->preco = 59.90;
    reset_estoque(p);
    free(p);
}