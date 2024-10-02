#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
    struct no *ant;
} Node;

void inserirListaDuplamenteCircular(Node** head, Node** tail, int n) {
    Node* novo = malloc(sizeof(Node));
    if (novo != NULL) {
        novo->valor = n;
        if (*head == NULL) {
            *head = novo;
            *tail = novo;
            (*head)->ant = novo;
            (*tail)->prox = novo;
        } else {
            novo->prox = *head;
            (*head)->ant = novo;
            novo->ant = *tail;
            (*tail)->prox = novo;
            *tail = novo;
        }
    }
}

void removerInicioListaDuplamenteCircular(Node** head, Node** tail) {
    if (*head != NULL) {
        Node* aux = *head;
        if (*head == *tail) {
            *head = NULL;
            *tail = NULL;
        } else {
            *head = aux->prox;
            (*tail)->prox = *head;
            (*head)->ant = *tail;
        }
        free(aux);
    }
}

void removerFinalListaDuplamenteCircular(Node** head, Node** tail) {
    if (*head != NULL) {
        Node* aux = *tail;
        if (*head == *tail) {
            *head = NULL;
            *tail = NULL;
        } else {
            *tail = aux->ant;
            (*head)->ant = *tail;
            (*tail)->prox = *head;
        }
        free(aux);
    }
}

void multiplicacao(Node** head, Node** tail) {
    if(*head==*tail){
        printf("Tamanho da lista é insuficiente :(");
    } else {
        while (*head != NULL && *tail != NULL) {
            int cabeca = (*head)->valor;
            int rabo = (*tail)->valor;
            int multiplicacao = cabeca * rabo;
            printf("%d por %d é %d\n",cabeca,rabo,multiplicacao);
            removerInicioListaDuplamenteCircular(head, tail);
            removerFinalListaDuplamenteCircular(head, tail);
        }
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Inserindo valores na lista
    inserirListaDuplamenteCircular(&head, &tail, 1);
    inserirListaDuplamenteCircular(&head, &tail, 2);
    inserirListaDuplamenteCircular(&head, &tail, 3);
    inserirListaDuplamenteCircular(&head, &tail, 4);
    inserirListaDuplamenteCircular(&head, &tail, 5);
    inserirListaDuplamenteCircular(&head, &tail, 6);
    inserirListaDuplamenteCircular(&head, &tail, 7);
    inserirListaDuplamenteCircular(&head, &tail, 8);
    

    printf("Resultado das multiplicações:\n");
    multiplicacao(&head, &tail);

    return 0;
}
