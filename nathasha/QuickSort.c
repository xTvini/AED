#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int start, int end){
    if(start<end){
        int indice = particao(arr,start,end);

        quickSort(arr,start,end-1);
        quickSort(arr,start+1,end);
    }
}

int particao(int arr[], int start, int end){
    int pivot, indice, i;
    pivot=arr[start];
    indice=end;
    for(i=end;i>start;i--){
        if(arr[i]>=pivot){
            troca(arr,i,indice);
            indice--;
        }
        troca(arr,start,indice);
        return indice;
    }
}

void troca(int arr[],int start,int end){
    int aux=arr[start];
    arr[start]=arr[end];
    arr[end]=aux;
}


int main(){

}