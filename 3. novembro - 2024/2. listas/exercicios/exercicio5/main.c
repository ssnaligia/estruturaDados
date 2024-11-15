#include <stdio.h>
#include "ordenado.h"

int main() {
	int lista1[MAX], lista2[MAX], lista3[2 * MAX];
	int n1, n2;

	printf("\nDigite o número de elementos da lista 1: ");
	scanf("%d", &n1);
	if (n1 <= 0 || n1 > MAX) {
		return 1;
	}
	printf("\nDigite os elementos da lista 1:\n");
	for (int i = 0; i < n1; i++) {
        printf("Elemento %d: ", i + 1);
		scanf("%d", &lista1[i]);
	}

	printf("\nDigite o número de elementos da lista 2: ");
	scanf("%d", &n2);
	if (n2 <= 0 || n2 > MAX) {
		return 1;
	}
	printf("\nDigite os elementos da lista 2:\n");
	for (int i = 0; i < n2; i++) {
	    printf("Elemento %d: ", i + 1);
		scanf("%d", &lista2[i]);
	}

	ordenarLista(lista1, n1);
	ordenarLista(lista2, n2);

	int n3 = unirListasOrdenadas(lista1, n1, lista2, n2, lista3);

	printf("\nLista 1 (Ordenada): ");
	imprimirLista(lista1, n1);

	printf("\nLista 2 (Ordenada): ");
	imprimirLista(lista2, n2);

	printf("\nLista 3 (União ordenada): ");
	imprimirLista(lista3, n3);

	return 0;
}
