#include <stdio.h>
#include "ordenado.h"

int unirListasOrdenadas(int lista1[], int n1, int lista2[], int n2, int lista3[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (lista1[i] < lista2[j]) {
            lista3[k++] = lista1[i++];
        } else {
            lista3[k++] = lista2[j++];
        }
    }
    while (i < n1) {
        lista3[k++] = lista1[i++];
    }
    while (j < n2) {
        lista3[k++] = lista2[j++];
    }
    return k;
}

void ordenarLista(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

void imprimirLista(int lista[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("}\n");
}
