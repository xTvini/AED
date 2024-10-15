#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nome[31];
    int ficha;
    struct Node *next;
    struct Node *prev;
} Node;

void inserirFinal(Node **head, Node **tail, char *nome, int ficha) {
    Node *novo = (Node *)malloc(sizeof(Node));
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

void deletar(Node **head, Node **tail, Node *node) {
    if (*head != NULL) {
        if (node == *head && node == *tail) {
            *head = NULL;
            *tail = NULL;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            if (node == *head) {
                *head = node->next;
            }
            if (node == *tail) {
                *tail = node->prev;
            }
        }
        free(node);
    }
}

char* acharVencedor(Node **head, Node **tail, int tamanhoDaFila) {
    Node *atual = *head;
    int N = tamanhoDaFila;

    while (N > 1) {
        int valor = atual->ficha;
        Node *proximoExcluir = atual;

        // Move o ponteiro para a esquerda ou para a direita
        if (valor % 2) {
            for (int j = 0; j < valor; ++j) {
                proximoExcluir = proximoExcluir->prev;
            }
        } else {
            for (int j = 0; j < valor; ++j) {
                proximoExcluir = proximoExcluir->next;
            }
        }

        // Atualiza o atual para o próximo que vai sobreviver
        atual = (valor % 2) ? proximoExcluir->next : proximoExcluir->prev;

        // Remove o nó excluído
        deletar(head, tail, proximoExcluir);
        N--;
    }
    return (*head)->nome;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int tamanhoDaFila;
    char nome[31];
    int ficha;

    while (1) {
        scanf("%d", &tamanhoDaFila);
        if (tamanhoDaFila == 0) break;

        head = NULL; // Reinicializa a lista
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