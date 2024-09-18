#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no*prox;
    struct no*ant;
}no;

void inserir_lista_circular_dupla(no**head,no**tail,int num){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=num;
        if(*head==NULL){
            //caso so tenha um nó
            *head=novo;
            *tail=novo;
            (*tail)->prox=novo;
            (*head)->ant=novo;
        }else{
            novo->prox=*head;
            (*head)->ant=novo;
            *head = novo;
            (*tail)->prox=novo;
            novo->ant=*tail;
        }
    }
}
void remover_cirular_dupla(no**head,no**tail){
    if(*head!=NULL){   
        no*aux=*head;
        if(*head==*tail){
            *head=NULL;
            *tail=NULL;
        }else{
            *head=aux->prox;
            (*head)->ant=*tail;
            (*tail)->prox=*head;
        }
        free(aux);
    }
}

void remover_final_circular_dupla(no**head,no**tail){
    if(*head!=NULL){
        if(*head==*tail){
            *head=NULL;
            *tail=NULL;
        }else{
            *tail=(*tail)->ant;
            free((*tail)->prox);
            (*head)->ant=*tail;
            (*tail)->prox=*head;
        }
    }
}

void imprimir_circular_dupla(no*head,no*tail){
    do{
        printf("%d ", head->valor);
        *head=*head->prox;
    }while(head!=tail->prox);
}

void imprimir_contrario_circular_dupla(no*head,no*tail){
    do{
        printf("%d ", tail->valor);
        *tail=*tail->ant;
    }while(head!=tail->prox);
}