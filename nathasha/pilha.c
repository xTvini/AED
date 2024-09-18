#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[32];
    struct Aluno *prox;
}Aluno;

void insert(Aluno **pilha, char name[]) {
    Aluno *novo = malloc(sizeof(Aluno));

    strcpy(novo->nome, name);
    novo->prox=*pilha;
    *pilha=novo;
}

void imprimir_ultimo(Aluno *pilha){
    while(pilha!=NULL){
        if(pilha->prox==NULL){
            printf("%s\n", pilha->nome);
        }
        pilha=pilha->prox;
    }
}

void imprimir_par(Aluno *pilha){
    int cont=0;
    while(pilha!=NULL){
        if(cont%2==0){
            printf("%s\n", pilha->nome);
        }
        pilha=pilha->prox;
        cont++;
    }
}

int main(void) {
    Aluno *topo = NULL;
    char nomePessoal[32];
    int x;
    scanf("%d", &x);
    for(int i = 0; i<x; i++){
        scanf("%s", nomePessoal);
        insert(&topo, nomePessoal);
    }
    printf("\n");
    imprimir_par(topo);
    printf("\n");
    imprimir_ultimo(topo);

}
