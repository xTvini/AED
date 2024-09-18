#include <stdio.h>
#include <stdlib.h>

int main(){
    int numeros[5];
    int troca=1, n=1;
    for(int i = 0; i<5; i++){
        numeros[i]=rand()%100;
    }
    while(troca==1 && n<=5){
        troca=0;
        for(int i = 0; i<4; i++){
            if(numeros[i]>numeros[i+1]){
                int aux = numeros[i];
                numeros[i]=numeros[i+1];
                numeros[i+1]=aux;
                troca=1;
            }
        }
        ++n;
    }
    for(int i = 0; i<5 ; i++){
        printf(" %d ", numeros[i]);
    }
    return 0;
}