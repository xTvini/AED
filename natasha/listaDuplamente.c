#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;
}Node;

void inserir_antes(Node **head,Node **tail, int valor){
    Node *novo = malloc(sizeof(Node));
    if(novo!=NULL){
        novo->valor=valor;
        novo->ant=NULL;
        novo->prox=*head;
        if(*head!=NULL){
            (*head)->ant=novo;
        }else{
            *tail = novo;
        }
        *head=novo;
    }
}
void inserir_depois(Node **head, Node **tail, int valor){
    Node *novo = malloc(sizeof(Node));
    if(novo!=NULL){
        novo->valor = valor;
        novo->prox =NULL;
        novo->ant = *tail;
        if(*tail!=NULL){
            (*tail)->prox=novo;
        }
        else{
            *head=novo;
        }
        *tail=novo;
    }
}
void imprimir(Node *head){
    while(head!=NULL){
        printf("%d ", head->valor);
        head=head->prox;
    }

}

void imprimirContrario(Node **head){
    Node *current = *head;
    while(current->prox!=NULL){
        current = current->prox;
    }
    while(current!=NULL){
        printf("%d ", current->valor);
        current=current->ant;
    }
}

void remover_inicio(Node **head){
    if(*head!=NULL){
        Node *aux = *head;
        *head = (*head)->prox;
        free(aux);
        if(*head!=NULL){
            (*head)->ant=NULL;
        }
    }
}

void remover_final(Node **head, Node **tail){
    Node *aux = *tail;
    if(*tail==NULL){
        return;
    }
    if(aux->ant==NULL){
        *head==NULL;
        *tail==NULL;
    }
    else{
        *tail=aux->ant;
        (*tail)->prox=NULL;
    }
    free(aux);
}

int main(void){
    Node *inicio = NULL;
    Node *inicio2 = NULL;
    Node *final =NULL;
    Node *final2 =NULL;
    int x;
    for(int i = 0; i<3; i ++){
        inserir_antes(&inicio,&final, i);
    }
    for(int i = 0; i<3; i++){
        inserir_depois(&inicio2,&final2, i*2);
    }
    imprimir(inicio2);
    printf("\n");
    imprimirContrario(&inicio);
    printf("\n");
    remover_inicio(&inicio);
    imprimir(inicio);
    printf("\n");
    remover_final(&inicio, &final);
    imprimir(inicio);
}