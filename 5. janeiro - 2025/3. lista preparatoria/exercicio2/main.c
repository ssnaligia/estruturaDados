/*2. Implemente uma função que copia uma lista L1 de elementos inteiros em uma outra lista L2 eliminando
elementos repetidos. Os dados devem estar ordenados decrescentemente em L2. Use conceito de lista
sequencial*/

#include "lista.h"
#include <stdio.h>

int main() {
    Lista L1, L2;
    inicializarLista(&L1);  

    int n, valor;

    printf("Quantos números deseja inserir na lista L1? ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Número inválido! A quantidade deve ser entre 1 e %d.\n", MAX);
        return 1;
    }

    printf("Digite os %d números para L1:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &valor);
        inserirElemento(&L1, valor);
    }

    copiarListaSemRepetidos(&L1, &L2);

    printf("\nLista L1 original: ");
    imprimirLista(&L1);

    printf("Lista L2 sem repetidos e ordenada decrescentemente: ");
    imprimirLista(&L2);

    return 0;  
}
