#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char valor;
    struct no *prox;
} no;

void inserirPilha(no **head, char lista) {
    no *novo = malloc(sizeof(no));
    if (novo != NULL) {
        novo->valor = lista;
        novo->prox = *head;
        *head = novo;
    }
}

char removerPilha(no **head) {
    if (*head == NULL) {
        return '\0';  
    }
    no *temp = *head;
    char valor = temp->valor;
    *head = (*head)->prox;
    free(temp);
    return valor;
}

int procurarNaPilha(char *linha) {
    int diamantes = 0;
    no *pilha = NULL;

    for (int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] == '<') {
            inserirPilha(&pilha, '<');
        } else if (linha[i] == '>') {
            if (pilha != NULL) {
                removerPilha(&pilha);
                diamantes++;
            }
        }
    }
    while (pilha != NULL) {
        removerPilha(&pilha);
    }
    return diamantes;
}

int main(void) {
    int teste;
    scanf("%d", &teste);

    while (teste!=0) {
        char linha[1001];
        scanf("%s", linha);
        int diamantes = procurarNaPilha(linha);
        printf("%d\n", diamantes);
        teste--;
    }

    return 0;
}
