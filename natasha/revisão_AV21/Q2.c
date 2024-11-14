
/*
02 - Escreva uma função em C que receba uma árvore binária de busca e
retorne 1 se a árvore for AVL ou retorne 0 se a árvore não for AVL.
Protótipo da função:

int arvBalanceada(Arv* raiz);

OBS.: Verifique recursivamente
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Arv {
    int chave;
    struct Arv *esquerda;
    struct Arv *direita;
} Arv;

void inserir(Arv** raiz, int n) {
    if (*raiz == NULL) {
        *raiz = malloc(sizeof(Arv));
        (*raiz)->chave = n;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    } else {
        if (n < (*raiz)->chave) {
            inserir(&(*raiz)->esquerda, n);
        } else if (n > (*raiz)->chave) {
            inserir(&(*raiz)->direita, n);
        }
    }
}

int altura(Arv *raiz){
    if(raiz==NULL)return 0;
    else {
        int ArvEsq = altura(raiz->esquerda);
        int ArvDir = altura (raiz->direita);
        if(ArvEsq>ArvDir) return 1 + ArvEsq;
        else return 1 + ArvDir;
    }
}

int arvBalanceada(Arv* raiz){
    if(raiz==NULL)return 1;
    else {
        int ESQ = altura(raiz->esquerda);
        int DIR = altura(raiz->direita);
        int FB = ESQ - DIR;

        if(FB>-1 ||FB<1) return 0;
        return arvBalanceada(raiz->esquerda) && arvBalanceada(raiz->direita);
    }
}

int main() {
    Arv* raiz = NULL;

    inserir(&raiz, 4);
    inserir(&raiz, 2);
    inserir(&raiz, 7);
    inserir(&raiz, 1);
    inserir(&raiz, 3);
    inserir(&raiz, 5);
    inserir(&raiz, 6);

    if (arvBalanceada(raiz)) {
        printf("A árvore é AVL.\n");
    } else {
        printf("A árvore não é AVL.\n");
    }

    return 0;
}
