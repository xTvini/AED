#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node*prox;
}Node;


void inserirFila(Node**head,Node**tail, int n){
    Node*novo=malloc(sizeof(Node));
    if(novo!=NULL){
        novo->valor=n;
        novo->prox=NULL;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
        } else {
            (*tail)->prox=novo;
            *tail=novo;
        }
    }
}

void troca(Node **head1, Node **tail1, Node **head2, Node **tail2){
    if(head1 != NULL && head2 != NULL){
        Node*aux1=*head1;
        Node*aux2=*head2;
        *head1=aux1->prox;
        *head2=aux2->prox;
        aux1->prox=*head2;
        aux2->prox=*head1;
        *head1=aux2;
        *head2=aux1;
    }
}

void printfFila(Node*head){
    while(head!=NULL){
        printf("%d ", head->valor);
        head=head->prox;
    }
    printf("\n");
}

int main(){
    Node*cabeca1 =NULL;
    Node*cabeca2=NULL;
    Node*rabo1=NULL;
    Node*rabo2=NULL;
    for(int i = 1; i<10; i++){
        inserirFila(&cabeca1, &rabo1, i);
        inserirFila(&cabeca2, &rabo2, i*100);
    }
    printfFila(cabeca1);
    printfFila(cabeca2);
    troca(&cabeca1,&rabo1,&cabeca2,&rabo2);
    printf("\n");
    printfFila(cabeca1);
    printfFila(cabeca2);
    return 0;
}