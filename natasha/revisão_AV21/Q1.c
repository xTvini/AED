/*
01 - Escreva uma função em C que exiba todos os valores que são filhos à
esquerda em toda a Árvore Binária de Busca.
Protótipo da função:

void fihsEsquerdos(Arv* raiz);

OBS.: Verifique recursivamente
Exemplo: Nesse caso ele deve exibir os valores: 1,2 e 5.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Arv {
    int chave;
    struct Arv *esquerda;
    struct Arv *direita;
} Arv;

void inserir(Arv **raiz, int n) {
    if (*raiz == NULL) {
        *raiz = malloc(sizeof(Arv));
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
        (*raiz)->chave = n;
    } else {
        if (n < (*raiz)->chave) {
            inserir(&(*raiz)->esquerda, n);
        } else if (n > (*raiz)->chave) {
            inserir(&(*raiz)->direita, n);
        }
    }
}

void fihsEsquerdos(Arv* raiz) {
    if (raiz != NULL) {
        if(raiz->esquerda!=NULL){
            printf("%d", raiz->esquerda->chave);
            fihsEsquerdos(raiz->esquerda);
        }
        fihsEsquerdos(raiz->direita);
    }
}

int main() {
    Arv* raiz = NULL;
    int valores[] = {4,2,7,1,3,5,8};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        inserir(&raiz, valores[i]);
    }

    printf("Elementos em ordem (fihsEsquerdos): ");
    fihsEsquerdos(raiz);
    printf("\n");

    return 0;
}
