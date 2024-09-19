#include <stdio.h>
#include <stdlib.h>

int recursividade(int n){
    printf("%d ", n*2);
    if(n==0){
        return 0;
    }
    return (n*2)+recursividade(n-1);
}

int main(){
    int x;
    scanf("%d", &x);
    if(x<0){
        return 1;
    }

    printf("= %d", recursividade(x));
    return 0;
}