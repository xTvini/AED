#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[31];
    int ficha;
    struct no *next;
    struct no *prev;
} no;

void inserirFinal(no **head, no **tail, char *nome, int ficha) {
    no *novo = (no *)malloc(sizeof(no));
    if (novo != NULL) {
        strcpy(novo->nome, nome);
        novo->ficha = ficha;

        if (*head == NULL) {
            *head = novo;
            *tail = novo;
            novo->next = novo;
            novo->prev = novo;
        } else {
            novo->next = *head;
            novo->prev = *tail;
            (*tail)->next = novo;
            (*head)->prev = novo;
            *tail = novo;
        }
    }
}

void deletar(no **head, no **tail, no *nDelete) {
    if (*head != NULL) {
        if (nDelete == *head && nDelete == *tail) {
            *head = NULL;
            *tail = NULL;
        } else {
            nDelete->prev->next = nDelete->next;
            nDelete->next->prev = nDelete->prev;
            if (nDelete == *head) {
                *head = nDelete->next;
            }
            if (nDelete == *tail) {
                *tail = nDelete->prev;
            }
        }
        free(nDelete);
    }
}

char* acharVencedor(no **head, no **tail, int tamanhoDaFila) {
    no *atual = *head;
    int N = tamanhoDaFila;
    while (N > 1) {
        int valor = atual->ficha;
        no *proximoExcluir = atual;
        if (valor % 2 == 0) {
            for (int j = 0; j < valor; j++) {
                proximoExcluir = proximoExcluir->next;
            }
        } else {
            for (int j = 0; j < valor; j++) {
                proximoExcluir = proximoExcluir->prev;
            }
        }t
        atual = (valor % 2 == 0) ? proximoExcluir->prev : proximoExcluir->next;
        deletar(head, tail, proximoExcluir);
        N--;
    }
    return (*head)->nome;
}

int main() {
    no *head = NULL;
    no *tail = NULL;
    int tamanhoDaFila;
    char nome[31];
    int ficha;
    while (1) {
        scanf("%d", &tamanhoDaFila);
        if (tamanhoDaFila == 0) break;
        head = NULL;
        tail = NULL;
        for (int i = 0; i < tamanhoDaFila; i++) {
            scanf("%s %d", nome, &ficha);
            inserirFinal(&head, &tail, nome, ficha);
        }
        char *vencedor = acharVencedor(&head, &tail, tamanhoDaFila);
        printf("Vencedor(a): %s\n", vencedor);
    }
    return 0;
}