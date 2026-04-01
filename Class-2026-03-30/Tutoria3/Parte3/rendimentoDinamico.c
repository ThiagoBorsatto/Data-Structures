#include <stdio.h>
#include <stdlib.h>

void redimensionar_vetorDeDoisDeDois() {
    int *vetorDeDois = (int *) malloc(2 * sizeof(int));
    
    printf("Digite um valor:");
    scanf("%d", &vetorDeDois[0]); 
    
    printf("Digite um valor:");
    scanf("%d", &vetorDeDois[1]); 


    int *temp = (int *) realloc(vetorDeDois, 4 * sizeof(int));
    if (temp != NULL) {
        vetorDeDois = temp;
        printf("Digite um valor:");
        scanf("%d", &vetorDeDois[3]); 
    
        printf("Digite um valor:");
        scanf("%d", &vetorDeDois[4]); 
    }

    for(int i = 0; i < 4; i++) {
        printf("%d ", vetorDeDois[i]);
    }
    
    free(vetorDeDois);
}