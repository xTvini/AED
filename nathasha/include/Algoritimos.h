/**
 * paineis.h
 * Created on May, 10th 2024
 * Author: Vinicius Diniz 
*/
#ifndef ALGORITIMOS_H
#define ALGORITIMOS_H

#include <stdio.h> 

//LISTA DUPLAMENTE ENCADEADA

void InserirInicioDupla();
void InserirFinalDupla();
void InserirNoMeioDupla();
void DeleteFinalDupla();
void DeleteInicioDupla();
void printDupla();
void printfInvertido();

//PILHA

void InserirPilha();
void DeletarPilha();
void PrintPilha();


//FILA SEM TAIL

void inserirFila();
void deleteFila(); 
void printfFila();

//FILA COM TAIL

void inserirFilaComTail();
void removerFilaComTail();

//LISTA DUPLAMENTE CIRCULAR

void inserirDuplaListaCircular();

#endif