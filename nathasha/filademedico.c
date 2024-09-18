#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    struct Node *next;
}Node;

void insert(Node** fila, char name[]){
    Node* novo = malloc(sizeof(Node));
    if(fila!=NULL){
        strcpy(novo->nome,name);
        novo->next=NULL;
        if(*fila == NULL){
            *fila=novo;
        }else{
            Node* aux = *fila;
            while(aux->next!=NULL){
                aux = aux->next;
            }
            aux->next=novo;
        }
    }   
}

Node *removido(Node** fila){
    Node* remover = NULL;
    if(*fila!=NULL){
        remover = *fila;
        *fila = remover->next;
    }
    return remover;
}

void print(Node* fila){
    while(fila!=NULL){
        printf("\n%s", fila->nome);
        fila = fila->next;
    }
}
int main(){
    Node*seguirALista,*tirado,*fila = NULL;
    char pessoa[30], nomePosicao[30];
    int op, atendidos=0;
    do{
        printf("\n\nDigite\n1 pra adicianr paciente\n2 pra atender o paciente\n3 para consultar a posicao do paciente\n4 para exibir a quantidade de pacientes atendidos\n0 para sair\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                scanf("%s", pessoa);
                insert(&fila, pessoa);
                break;
            case 2:
                tirado=removido(&fila);
                if(tirado!=NULL){
                printf("paciente de nome %s foi atendido!\n", tirado->nome);
                free(tirado);
                atendidos++;
                }
                break;
            case 3:
                seguirALista = fila;
                printf("qual o nome do paciente?\n");
                scanf("%s", nomePosicao);
                if(seguirALista==NULL){
                    printf("a lista ta vazia\n");
                }
                else{
                    int posicao = 1;
                    while(seguirALista!=NULL){
                        if(strcmp(nomePosicao, seguirALista->nome)==0){
                            printf("o paciente %s esta na posicao %d da lista\n", nomePosicao, posicao);
                            break;
                        }
                         seguirALista=seguirALista->next;
                         posicao++;
                    }
                }
                break;
            case 4:
                printf("a quantidade de pacientes atendidos foi de: %d\n", atendidos);
                break;
            default:
                printf("MEU QUERIDO DIGITE PELO AMOR DE DEUS DE 0-4");
            }
        }while(op!=0);
    return 0;
    }
