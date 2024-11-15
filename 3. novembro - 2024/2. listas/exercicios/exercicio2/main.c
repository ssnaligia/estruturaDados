#include <stdio.h>
#include "ordenado.h"

int main() {
    int n;

    printf("Digite o número de elementos na lista A: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("\nO número de elementos excede o limite máximo de %d.\n", MAX);
        return 1;
    } else if(n <= 0) {
        printf("\nO número de elementos não pode ser menor ou igual a 0.\n");
        return 1;
    }

    No A[MAX], B[MAX];

    printf("\nDigite os elementos da lista A (Desordenados): \n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &A[i].valor);
    }

    ordenarLista(A, B, n);

    printf("\nLista A (Desordenada): ");
    imprimirLista(A, n);

    printf("\nLista B (Ordenada): ");
    imprimirLista(B, n);

    return 0;
}
