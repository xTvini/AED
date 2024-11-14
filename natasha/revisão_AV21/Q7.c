/*
07 - Ordenação de Livros com Merge Sort
Você é bibliotecário e precisa organizar duas fileiras de livros na sua
biblioteca. As duas fileiras são:
● Fileira 1: Romance
● Fileira 2: Terror
Cada fileira contém 5 livros, mas eles estão fora de ordem. Seu
objetivo é ordenar os livros de cada fileira em ordem alfabética
utilizando o algoritmo Merge Sort. Para facilitar, organize os livros
conforme o exemplo abaixo, depois aplique o algoritmo e mostre a
ordem final dos livros de cada fileira.
Fileira 1: Romance
● O Morro dos Ventos Uivantes
● Orgulho e Preconceito
● A Culpa é das Estrelas
● Anna Kariênina
● Jane Eyre
Fileira 2: Terror
● It - A Coisa
● Drácula
● O Iluminado
● O Exorcista
● A Coisa
Obs: Se o livro começar com a mesma letra, utilize para comparação a
segunda letra para ordenar.
a) Atualize o algoritmo em C do MergeSort para realizar o processo
indicado na questão.
b) Explique o processo de ordenação passo a passo utilizando a
lógica do algoritmo.
*/

//LETRA A
#include <stdio.h>
#include <string.h>

#define TAMANHO 100 // Defina o tamanho do vetor de acordo com o uso

void intercala(int inicio, int meio, int fim,char* v[]) {
    
    int inicio_v01 = inicio;
    int inicio_v02 = meio + 1;
    int poslivre = 0;
    char* aux[TAMANHO];

    // Intercala os dois vetores enquanto ambos tiverem elementos
    while (inicio_v01 <= meio && inicio_v02 <= fim) {
        if (strcmp(v[inicio_v01],v[inicio_v02])<=0)
            aux[poslivre++] = v[inicio_v01++];
        else
            aux[poslivre++] = v[inicio_v02++];
    }

    // Se existirem números em v[inicio_v01] que não foram intercalados
    while (inicio_v01 <= meio)
        aux[poslivre++] = v[inicio_v01++];

    // Se existirem números em v[inicio_v02] que não foram intercalados
    while (inicio_v02 <= fim)
        aux[poslivre++] = v[inicio_v02++];

    // Retorna os valores do vetor aux para o vetor v
    for (inicio_v01 = inicio; inicio_v01 <= fim; inicio_v01++)
        v[inicio_v01] = aux[inicio_v01 - inicio];
}

void mergesort(int inicio, int fim, char* v[]) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergesort(inicio, meio, v); // Ordena a primeira metade
        mergesort(meio + 1, fim, v); // Ordena a segunda metade
        intercala(inicio, meio, fim, v); // Intercala as duas metades
    }
}

int main() {
    // Lista de nomes para ordenar
    char* livrosR[] = {
        "O Morro dos Ventos Uivantes",
        "Orgulho e Preconceito",
        "A Culpa é das Estrelas",
        "Anna Kariênina",
        "Jane Eyre"
    };
    char* livrosT[] ={
        "It - A Coisa",
        "Drácula",
        "O Iluminado",
        "O Exorcista",
        "A Coisa"
    };

    // Chama a função mergesort para ordenar
    mergesort(0, 4, livrosR);
    mergesort(0, 4, livrosT);
    // Exibe os nomes ordenados
    printf("Fileira 1: Romance\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", livrosR[i]);
    }
    printf("\n");
    printf("Fileira 2: Terror\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", livrosT[i]);
    }
    return 0;
}
//FIM LETRA A
//LETRA B
/*
Então professora, o merge sort funciona com base nas divisões, a função intercala ele vai dividir o tamanho da lista de elementos
pela metade até sobrarem uma dupla, que vai ser separada também mas assim que é separada ela é comparada e ordenada, depois dessa
ordenação, após isso ele vai comparar a dupla com o numero que está no proximo indice, por exemplo ele vai comparar o indice 0 1
com o indice 2, e assim vai comparando e ordenando trocando os valores armazenado no indice até ficarem ordenados
*/
//FIM LETRA B