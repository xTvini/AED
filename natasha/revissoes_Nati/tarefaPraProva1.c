#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} Node;

void inserirCircular(Node** head, Node** tail, int n) {
    Node* novo = malloc(sizeof(Node));
    if (novo != NULL) {
        novo->valor = n;
        if (*head == NULL) {
            *head = novo;
            *tail = novo;
            (*tail)->prox = *head;
        } else {
            novo->prox = *head;
            (*tail)->prox = novo;
            *head = novo;
        }
    }
}

void multiplicacao(Node* head, Node* tail) {
    if (head == tail) {
        printf("Tamanho da lista é insuficiente :(\n");
    } else {
        Node*aux=head;
        Node*aux2=head->prox;
        while (1) {
            int primeiro = aux->valor;
            int segundo = aux->prox->valor;
            printf("%d por %d é %d\n", primeiro, segundo, primeiro*segundo);
            aux=aux2->prox;
            if(aux==head){
                break;
            }
            aux2=aux->prox;
            if(aux2==head){
                break;
            }
        }
         if (aux != head && aux->prox == head) {
        printf("%d por %d é %d\n", aux->valor, aux->valor, aux->valor * aux->valor);
    }
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 11; i >= 1; i--) {
        inserirCircular(&head, &tail, i);
    }

    printf("Resultado das multiplicações:\n");
    multiplicacao(head, tail); 
    printf("\n");
    return 0;
}
