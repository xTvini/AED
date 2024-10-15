#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int valor;
    struct arvore *esquerda;
    struct arvore *direita;
}arvore;

void inserirArvoreBinaria(arvore**raiz,int num){
    if(*raiz==NULL){
        *raiz=malloc(sizeof(arvore));
        (*raiz)->esquerda=NULL;
        (*raiz)->direita=NULL;
        (*raiz)->valor=num;
    } else {
        if(num<(*raiz)->valor){
            inserirArvoreBinaria(&(*raiz)->esquerda, num);
        } else if(num>(*raiz)->valor){
            inserirArvoreBinaria(&(*raiz)->direita, num);
        }
    }
}

void posordemAdaptadoPraVc(arvore*raiz, int *maiorNumero){
    if(raiz!=NULL){
        posordem(raiz->esquerda, maiorNumero);
        posordem(raiz->direita, maiorNumero);
        if(raiz->valor>*maiorNumero){
            *maiorNumero=raiz->valor;
        }
    }
}

int main(){
    arvore*raiz=NULL;
    inserirArvoreBinaria(&raiz, 5);
    inserirArvoreBinaria(&raiz, 7);
    inserirArvoreBinaria(&raiz, 3);
    inserirArvoreBinaria(&raiz, 2);
    inserirArvoreBinaria(&raiz, 4);
    inserirArvoreBinaria(&raiz, 8);
    int maiorNumero=0;
    posordemAdaptadoPraVc(raiz, &maiorNumero);
    printf("%d", maiorNumero);
    return 0;
}