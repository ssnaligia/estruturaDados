#include "copia.h"
#include <stdio.h>
#include <locale.h>

void inicializarLista(Lista *lista) {
    lista->tamanho = 0;
}

int inserirElemento(Lista *lista, int valor) {
    if (lista->tamanho >= MAX)  
        return 0; 
    
    lista->elementos[lista->tamanho++] = valor;  
    return 1;
}

void copiarListaSemRepetidos(Lista *L1, Lista *L2) {
    inicializarLista(L2);  

    for (int i = 0; i < L1->tamanho; i++) {  //percorre L1 e insere elementos únicos em L2
        int elemento = L1->elementos[i];
        int jaExiste = 0;

        for (int j = 0; j < L2->tamanho; j++) {  //verifica se o elemento já está em L2
            if (L2->elementos[j] == elemento) {
                jaExiste = 1;
                break;
            }
        }

        if (!jaExiste) {  //se o elemento não existe, insere no lugar correto para manter a ordem decrescente
            int k = L2->tamanho - 1;
            while (k >= 0 && L2->elementos[k] < elemento) {
                L2->elementos[k + 1] = L2->elementos[k];
                k--;
            }
            L2->elementos[k + 1] = elemento;
            L2->tamanho++;
        }
    }
}

void imprimirLista(Lista *lista) {
    printf("[ ");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("]\n");
}
