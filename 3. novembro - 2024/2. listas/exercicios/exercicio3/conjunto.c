#include <stdio.h>
#include "conjunto.h"

void imprimirLista(No lista[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i].valor);
    }
    printf("\n");
}

int uniao(No A[], int nA, No B[], int nB, No C[]) {
    int nC = 0;

    for (int i = 0; i < nA; i++) {
        C[nC++] = A[i];
    }

    for (int i = 0; i < nB; i++) {
        int encontrado = 0;
        for (int j = 0; j < nA; j++) {
            if (B[i].valor == A[j].valor) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            C[nC++] = B[i];
        }
    }

    return nC;
}

int intersecao(No A[], int nA, No B[], int nB, No C[]) {
    int nC = 0;

    for (int i = 0; i < nA; i++) {
        for (int j = 0; j < nB; j++) {
            if (A[i].valor == B[j].valor) {
                C[nC++] = A[i];
                break;
            }
        }
    }

    return nC;
}

int diferenca(No A[], int nA, No B[], int nB, No C[]) {
    int nC = 0;

    for (int i = 0; i < nA; i++) {
        int encontrado = 0;
        for (int j = 0; j < nB; j++) {
            if (A[i].valor == B[j].valor) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            C[nC++] = A[i];
        }
    }

    return nC;
}


