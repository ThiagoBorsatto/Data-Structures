#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t umGb = 1024 * 1024 * 1024;
    char *testeDeMemoria = (char *) malloc(umGb);

    

    if (testeDeMemoria == NULL)
    {
        printf("Nao foi possivel alocar memoria!");
        return 1;
    }
    
    free(testeDeMemoria);
    return 0;
}