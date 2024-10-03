#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* next;
    struct no* prev;
} Node;

void inserirDuplamenteCircular(Node** head, Node** tail, int n) {
    Node* novo = malloc(sizeof(Node));
    if (novo != NULL) {
        novo->valor = n;
        if (*head == NULL) {
            *head = novo;
            *tail = novo;
            (*head)->prev = novo; 
            (*tail)->next = novo;
        } else {
            novo->next = *head;
            (*head)->prev = novo;
            novo->prev = *tail;
            (*tail)->next = novo;
            *head = novo;
        }
    }
}

void sequencia(Node* head, Node* tail) {
    if (head != NULL) {
        int cont = 0;
        Node* aux1 = head;
        Node*aux2=tail;
        do {
            cont++;
            aux1 = aux1->next;
        } while (aux1 != head);

        if (cont < 3) {
            printf("Tamanho da lista é insuficiente :(\n");
        } else {
            aux1 = head;
            do {
                if (aux1->next->valor % 2 != 0 && aux1->next->next->valor % 2 != 0 || aux1->prev->valor % 2 != 0 && aux1->prev->prev->valor % 2 != 0) {
                    printf("%d\n", aux1->valor);
                }
                aux1 = aux1->next;
            } while (aux1 != head);
        }
    }
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &n);
        inserirDuplamenteCircular(&head, &tail, n);
    }
    sequencia(head, tail);
    return 0;
}
