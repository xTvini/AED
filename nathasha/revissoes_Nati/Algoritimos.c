#include <stdio.h>
#include <stdlib.h>
#include "algoritimos.h"

typedef struct no{
    int valor;
    struct no *next;
    struct no *prev;
}no;

//INICIO ASSUNTO AV1

//LISTA DUPLAMENTE

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
            novo->prev=*tail;
            (*head)->prev=novo;
            (*tail)->next=novo;
            *head=novo;
        }
    }
}

void inserirFinalDuplaListaCircular(no**head,no**tail,int n){
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
            novo->prev=*tail;
            (*tail)->next=novo;
            (*head)->prev=novo;
            *tail=novo;

        }
    }
}

void inserirMeioAntesDuplaListaCircular(no**head,no**tail,int n,int dps){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            (*tail)->next=novo;
            (*head)->prev=novo;
        }else{
            no*aux=*head;
            do{
                if(aux->valor==dps){
                    novo->prev=aux->prev;
                    novo->next=aux;
                    aux->prev->next=novo;
                    aux->prev=novo;
                    return;
                }
                aux=aux->next;
            }while(aux!=*head);
        }
    }
}

void inserirMeioDepoisDuplaListaCircular(no**head,no**tail,int n, int ant){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            (*head)->prev=*tail;
            (*tail)->next=*head;
        } else {
            no*aux=*head;
            if((*tail)->valor==ant){
                novo->next=*head;
                novo->prev=*tail;
                (*tail)->next=novo;
                *tail=novo;
                (*head)->prev=*tail;
            }
            do{
                if(aux->valor==ant){
                    novo->next=aux->next;
                    novo->prev=aux;
                    aux->next->prev=novo;
                    aux->next=novo;
                }
                aux=aux->next;
            }while(aux!=*head);
        }
    }
}

void deletarNumeroEspecificoDuplaListaCircular(no**head,no**tail,int nDelete){
    if(*head!=NULL){
        no*aux=*head;
        if(*head==*tail && (*head)->valor==nDelete){
            free(*head);
            *tail=NULL;
            *head=NULL;
            return;
        }
        do{
            if(aux->valor==nDelete){
                if(aux==*head){
                    *head=aux->next;
                    (*tail)->next=*head;
                    (*head)->prev=*tail;
                }
                if(aux==*tail){
                    *tail=aux->prev;
                    (*tail)->next=*head;
                    (*head)->prev=*tail;
                }
                aux->prev->next=aux->next;
                aux->next->prev=aux->prev;
                free(aux);
                return;
            } else {
                aux=aux->next;
            }
        }while(aux!=*head);
    }
}

void deletarInicioDuplaListaCircular(no**head,no**tail){
    if(*head!=NULL){
        if(*head==*tail){
            free(*head);
            *head=NULL;
            *tail=NULL;
        } else {
            no*aux=*head;
            *head=aux->next;
            (*head)->prev=*tail;
            (*tail)->next=*head;
            free(aux);
        }
    }
}

void deletarFinalDuplaListaCircular(no**head,no**tail){
    if(*head!=NULL){
        if(*head==*tail){
            free(*head);
            *head=NULL;
            *tail=NULL;
        } else {
            no*aux=*tail;
            *tail=aux->prev;
            (*tail)->next=*head;
            (*head)->prev=*tail;
            free(aux);
        }
    }
}

void printDuplaListaCircular(no*head,no*tail){
    if(head!=NULL){
        do{
            printf("%d ", head->valor);
            head=head->next;
        }while(head!=tail->next);
        printf("\n");
    }
}

void printInvertidoDuplaListaCircular(no*head,no*tail){
    if(head!=NULL){
        do{
            printf("%d",tail->valor);
            tail=tail->prev;
        }while(tail!=head->prev);
    }
}

//Lista Simplesmente Circular


void inserirInicioListaSimplesCircular(no**head,no**tail,int n){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            (*tail)->next=*head;
        } else {
            novo->next=*head;
            *head=novo;
            (*tail)->next=*head;
        }
    }
}

void inserirMeioListaSimplesCircular(no**head,no**tail,int n, int pos){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            (*tail)->next=*head;
        } else {
            no*aux=*head;
            if((*head)->valor==pos){
                novo->next=*head;
                *head=novo;
                (*tail)->next=*head;
                return;
            }
            do{
                if(aux->next->valor==pos){
                    novo->next=aux->next;
                    aux->next=novo;
                    return;
                }
                aux=aux->next;
            }while(aux!=*head);
        }
    }
}

void inserirFinalListaSimplesCircular(no**head,no**tail,int n){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            (*tail)->next=*head;
        } else {
            novo->next=*head;
            (*tail)->next=novo;
            *tail=novo;
        }
    }
}

void deleteInicioListaSimplesCircular(no**head,no**tail){
    if(*head!=NULL){
        if(*head==*tail){
            free(*head);
            *head=NULL;
            *tail=NULL;
        } else {
            no*aux=*head;
            *head=aux->next;
            (*tail)->next=*head;
            free(aux);
        }
    }
}

void deleteFinalListaSimplesCircular(no**head,no**tail){
    if(*head!=NULL){
        if(*head==*tail){
            free(*head);
            *head=NULL;
            *tail=NULL;
        } else {
            no*aux=*head;
            do{
                if(aux->next==*tail){
                    free(*tail);
                    *tail=aux;
                    (*tail)->next=*head;
                    return;
                }
                aux=aux->next;
            }while(aux!=*head);
        }
    }
}

void printListaSimplesCircular(no*head,no*tail){
    if(head!=NULL){
        do{
            printf("%d ", head->valor);
            head=head->next;
        }while(head!=tail->next);
    }
}

//Insertion Sort

void insertionSort(int *arr, int tamanho,int num){
    for(int i=1;i<tamanho;i++){
        int j=i;
        while(arr[j]>arr[j-1] && j>0){
            int aux = arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=aux;
            --j;
        }
    }
}

//Bubble Sort V0

void bubbleSortV0(int *arr,int tamanho, int n){
    for(int i=1;i<tamanho;i++){
        for(int j=0;j<tamanho-1;j++){
            if(arr[j]>arr[j+1]){
                int aux=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=aux;
            }
        }
    }
}

void bubbleSortV1(int *arr, int tamanho, int n){
    for(int i=1; i<tamanho;i++){
        for(int j=tamanho-1; j>=i; j--){
            if(arr[j]>arr[j-1]){
                int aux=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=aux;
            }
        }
    }
}

void bubbleSortV2(int *arr, int tamanho, int n){
    int troca=1, n=1;
    while(n<=tamanho && troca==1){
        troca = 0;
        for(int i=0;i<tamanho-1;i++){
            if(arr[i]>arr[i+1]){
                int aux = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = aux;
                troca=1;
            }
        }
        ++n;
    }
}

//FIM ASSUNTO AV1

//ARVORE BINARIA
typedef struct arvore{
    int valor;
    struct arvore *direita;
    struct arvore *esquerda;
}arvore;

void inserirNaARaizBinario(arvore**raiz,int chave){
    if(*raiz==NULL){
        *raiz=(arvore*)malloc(sizeof(arvore));
        (*raiz)->esquerda=NULL;
        (*raiz)->direita=NULL;
        (*raiz)->valor=chave;
    } else {
        if(chave<(*raiz)->valor){
            inserirNaARaizBinario(&(*raiz)->esquerda, chave);
        }else if(chave>(*raiz)->valor){
            inserirNaARaizBinario(&(*raiz)->direita, chave);
        }
    }
}

void printArvore(arvore*raiz){
    if(raiz!=NULL){
        printArvore(raiz->esquerda);
        printArvore(raiz->direita);
        printf("%d", raiz->valor);
    }
}