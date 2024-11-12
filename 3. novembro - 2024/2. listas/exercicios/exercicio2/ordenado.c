#include <stdio.h>
#include "ordenado.h"

void ordenarLista(No A[], No B[], int n) {
    for (int i = 0; i < n; i++) {
        B[i] = A[i];
    }

    for (int i = 1; i < n; i++) {
        int chave = B[i].valor;
        int j = i - 1;

        while (j >= 0 && B[j].valor > chave) {
            B[j + 1].valor = B[j].valor;
            j = j - 1;
        }
        B[j + 1].valor = chave;
    }
}

void imprimirLista(No lista[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i].valor);
    }
    printf("\n");
}
