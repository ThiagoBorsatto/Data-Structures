#include <stdio.h>

int main() {
    float media1;
    float media2;
    float media3;
    float mediaTotal;

    media1 = 6.4;
    media2 = 7.8;
    media3 = 4.6;
    mediaTotal = (media1 + media2 + media3)/3;

    if (mediaTotal > 6.0)
    {
        printf("A media total e maior que 6.0!");
    }
    else
    {
        printf("A media e menor que 6.0!");
    }
    
    
    return 0;
}
