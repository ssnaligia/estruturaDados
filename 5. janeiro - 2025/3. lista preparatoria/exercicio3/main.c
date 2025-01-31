/*3. Dadas duas listas encadeadas dinâmicas L1 e L2, implemente uma operação UNION, que cria uma
terceira lista L3 com a união entre as duas listas. No UNION não há necessidade de eliminar elementos
repetidos.*/

#include <stdio.h>
#include <locale.h>
#include "union.h"

int main() {
    Lista L1, L2, L3;
    int valor;
    int n, i;
    
    inicializarLista(&L1);
    inicializarLista(&L2);
    inicializarLista(&L3);

    printf("Digite a quantidade de elementos para a Lista 1: ");
    scanf("%d", &n);
    printf("Digite os %d elementos da Lista 1:\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        inserirFinal(&L1, valor);
    }

    printf("Digite a quantidade de elementos para a Lista 2: ");
    scanf("%d", &n);
    printf("Digite os %d elementos da Lista 2:\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        inserirFinal(&L2, valor);
    }

    printf("\nLista L1: ");
    imprimirLista(&L1);
    printf("Lista L2: ");
    imprimirLista(&L2);

    unirListas(&L1, &L2, &L3);

    printf("\nLista L3 (União de L1 e L2): ");
    imprimirLista(&L3);

    return 0;
}
