#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
    struct no *ant;
}no;

void inserirListaDuplamente(no**head,no**tail,int n){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            (*head)->ant=novo;
            (*tail)->prox=novo;
        } else { 
            novo->prox=*head;
            (*head)->ant=novo;
            novo->ant=*tail;
            (*tail)->prox=novo;
        }
    }
}