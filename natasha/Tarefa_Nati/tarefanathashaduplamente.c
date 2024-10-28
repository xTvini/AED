#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
    struct Node *ant;
} Node;

void inserir(Node **head, int num) {
    Node *novo = malloc(sizeof(Node));
    if (novo != NULL) {
        novo->valor = num;
        novo->prox = *head;
        novo->ant = NULL;
        if (*head != NULL) {
            (*head)->ant = novo;
        }
        *head = novo;
    }
}

void inserirIntercalando(Node *lista1, Node *lista2, Node **lista3, int quantidadeDePessoasNaFila) {
    Node *aux1 = lista1;
    Node *aux2 = lista2;
    int cont = 0;
    while (cont < quantidadeDePessoasNaFila) {
        if (cont % 2 != 0) {
            inserir(lista3, aux1->valor);
            aux1 = aux1->prox;
        } else {
            inserir(lista3, aux2->valor);
            aux2 = aux2->prox;
        }
        cont++;
    }
}

void inserirOrdenado(Node **head, int num) {
    Node *novo = malloc(sizeof(Node));
    if (novo != NULL) {
        novo->valor = num;
        if (*head == NULL) {
            novo->prox = NULL;
            novo->ant = NULL;
            *head = novo;
        } else if (num < (*head)->valor) {
            novo->prox = *head;
            (*head)->ant = novo;
            *head = novo;
        } else {
            Node *aux = *head;
            while (aux->prox != NULL && num > aux->prox->valor)
                aux = aux->prox;
            novo->prox = aux->prox;
            if (aux->prox != NULL) {
                aux->prox->ant = novo;
            }
            novo->ant = aux;
            aux->prox = novo;
        }
    }
}

void procurarElemento(Node *head, int x){
    Node *aux = head;
    Node *aux2 = head;
    int cont = 0,elementosAtras=0,elementrosFrente=0;
    if(head!=NULL){
        while(aux!=NULL){
            if(aux->valor==x){
                cont = 1;
                break;
            }
            aux=aux->prox;
        }
        if(cont==1){
            aux=aux2;
            while(aux!=NULL){
                elementosAtras++;
                aux=aux->ant;
            }
            while(aux2!=NULL){
                elementrosFrente++;
                aux2=aux2->prox;
            }
            printf("%d\n", elementrosFrente);
            printf("%d\n", elementosAtras);
        }
    }
}

int imprimir(Node *head) {
    while (head != NULL) {
        printf("%d ", head->valor);
        head = head->prox;
    }
    printf("\n");
}

int main() {
    Node *list = NULL, *list2 = NULL, *list3 = NULL;
    int tam1, tam2, tamtotal,item1,item2;
    scanf("%d", &tam1);
    scanf("%d", &tam2);
    tamtotal = tam1 + tam2;
    for (int i = 0; i < tam1; i++){
        scanf("%d", &item1);
        inserir(&list, item1);
    }for (int i = 0; i < tam2; i++){
        scanf("%d", &item2);
        inserir(&list2, item2);
    }
    inserirIntercalando(list, list2, &list3, tamtotal);
    imprimir(list3);
    printf("\n");
    procurarElemento(list3, 3);
    return 0;
}
