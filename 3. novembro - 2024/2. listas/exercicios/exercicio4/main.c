#include <stdio.h>
#include "remover.h"

int main() {
    int n;

    printf("Digite o número de elementos na lista: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("\nO número de elementos excede o limite máximo de %d.\n", MAX);
        return 1;
    } else if (n <= 0) {
        printf("\nO número de elementos deve ser maior que 0.\n");
        return 1;
    }

    No lista[MAX];

    printf("\nDigite os elementos da lista: \n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &lista[i].valor);
    }

    printf("\nLista Original: ");
    imprimirLista(lista, n);

    int novaTamanho = removerDuplicados(lista, n);

    printf("\nLista após remover duplicados: ");
    imprimirLista(lista, novaTamanho);

    return 0;
}
