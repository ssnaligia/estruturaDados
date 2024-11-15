#include <stdio.h>
#include "invertido.h"

int main() {
    int lista[MAX], n;

    printf("\nDigite o número de elementos da lista: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("\nNúmero inválido de elementos.\n");
        return 1;
    }

    printf("\nDigite os elementos da lista:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &lista[i]);
    }

    printf("\nLista original: ");
    imprimirLista(lista, n);

    inverterLista(lista, n);

    printf("\nLista invertida: ");
    imprimirLista(lista, n);

    return 0;
}
