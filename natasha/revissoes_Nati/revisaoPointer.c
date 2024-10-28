#include <stdio.h>

void calcular_media (int *A, int *B){
    int media =(*A + *B)/2;
    int resto =(*A + *B)%2;
    if( *A<*B){
        *A=media;
        *B=resto;
    }
    else{
        *A=resto;
        *B=media;
    }
}

int main(void){
    int x,y;
    scanf("%d %d", &x, &y);
    calcular_media(&x, &y);
    printf("%d", x);
    printf("%d", y);
    
    return 0;
}