#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int valor;
    struct no* next;
} no;

void inserir(no** fila, int num) {
    no *novo = malloc(sizeof(no));
    if (novo != NULL) {
        novo->valor = num;
        novo->next = NULL;

        if (*fila == NULL) {
            *fila = novo;
        } else {
            no* aux = *fila;
            while (aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = novo;
        }
    }
}

no* removido(no** fila) {
    no* remover = NULL;
    if (*fila != NULL) {
        remover = *fila;
        *fila = remover->next;
    }
    return remover;
}

void print(no* fila) {
    while (fila != NULL) {
        printf("\n%d", fila->valor);
        fila = fila->next;
    }
}

int main() {
    int N, M, K;

    scanf("%d %d %d", &N, &M, &K);

    no *fila1 = NULL, *fila2 = NULL;

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        inserir(&fila1, num);
    }

    for (int i = 0; i < M; i++) {
        int num;
        scanf("%d", &num);
        inserir(&fila2, num);
    }

    no *filaResultado = NULL;

    if (K == 1) {
        while (fila2 != NULL || fila1 != NULL) {
            if (fila2 != NULL) {
                inserir(&filaResultado, removido(&fila2)->valor);
            }
            if (fila1 != NULL) {
                inserir(&filaResultado, removido(&fila1)->valor);
            }
        }
    } else {
        while (fila1 != NULL || fila2 != NULL) {
            if (fila1 != NULL) {
                inserir(&filaResultado, removido(&fila1)->valor);
            }
            if (fila2 != NULL) {
                inserir(&filaResultado, removido(&fila2)->valor);
            }
        }
    }

    print(filaResultado);

    while (filaResultado != NULL) {
        no* temp = removido(&filaResultado);
        free(temp);
    }

    return 0;
}
