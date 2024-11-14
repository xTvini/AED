#include <stdio.h>
#include <stdlib.h>
#include "./Algoritimos.h"

typedef struct no{
    int valor;
    struct no *next;
    struct no *prev;
}no;

//INICIO ASSUNTO AV1

//LISTA DUPLAMENTE

void InserirInicioDupla(no **head, int num){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=num;
        novo->next=*head;
        novo->prev=NULL;
        if(*head!=NULL){
            (*head)->prev=novo;
        }
        *head=novo;
    }
}

void InserirFinalDupla(no **head, int num){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=num;
        novo->next=NULL;
        novo->prev=*head;
        if(*head==NULL){
            *head=novo;
            novo->prev=NULL;
        }else{
            no*aux=*head;
            while(aux->next!=NULL){
                aux=aux->next;
            }
            aux->next=novo;
            novo->prev=aux;
        }
    }
}

void InserirNoMeioDupla(no**head,int num, int prevnum){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=num;
        if(*head==NULL){
            novo->next=NULL;
            novo->prev=NULL;
            *head=novo;
        }
        else{
            no*aux=*head;
            while(aux->next!=prevnum && aux->next==NULL){
                aux=aux->next;
            }
            novo->next=aux->next;
            aux->next->prev=novo;
            aux->next=novo;
            novo->prev=aux;
        }
    }
}

void DeleteFinalDupla(no**head){
    no* aux=*head;
    if(*head==NULL){
        return;
    }
    if(aux->next==NULL){
        free(aux);
        *head=NULL;
        return;
    }
    while(aux->next!=NULL){
        aux=aux->next;
    }
    aux->prev->next=NULL;
    free(aux);
}

void DeletarInicioDupla(no**head){
    no*aux=*head;
    if(*head==NULL){
        return;
    }
    *head = aux->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(aux);
}

void printDupla(no*head){
    no*aux=head;
    while(aux!=NULL){
        printf("%d ", aux);
        aux=aux->next;
    }
    printf("\n");
}

void printfInvertido(no*head){
    no*aux=head;
    while(aux!=NULL){
        printf("%d ", aux);
        aux=aux->next;
    }
    printf("\n");
}
//pilha
void InserirPilha(no**head, int num){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=num;
        novo->next=*head;
        *head=novo;
    }
}

void DeletarPilha(no**head){
    no*aux;
    while(*head!=NULL){
        aux=*head;
        *head=(*head)->next;
        free(aux);
    }
}

void PrintPilha(no*head){
    while(head!=NULL){
        printf("%d ", head->valor);
        head=head->next;
    }
}

//fila sem tail

void inserirFila(no**head, int num){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=num;
        novo->next=NULL;
        if(*head==NULL){
            *head=novo;
        }else{
            no*aux=*head;
            while(aux->next!=NULL){
                aux=aux->next;
            }
            aux=novo;
        }
    }
}

void deleteFila(no**head){
    no*aux;
    while(*head!=NULL){
        aux=*head;
        *head=(*head)->next;
        free(aux);
    }
}

void printfFila(no*head){
    while(head!=NULL){
        printf("%d ", head->valor);
        head=head->next;
    }
}

//fila com tail

void inserirFilaComTail(no**head,no**tail, int n){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        novo->next=NULL;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
        } else {
            (*tail)->next=novo;
            *tail=novo;
        }
    }
}

void removerFilaComTail(no**head,no**tail){
    if(*head!=NULL){
        no*aux=*head;
        *head=(*head)->next;
        free(aux);
        *head=aux;
    }
    if(*head==NULL){
        *tail=NULL;
    }
}

//Lista Duplamente Circular

void inserirDuplaListaCircular(no**head,no**tail,int n){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            (*head)->prev=novo;
            (*tail)->next=novo;
        } else {
            novo->next=*head;
            novo->prev=*tail;
            (*head)->prev=novo;
            (*tail)->next=novo;
            *head=novo;
        }
    }
}

void inserirFinalDuplaListaCircular(no**head,no**tail,int n){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            (*head)->prev=novo;
            (*tail)->next=novo;
        } else {
            novo->next=*head;
            novo->prev=*tail;
            (*tail)->next=novo;
            (*head)->prev=novo;
            *tail=novo;

        }
    }
}

void inserirMeioAntesDuplaListaCircular(no**head,no**tail,int n,int dps){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            (*tail)->next=novo;
            (*head)->prev=novo;
        }else{
            no*aux=*head;
            do{
                if(aux->valor==dps){
                    novo->prev=aux->prev;
                    novo->next=aux;
                    aux->prev->next=novo;
                    aux->prev=novo;
                    return;
                }
                aux=aux->next;
            }while(aux!=*head);
        }
    }
}

void inserirMeioDepoisDuplaListaCircular(no**head,no**tail,int n, int ant){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            (*head)->prev=*tail;
            (*tail)->next=*head;
        } else {
            no*aux=*head;
            if((*tail)->valor==ant){
                novo->next=*head;
                novo->prev=*tail;
                (*tail)->next=novo;
                *tail=novo;
                (*head)->prev=*tail;
            }
            do{
                if(aux->valor==ant){
                    novo->next=aux->next;
                    novo->prev=aux;
                    aux->next->prev=novo;
                    aux->next=novo;
                }
                aux=aux->next;
            }while(aux!=*head);
        }
    }
}

void deletarNumeroEspecificoDuplaListaCircular(no**head,no**tail,int nDelete){
    if(*head!=NULL){
        no*aux=*head;
        if(*head==*tail && (*head)->valor==nDelete){
            free(*head);
            *tail=NULL;
            *head=NULL;
            return;
        }
        do{
            if(aux->valor==nDelete){
                if(aux==*head){
                    *head=aux->next;
                    (*tail)->next=*head;
                    (*head)->prev=*tail;
                }
                if(aux==*tail){
                    *tail=aux->prev;
                    (*tail)->next=*head;
                    (*head)->prev=*tail;
                }
                aux->prev->next=aux->next;
                aux->next->prev=aux->prev;
                free(aux);
                return;
            } else {
                aux=aux->next;
            }
        }while(aux!=*head);
    }
}

void deletarInicioDuplaListaCircular(no**head,no**tail){
    if(*head!=NULL){
        if(*head==*tail){
            free(*head);
            *head=NULL;
            *tail=NULL;
        } else {
            no*aux=*head;
            *head=aux->next;
            (*head)->prev=*tail;
            (*tail)->next=*head;
            free(aux);
        }
    }
}

void deletarFinalDuplaListaCircular(no**head,no**tail){
    if(*head!=NULL){
        if(*head==*tail){
            free(*head);
            *head=NULL;
            *tail=NULL;
        } else {
            no*aux=*tail;
            *tail=aux->prev;
            (*tail)->next=*head;
            (*head)->prev=*tail;
            free(aux);
        }
    }
}

void printDuplaListaCircular(no*head,no*tail){
    if(head!=NULL){
        do{
            printf("%d ", head->valor);
            head=head->next;
        }while(head!=tail->next);
        printf("\n");
    }
}

void printInvertidoDuplaListaCircular(no*head,no*tail){
    if(head!=NULL){
        do{
            printf("%d",tail->valor);
            tail=tail->prev;
        }while(tail!=head->prev);
    }
}

//Lista Simplesmente Circular


void inserirInicioListaSimplesCircular(no**head,no**tail,int n){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            (*tail)->next=*head;
        } else {
            novo->next=*head;
            *head=novo;
            (*tail)->next=*head;
        }
    }
}

void inserirMeioListaSimplesCircular(no**head,no**tail,int n, int pos){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            (*tail)->next=*head;
        } else {
            no*aux=*head;
            if((*head)->valor==pos){
                novo->next=*head;
                *head=novo;
                (*tail)->next=*head;
                return;
            }
            do{
                if(aux->next->valor==pos){
                    novo->next=aux->next;
                    aux->next=novo;
                    return;
                }
                aux=aux->next;
            }while(aux!=*head);
        }
    }
}

void inserirFinalListaSimplesCircular(no**head,no**tail,int n){
    no*novo=malloc(sizeof(no));
    if(novo!=NULL){
        novo->valor=n;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
            (*tail)->next=*head;
        } else {
            novo->next=*head;
            (*tail)->next=novo;
            *tail=novo;
        }
    }
}

void deleteInicioListaSimplesCircular(no**head,no**tail){
    if(*head!=NULL){
        if(*head==*tail){
            free(*head);
            *head=NULL;
            *tail=NULL;
        } else {
            no*aux=*head;
            *head=aux->next;
            (*tail)->next=*head;
            free(aux);
        }
    }
}

void deleteFinalListaSimplesCircular(no**head,no**tail){
    if(*head!=NULL){
        if(*head==*tail){
            free(*head);
            *head=NULL;
            *tail=NULL;
        } else {
            no*aux=*head;
            do{
                if(aux->next==*tail){
                    free(*tail);
                    *tail=aux;
                    (*tail)->next=*head;
                    return;
                }
                aux=aux->next;
            }while(aux!=*head);
        }
    }
}

void printListaSimplesCircular(no*head,no*tail){
    if(head!=NULL){
        do{
            printf("%d ", head->valor);
            head=head->next;
        }while(head!=tail->next);
    }
}

//Insertion Sort

void insertionSort(int *arr, int tamanho,int num){
    for(int i=1;i<tamanho;i++){
        int j=i;
        while(arr[j]>arr[j-1] && j>0){
            int aux = arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=aux;
            --j;
        }
    }
}

//Bubble Sort V0

void bubbleSortV0(int *arr,int tamanho, int n){
    for(int i=1;i<tamanho;i++){
        for(int j=0;j<tamanho-1;j++){
            if(arr[j]>arr[j+1]){
                int aux=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=aux;
            }
        }
    }
}

void bubbleSortV1(int *arr, int tamanho, int n){
    for(int i=1; i<tamanho;i++){
        for(int j=tamanho-1; j>=i; j--){
            if(arr[j]>arr[j-1]){
                int aux=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=aux;
            }
        }
    }
}

void bubbleSortV2(int *arr, int tamanho, int n){
    int troca=1, n=1;
    while(n<=tamanho && troca==1){
        troca = 0;
        for(int i=0;i<tamanho-1;i++){
            if(arr[i]>arr[i+1]){
                int aux = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = aux;
                troca=1;
            }
        }
        ++n;
    }
}

//FIM ASSUNTO AV1

//Arv BINARIA
typedef struct Arv{
    int valor;
    struct Arv *dir;
    struct Arv *esq;
}Arv;

void inserirNaARaizBinario(Arv**raiz,int chave){
    if(*raiz==NULL){
        *raiz=(Arv*)malloc(sizeof(Arv));
        (*raiz)->esq=NULL;
        (*raiz)->dir=NULL;
        (*raiz)->valor=chave;
    } else {
        if(chave<(*raiz)->valor){
            inserirNaARaizBinario(&(*raiz)->esq, chave);
        }else if(chave>(*raiz)->valor){
            inserirNaARaizBinario(&(*raiz)->dir, chave);
        }
    }
}

void posOrdem(Arv*raiz){
    if(raiz!=NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d", raiz->valor);
    }
}

void inOrdem(Arv*raiz){
    if(raiz!=NULL){
        inOrdem(raiz->esq);
        printf("%d", raiz->valor);
        inOrdem(raiz->dir);
    }
}

void preOrdem(Arv*raiz){
    if(raiz!=NULL){
        printf("%d", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void buscarArvBinaria(Arv*raiz, int chave){
    if(raiz->valor==chave) return 1;
    else if(raiz == NULL) return 0;
    else if(raiz->valor<chave) busca(raiz->dir, chave);
    else busca(raiz->esq, chave);
}

//ARV AVL

// Calcula a altura de uma árvore/subárvore
int filhosAlt(Arv *r) {
  if (r == NULL)
    return 0;
  else {
    int ae = filhosAlt(r->esq);  // Calcula a altura da subárvore esq
    int ad = filhosAlt(r->dir);  // Calcula a altura da subárvore dir
    return 1 + (ae > ad ? ae : ad);  // Retorna a altura máxima entre as subárvores + 1
  }
}

// Realiza uma rotação simples à dir em um nó desbalanceado
void roda_dir(Arv **p) {
  Arv *aux = (*p)->esq;  // Nó esquerdo da raiz se torna a nova raiz
  (*p)->esq = aux->dir;  // Subárvore dir do nó esquerdo passa para a esq do nó atual
  aux->dir = (*p);       // Nó atual se torna filho direito do nó esquerdo
  *p = aux;              // Atualiza o ponteiro para o novo nó raiz
}

// Realiza uma rotação simples à esq em um nó desbalanceado
void roda_esq(Arv **p) {
  Arv *aux = (*p)->dir;  // Nó direito da raiz se torna a nova raiz
  (*p)->dir = aux->esq;  // Subárvore esq do nó direito passa para a dir do nó atual
  aux->esq = (*p);       // Nó atual se torna filho esquerdo do nó direito
  *p = aux;              // Atualiza o ponteiro para o novo nó raiz
}

// Realiza o balanceamento do nó, aplicando rotações conforme necessário
void balanco(Arv **p) {
  if (*p != NULL) {
    int fb = filhosAlt((*p)->dir) - filhosAlt((*p)->esq);  // Calcula o fator de balanceamento

    // Desbalanceamento para a esq
    if (fb <= -2) {
      int fb_aux = filhosAlt((*p)->esq->dir) - filhosAlt((*p)->esq->esq);
      if (fb_aux > 0) {  // Rotação dupla dir
        roda_esq(&((*p)->esq));
        roda_dir(p);
        printf("\nRotação: Dupla dir");
      } else {  // Rotação simples dir
        roda_dir(p);
        printf("\nRotação: dir Simples");
      }
    }
    // Desbalanceamento para a dir
    else if (fb >= 2) {
      int fb_aux = filhosAlt((*p)->dir->dir) - filhosAlt((*p)->dir->esq);
      if (fb_aux < 0) {  // Rotação dupla esq
        roda_dir(&((*p)->dir));
        roda_esq(p);
        printf("\nRotação: Dupla esq");
      } else {  // Rotação simples esq
        roda_esq(p);
        printf("\nRotação: esq Simples");
      }
    }
  }
}

// Insere um novo nó na árvore e balanceia após a inserção
void inserirAVL(Arv **t, int n) {
  if (*t == NULL) {  // Cria um novo nó se a posição estiver vazia
    *t = (Arv *)malloc(sizeof(Arv));
    (*t)->esq = NULL;
    (*t)->dir = NULL;
    (*t)->valor = n;
  } else if (n < (*t)->valor)
    inserirAVL(&(*t)->esq, n);  // Insere na subárvore esq
  else if (n > (*t)->valor)
    inserirAVL(&(*t)->dir, n);  // Insere na subárvore dir
  balanco(t);  // Realiza o balanceamento após a inserção
}

// Encontra o maior valor na subárvore esq para substituição
Arv *Maiordir(Arv **no) {
  if ((*no)->dir != NULL)
    return Maiordir(&(*no)->dir);  // Procura o maior valor (extremidade dir)
  else {
    Arv *aux = *no;
    if ((*no)->esq != NULL) {
      *no = (*no)->esq;  // Se houver uma subárvore esq, atualiza o nó
    } else {
      *no = NULL;  // Remove o nó se não tiver filhos
    }
    return aux;  // Retorna o nó com o maior valor
  }
}

// Remove um nó da árvore e realiza balanceamento após a remoção
void removerAVL(Arv **pRaiz, int numero) {
  if (*pRaiz == NULL) {
    printf("\nRemoção: Numero nao existe na Arv!");
    return;
  }
  else if (numero < (*pRaiz)->valor)
    removerAVL(&(*pRaiz)->esq, numero);  // Procura o valor na subárvore esq
  else if (numero > (*pRaiz)->valor)
    removerAVL(&(*pRaiz)->dir, numero);  // Procura o valor na subárvore dir
  else {
    Arv *pAux = *pRaiz;

    // Caso 1: nó sem filhos
    if (((*pRaiz)->esq == NULL) && ((*pRaiz)->dir == NULL)) {
      free(pAux);
      (*pRaiz) = NULL;
    } 
    // Caso 2: nó com apenas um filho (direito)
    else if ((*pRaiz)->esq == NULL) {
      (*pRaiz) = (*pRaiz)->dir;
      pAux->dir = NULL;
      free(pAux);
    } 
    // Caso 2: nó com apenas um filho (esquerdo)
    else if ((*pRaiz)->dir == NULL) {
      (*pRaiz) = (*pRaiz)->esq;
      pAux->esq = NULL;
      free(pAux);
    } 
    // Caso 3: nó com dois filhos
    else {
      pAux = Maiordir(&(*pRaiz)->esq);  // Encontra o maior da subárvore esq
      pAux->esq = (*pRaiz)->esq;
      pAux->dir = (*pRaiz)->dir;
      (*pRaiz)->esq = (*pRaiz)->dir = NULL;
      free((*pRaiz));
      *pRaiz = pAux;
    }
  }
  balanco(pRaiz);  // Realiza o balanceamento após a remoção
}
