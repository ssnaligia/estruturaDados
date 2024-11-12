#include <stdio.h>
#include "ordenado.h"

int main() {
    int n;

    printf("Digite o número de elementos na lista A: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("O número de elementos excede o limite máximo de %d.\n", MAX);
        return 1;
    }

    No A[MAX], B[MAX];

    printf("Digite os elementos da lista A (desordenados): \n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &A[i].valor);
    }

    ordenarLista(A, B, n);

    printf("Lista A (desordenada): ");
    imprimirLista(A, n);

    printf("Lista B (ordenada): ");
    imprimirLista(B, n);

    return 0;
}
