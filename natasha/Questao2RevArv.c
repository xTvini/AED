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

arvore* buscaPai(arvore *raiz, int chave){
    if(raiz==NULL){
        printf("arvore vazia");
        return NULL;
    }
    if((raiz->esquerda && raiz->esquerda->valor==chave)||(raiz->direita&&raiz->direita->valor==chave)){
        return raiz;
    }
    if (chave < raiz->valor) {
        return buscaPai(raiz->esquerda, chave);
    }else if (chave > raiz->valor) {
        return buscaPai(raiz->direita, chave);
    }
    return NULL;
}

int main() {
    arvore *raiz = NULL;
    inserirNaARaizBinario(&raiz, 10);
    inserirNaARaizBinario(&raiz, 5);
    inserirNaARaizBinario(&raiz, 15);
    inserirNaARaizBinario(&raiz, 3);
    inserirNaARaizBinario(&raiz, 7);
    int chave = 15;
    arvore *pai = buscaPai(raiz, chave);
    printf("O pai do nó com valor %d é: %d\n",chave ,pai->valor);
    return 0;
}
