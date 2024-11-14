#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
    int valor;
    struct arvore *direita;
    struct arvore *esquerda;
} arvore;

void inserirNaARaizBinario(arvore **raiz, int chave) {
    if (*raiz == NULL) {
        *raiz = (arvore*)malloc(sizeof(arvore));
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
        (*raiz)->valor = chave;
    } else {
        if (chave < (*raiz)->valor) {
            inserirNaARaizBinario(&(*raiz)->esquerda, chave);
        } else if (chave > (*raiz)->valor) {
            inserirNaARaizBinario(&(*raiz)->direita, chave);
        }
    }
}

int qtdFolhas(arvore *raiz, int chave) {
    if (raiz == NULL) return 0;
    if (raiz->valor == chave) {
        if (raiz->esquerda == NULL && raiz->direita == NULL) return 1;
        return qtdFolhas(raiz->esquerda, chave) + qtdFolhas(raiz->direita, chave);
    }
    else if (chave < raiz->valor) {
        return qtdFolhas(raiz->esquerda, chave);
    } else {
        return qtdFolhas(raiz->direita, chave);
    }
}


int main() {
    arvore *raiz = NULL;
    inserirNaARaizBinario(&raiz, 10);
    inserirNaARaizBinario(&raiz, 5);
    inserirNaARaizBinario(&raiz, 15);
    inserirNaARaizBinario(&raiz, 3);
    inserirNaARaizBinario(&raiz, 7);
    int chave = 7;
    printf("Quantidade de folhas na subárvore com chave %d: %d\n", chave, qtdFolhas(raiz, chave));
    return 0;
}
