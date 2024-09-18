#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node* next;
    struct Node* ant;
}Node;

void inserir_inicio(Node **head, int num){
    Node *novo = malloc(sizeof(Node));
    if(novo!=NULL){
        novo->valor=num;
        novo->next=*head;
        novo->ant = NULL;
        if(*head!=NULL){
            (*head)->ant=novo;
        }
        *head = novo;
    } 
}

void inserir_meio(Node **head, int valor, int ant){
    Node *novo = malloc(sizeof(Node));
    if(novo!=NULL){
        novo->valor = valor;
        if(head==NULL){
            novo->next = NULL;
            novo->ant =NULL;
            *head = novo;
        }else{
            Node *aux = *head;
            while(aux->valor!=ant && aux->next!=NULL){
                aux = aux->next;
            }
            novo->next = aux->next;
            aux->next->ant = novo;
            novo->ant=aux;
            aux->next = novo;
        }
    }
}

void inserir_fim(Node **head, int num){
    Node *novo = malloc (sizeof(Node));
    if(novo!=NULL){
        novo->valor=num;
        novo->next=NULL;
        if(head==NULL){
            *head = novo;
            novo->ant=NULL;
        }else{
            Node *aux = *head;
            while(aux->next!=NULL){
                aux = aux->next;
            }
            aux->next = novo;
            novo->ant=aux;
        }
    }

}

void print(Node *head){
    while(head!=NULL){
        printf("%d ", head->valor);
        head = head->next;
    }
    printf("\n");
}

void remover_final(Node **head){
    Node *aux = *head;
    if(*head==NULL){
        return;
    }
    if(aux->next==NULL){
        free(aux);
        *head = NULL;
        return;
    }
    while(aux->next!=NULL){
        aux=aux->next;
    }
    aux->ant->next=NULL;
    free(aux);
}   

int main(){
    Node *head =NULL;
    int x;
    scanf("%d", &x);
    for(int i = 0;i<x;i++){
        inserir_inicio(&head, i);
    }
    print(head);
    for(int i = 0;i<x;i++){
        inserir_fim(&head, i*2);
    }
    print(head);
    int numero;
    scanf("%d", &numero);
    inserir_meio(&head, numero, 2);
    print(head);
    remover_final(&head);
    print(head);

}