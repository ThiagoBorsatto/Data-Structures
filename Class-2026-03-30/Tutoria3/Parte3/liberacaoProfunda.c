void liberar_matriz(int **matriz, int M) {
    for (int i = 0; i < M; i++) {
        free(matriz[i]); 
    }
    free(matriz);
}