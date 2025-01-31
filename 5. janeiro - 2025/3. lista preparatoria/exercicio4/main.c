/*Crie um programa para realizar merge entre duas listas ordenadas. A lista definitiva (merge) deverá
eliminar elementos repetidos. Você decide se deverá manter as listas originais ou não*/

#include <stdio.h>
#include "lista.h"

int main() {
    Lista L1, L2, L3;
    int valor;
    int n, i;

    inicializarLista(&L1);
    inicializarLista(&L2);
    inicializarLista(&L3);

    printf("Digite a quantidade de elementos para a Lista 1 (ordenada): ");
    scanf("%d", &n);
    printf("Digite os %d elementos da Lista 1 (ordenados):\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        inserirFinal(&L1, valor);
    }

    printf("Digite a quantidade de elementos para a Lista 2 (ordenada): ");
    scanf("%d", &n);
    printf("Digite os %d elementos da Lista 2 (ordenados):\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        inserirFinal(&L2, valor);
    }

    printf("\nLista L1: ");
    imprimirLista(&L1);
    printf("Lista L2: ");
    imprimirLista(&L2);

    mergeOrdenado(&L1, &L2, &L3);

    printf("\nLista L3 (Merge de L1 e L2 sem repetidos): ");
    imprimirLista(&L3);

    return 0;
}
