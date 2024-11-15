#include <stdio.h>
#include "invertido.h"

void inverterLista(int lista[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = lista[i];
        lista[i] = lista[n - 1 - i];
        lista[n - 1 - i] = temp;
    }
}

void imprimirLista(int lista[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("}\n");
}
