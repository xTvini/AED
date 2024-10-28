#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int valor;
    struct no *next;
} Node;

void inserir_fila(Node** fila, int num) {
    Node *novo_fila = malloc(sizeof(Node));
    if (novo_fila != NULL) {
        novo_fila->valor = num;
        novo_fila->next = NULL;
        if (*fila == NULL) {
            *fila = novo_fila;
        } else {
            Node* aux = *fila;
            while (aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = novo_fila;
        }
    }
}

void inserir_pilha(Node** pilha, int num) {
    Node *novo_pilha = malloc(sizeof(Node));
    if (novo_pilha != NULL) {
        novo_pilha->valor = num;
        novo_pilha->next = *pilha;
        *pilha = novo_pilha;
    }
}

void concatenar_fila(Node **fila1, Node **fila2, Node** pilha1) {
    Node* aux;
    while (*fila1 != NULL) {
        inserir_pilha(pilha1, (*fila1)->valor);
        aux = *fila1;
        *fila1 = (*fila1)->next;
        free(aux);
    }
    while (*fila2 != NULL) {
        inserir_pilha(pilha1, (*fila2)->valor);
        aux = *fila2;
        *fila2 = (*fila2)->next;
        free(aux);
    }
}

void exibir_pilha(Node* pilha) {
    Node* aux = pilha;
    while (aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->next;
    }
    printf("\n");
}

int main(void) {
    //não entendi o pq de ter q botar um do lado do outro (perguntar para a professora)
    Node *FL2=NULL;
    Node *FL1=NULL;
    Node *PL1=NULL;

    int numero;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numero);
        inserir_fila(&FL1, numero);
        scanf("%d", &numero);
        inserir_fila(&FL2, numero);
    }
    concatenar_fila(&FL1, &FL2, &PL1);
    exibir_pilha(PL1);
    return 0;
}
