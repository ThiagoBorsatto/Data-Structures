int** alocar_matriz(int M, int N) {
    int **matriz = (int **) malloc(M * sizeof(int *));

    for (int i = 0; i < M; i++) {
        matriz[i] = (int *) malloc(N * sizeof(int));
    }
    
    return matriz;
}
