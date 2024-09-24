#include <stdio.h>
#include <stdlib.h>
#include "algoritimos.h"

typedef struct no{
    int valor;
    struct no *next;
    struct no *prev;
}no;
//listaduplamente
void InserirInicioDupla(no **head, int num){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=num;
        novo->next=*head;
        novo->prev=NULL;
        if(*head!=NULL){
            (*head)->prev=novo;
        }
        *head=novo;
    }
}

void InserirFinalDupla(no **head, int num){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=num;
        novo->next=NULL;
        novo->prev=*head;
        if(*head==NULL){
            *head=novo;
            novo->prev=NULL;
        }else{
            no*aux=*head;
            while(aux->next!=NULL){
                aux=aux->next;
            }
            aux->next=novo;
            novo->prev=aux;
        }
    }
}

void InserirNoMeioDupla(no**head,int num, int prevnum){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=num;
        if(*head==NULL){
            novo->next=NULL;
            novo->prev=NULL;
            *head=novo;
        }
        else{
            no*aux=*head;
            while(aux->next!=prevnum && aux->next==NULL){
                aux=aux->next;
            }
            novo->next=aux->next;
            aux->next->prev=novo;
            aux->next=novo;
            novo->prev=aux;
        }
    }
}

void DeleteFinalDupla(no**head){
    no* aux=*head;
    if(*head==NULL){
        return;
    }
    if(aux->next==NULL){
        free(aux);
        *head=NULL;
        return;
    }
    while(aux->next!=NULL){
        aux=aux->next;
    }
    aux->prev->next=NULL;
    free(aux);
}

void DeletarInicioDupla(no**head){
    no*aux=*head;
    if(*head==NULL){
        return;
    }
    *head = aux->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(aux);
}

void printDupla(no*head){
    no*aux=head;
    while(aux!=NULL){
        printf("%d ", aux);
        aux=aux->next;
    }
    printf("\n");
}

void printfInvertido(no*head){
    no*aux=head;
    while(aux!=NULL){
        printf("%d ", aux);
        aux=aux->next;
    }
    printf("\n");
}
//pilha
void InserirPilha(no**head, int num){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=num;
        novo->next=*head;
        *head=novo;
    }
}

void DeletarPilha(no**head){
    no*aux;
    while(*head!=NULL){
        aux=*head;
        *head=(*head)->next;
        free(aux);
    }
}

void PrintPilha(no*head){
    while(head!=NULL){
        printf("%d ", head->valor);
        head=head->next;
    }
}

//fila sem tail

void inserirFila(no**head, int num){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=num;
        novo->next=NULL;
        if(*head==NULL){
            *head=novo;
        }else{
            no*aux=*head;
            while(aux->next!=NULL){
                aux=aux->next;
            }
            aux=novo;
        }
    }
}

void deleteFila(no**head){
    no*aux;
    while(*head!=NULL){
        aux=*head;
        *head=(*head)->next;
        free(aux);
    }
}

void printfFila(no*head){
    while(head!=NULL){
        printf("%d ", head->valor);
        head=head->next;
    }
}

//fila com tail

void inserirFilaComTail(no**head,no**tail, int n){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        novo->next=NULL;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
        } else {
            (*tail)->next=novo;
            *tail=novo;
        }
    }
}

void removerFilaComTail(no**head,no**tail){
    if(*head!=NULL){
        no*aux=*head;
        *head=(*head)->next;
        free(aux);
        *head=aux;
    }
    if(*head==NULL){
        *tail=NULL;
    }
}

//Lista Duplamente Circular

void inserirDuplaListaCircular(no**head,no**tail,int n){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            (*head)->prev=novo;
            (*tail)->next=novo;
        } else {
            novo->next=*head;
            (*head)->prev=novo;
            novo->prev=*tail;
            (*tail)->next=novo;
        }
    }
}