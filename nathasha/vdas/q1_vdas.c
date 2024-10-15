#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no*next;
    struct no*prev;
}no;

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

int bubbleSortV2Adaptado(no**head,no**tail){
    int troca=1,n=1,tamanho=0,quantidadeTrocas=0;
    no*aux=*head;
    do{
        tamanho++;
        aux=aux->next;
    }while(aux!=(*tail)->next);
    if(*head!=NULL){
        while(troca==1 && n<tamanho){
            troca=0;
            no *aux2=*head;
            for(int i=0;i<tamanho-1;i++){
                if(aux2->valor<aux2->next->valor){
                    int temp = aux2->next->valor;
                    aux2->next->valor = aux2->valor;
                    aux2->valor = temp;
                    troca=1;
                    quantidadeTrocas++;
                }
                aux2=aux2->next;
            }
            ++n;
        }
        return quantidadeTrocas;
    }
    return 0;
}

int main() {
    no *head = NULL;
    no *tail = NULL;
    int x, tamanhoLista, num;
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        scanf("%d", &tamanhoLista);
        head = NULL;
        tail = NULL;
        for (int j = 0; j < tamanhoLista; j++) {
            scanf("%d", &num);
            inserirDuplaListaCircular(&head, &tail, num);
        }
        int trocas = bubbleSortV2Adaptado(&head, &tail);
        printf("Optimal train swapping takes %d swaps.\n", trocas);
    }
    return 0;
}