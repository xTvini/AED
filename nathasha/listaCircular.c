#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* prox;
}no;

void inserirInicio(no**head,no**tail,int num){
    no *novo = malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor = num;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
        }else{
            novo->prox=*head;
            *head=novo;
        }(*tail)->prox=*head;
    }
}

void inserirFinal(no **head,no**tail, int num){
    no *novo= malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=num;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            novo->prox=*head;
        }else{
            novo->prox=(*tail)->prox;
            (*tail)->prox=novo;
            *tail=novo;
        }
    }
}

void removerFinal(no**head,no**tail){
    if(*head!=NULL){
        no *aux = *head;
        if(*head==*tail){
            *head=NULL;
            *tail=NULL;
            free(aux);
        }
        else{
            while(aux->prox!=*tail){
                aux=aux->prox;
            }
            aux->prox=(*tail)->prox;
            free(*tail);
            *tail=aux;
        }
    }
}

void remover(no**head,no**tail){
    if(*head!=NULL){
        no *aux = *head;
        if(*head==*tail){
            *head=NULL;
            *tail=NULL;
        }
        else{
            *head=(*head)->prox;
            (*tail)->prox=*head;
        }
        free(aux);
    }
}

int main(void){
    return 0;
}