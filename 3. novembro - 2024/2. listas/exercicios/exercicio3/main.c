#include <stdio.h>
#include "conjunto.h"

int main() {
    int nA, nB;

    printf("Digite o número de elementos na lista A: ");
    scanf("%d", &nA);

    if (nA > MAX || nA <= 0) {
        printf("\nNúmero de elementos inválido para A.\n");
        return 1;
    }

    No A[MAX], B[MAX], C[MAX];

    printf("\nDigite os elementos da lista A: \n");
    for (int i = 0; i < nA; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &A[i].valor);
    }

    printf("\nDigite o número de elementos na lista B: ");
    scanf("%d", &nB);

    if (nB > MAX || nB <= 0) {
        printf("\nNúmero de elementos inválido para B.\n");
        return 1;
    }

    printf("\nDigite os elementos da lista B: \n");
    for (int i = 0; i < nB; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &B[i].valor);
    }

    int nC = uniao(A, nA, B, nB, C);
    printf("\nUnião de A e B: ");
    imprimirLista(C, nC);

    nC = intersecao(A, nA, B, nB, C);
    printf("\nInterseção de A e B: ");
    imprimirLista(C, nC);

    nC = diferenca(A, nA, B, nB, C);
    printf("\nDiferença de A e B (A - B): ");
    imprimirLista(C, nC);

    return 0;
}
