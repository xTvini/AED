/**
 * paineis.h
 * Created on May, 10th 2024
 * Author: Vinicius Diniz 
*/

#ifndef ALGORITIMOS_H
#define ALGORITIMOS_H

#include <stdio.h> 

//INICIO ASSUNTO AV1

//LISTA DUPLAMENTE ENCADEADA

/*1*/ void InserirInicioDupla();
/*2*/ void InserirFinalDupla();
/*3*/ void InserirNoMeioDupla();
/*4*/ void DeleteFinalDupla();
/*5*/ void DeleteInicioDupla();
/*6*/ void printDupla();
/*7*/ void printfInvertido();

//PILHA

/*1*/ void InserirPilha();
/*2*/ void DeletarPilha();
/*3*/ void PrintPilha();


//FILA SEM TAIL

/*1*/ void inserirFila();
/*2*/ void deleteFila(); 
/*3*/ void printfFila();

//FILA COM TAIL

/*1*/ void inserirFilaComTail();
/*2*/ void removerFilaComTail();

//LISTA DUPLAMENTE CIRCULAR

/*1*/ void inserirDuplaListaCircular();
/*2*/ void inserirFinalDuplaListaCircular();
/*3*/ void inserirMeioAntesDuplaListaCircular();
/*4*/ void inserirMeioDepoisDuplaListaCircular();
/*5*/ void deletarNumeroEspecificoDuplaListaCircular();
/*6*/ void deletarInicioDuplaListaCircular();
/*7*/ void deletarFinalDuplaListaCircular();
/*8*/ void printDuplaListaCircular();
/*9*/ void printInvertidoDuplaListaCircular();

//LISTA SIMPLESMENTE CIRCULAR

/*1*/ void inserirInicioListaSimplesCircular();
/*2*/ void inserirMeioListaSimplesCircular();
/*3*/ void inserirFinalListaSimplesCircular();
/*4*/ void deleteInicioListaSimplesCircular();
/*5*/ void deleteFinalListaSimplesCircular();
/*6*/ void printListaSimplesCircular();

//INSERTION SORT

/*1*/ void insertionSort();

//BUBBLE SORT

/*1*/ void bubbleSortV0();
/*2*/ void bubbleSortV1();
/*3*/ void bubbleSortV2();

//FIM ASSUNTO AV1

//ARVORE BINARIA

/*1*/ void inserirNaARaizBinario();
/*2*/ void posOrdem();
/*3*/ void inOrdem();
/*4*/ void preOrdem();
/*5*/ void buscarArvoreBinaria();

//ARVORE AVL

/*1*/ int filhosAlt();
/*2*/ void roda_dir();
/*3*/ void roda_esq();
/*4*/ void balanco();
/*5*/ int filhosAlt();
/*6*/ void inserirAVL();
/*7*/ Arv *Maiordir();
/*8*/ void removerAVL();

#endif