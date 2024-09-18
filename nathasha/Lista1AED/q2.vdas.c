#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char nome[100];
    struct no *prox;
    struct no *ant;
}no;

void inserirfinal(no **head, char *giu) {
  no *novo = (no*)malloc(sizeof(no));  
  if (novo != NULL){
    strcpy(novo->nome,giu);   
    novo->prox = NULL;

    if(*head == NULL){
      novo->ant=NULL;
      *head=novo;
    }else{      
      no *aux = *head;
      while(aux->prox !=NULL)
        aux = aux->prox;

      aux->prox=novo;
      novo->ant =aux;
    }

  }
}
void inserir(no**head,char *pedro){
    no*novo=malloc(sizeof(no));
    no*aux = *head;
    while(aux!=NULL){
        if(strcmp(aux->nome,pedro)==0){
            return;
        }
        aux=aux->prox;
    }
    if(novo!=NULL){
        strcpy(novo->nome,pedro);
        novo->ant=NULL;
        novo->prox=NULL;
        aux=*head;
        no*aux2=NULL;
        while(aux!=NULL && strcmp(aux->nome, pedro)<0){
            aux2=aux;
            aux=aux->prox;
        }
        novo->prox=aux;
        novo->ant=aux2;
        if(aux2!=NULL){
            aux2->prox=novo;
        }else{
            *head=novo;
        }if(aux!=NULL){
            aux->ant=novo;
        }
    }
}

void imprimir(no*head){
    no*aux=head;
    while(aux!=NULL){
        printf("%s\n", aux->nome);
        aux=aux->prox;
    }
}

no *ganhador(no*head){
    no*ganhou=NULL;
    no*aux=head;
    while(aux!=NULL){
        if(ganhou==NULL || strlen(aux->nome)>strlen(ganhou->nome))
            ganhou=aux;
        aux=aux->prox;
    }
    return ganhou;
}

int main(){
    char opcao[4],nome[100];
    no*putaquepariu=NULL;
    no*listaAmigos = NULL;
    no*listaInimigos = NULL;
    while(1){
        scanf("%s", &nome);
        if(strcmp(nome,"FIM")==0)
            break;
        scanf("%s", &opcao);
        if(strcmp(opcao,"NO")==0)
            inserir(&listaInimigos,nome);
        else if(strcmp(opcao,"YES")==0){
            inserir(&listaAmigos,nome);
            inserirfinal(&putaquepariu, nome);
            
        }

    }
    imprimir(listaAmigos);
    imprimir(listaInimigos);

    no* vencedor = ganhador(putaquepariu);
    printf("\nAmigo do Habay:\n%s\n", vencedor->nome);
    return 0;
}