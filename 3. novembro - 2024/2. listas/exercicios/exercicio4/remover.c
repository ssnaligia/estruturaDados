#include <stdio.h>
#include "remover.h"

int removerDuplicados(No lista[], int n) {
    if (n == 0) return 0;

    int i, j, novaPos = 1;
    for (i = 1; i < n; i++) {
        int duplicado = 0;
        for (j = 0; j < novaPos; j++) {
            if (lista[i].valor == lista[j].valor) {
                duplicado = 1;
                break;
            }
        }
        if (!duplicado) {
            lista[novaPos++] = lista[i];
        }
    }
    return novaPos;
}

void imprimirLista(No lista[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i].valor);
    }
    printf("}\n");
}
