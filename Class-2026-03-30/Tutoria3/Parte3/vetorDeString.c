void vetor_cidades() {
    int n = 3;

    char *cidades = (char *) malloc(n * sizeof(char *));
    char buffer[100];

    for (int i = 0; i < n; i++) {
        printf("Cidade %d: ", i + 1);
        scanf(" %[^\n]", buffer);
        cidades[i] = (char *) malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(cidades[i], buffer);
    }
    
    for (int i = 0; i < n; i++) {
        free(cidades[i]);
    }
    
    free(cidades);
}