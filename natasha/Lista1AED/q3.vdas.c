#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char valor[10];
    struct no *prox;
} no;

void inserirFila(no **head, char *num) {
    no *novo = malloc(sizeof(no));
    if (novo != NULL) {
        strcpy(novo->valor, num);
        novo->prox = NULL;
        if (*head == NULL) {
            *head = novo;
        } else {
            no *aux = *head;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }
}

no *retirarfila(no **head) {
    if (*head == NULL) {
        return NULL;
    }
    no *remover = *head;
    *head = (*head)->prox;
    remover->prox = NULL;
    return remover;
}

void printfila(no *head) {
    while (head->prox != NULL) {
        printf("%s ", head->valor);
        head = head->prox;
    }
    if(head->prox==NULL){
            printf("%s", head->valor);
    }
    printf("\n");
}

int main() {
    char lerNumVoo[10];
    no *menos1 = NULL;
    no *menos2 = NULL;
    no *menos3 = NULL;
    no *menos4 = NULL;
    no *tudojunto = NULL;
    int quadrante = 0;

    while(1) {
        scanf("%s", lerNumVoo);
        if (strcmp(lerNumVoo, "-1") == 0)
            quadrante = -1;
        else if (strcmp(lerNumVoo, "-2") == 0)
            quadrante = -2;
        else if (strcmp(lerNumVoo, "-3") == 0)
            quadrante = -3;
        else if (strcmp(lerNumVoo, "-4") == 0)
            quadrante = -4;
        else if (strcmp(lerNumVoo, "0") == 0)
            break;
        else {
            if (quadrante == -1)
                inserirFila(&menos1, lerNumVoo);
            else if (quadrante == -2)
                inserirFila(&menos2, lerNumVoo);
            else if (quadrante == -3)
                inserirFila(&menos3, lerNumVoo);
            else if (quadrante == -4)
                inserirFila(&menos4, lerNumVoo);
        }
    }

    while (menos1 != NULL || menos2 != NULL || menos3 != NULL || menos4 != NULL) {
        if (menos1 != NULL) {
            inserirFila(&tudojunto, retirarfila(&menos1)->valor);
        }
        if (menos3 != NULL) {
            inserirFila(&tudojunto, retirarfila(&menos3)->valor);
        }
        if (menos2 != NULL) {
            inserirFila(&tudojunto, retirarfila(&menos2)->valor);
        }
        if (menos4 != NULL) {
            inserirFila(&tudojunto, retirarfila(&menos4)->valor);
        }
    }
    printfila(tudojunto);
    return 0;
}
