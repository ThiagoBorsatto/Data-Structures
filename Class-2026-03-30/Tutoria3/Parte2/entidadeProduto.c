typedef struct {
    int id;
    float preco;
} Produto;

void zerarValores(Produto *p) {
    p->id = 0;
    p->preco = 0.0;
}

int main() {
    Produto *p = (Produto *) malloc(sizeof(Produto));
    p->id = 101;
    p->preco = 59.90;
    zerarValores(p);
    free(p);
}