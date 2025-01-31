/*1. Fazer uma função para verificar se uma lista de inteiros (use conceito de lista sequencial) está ordenada
ou não (a ordem pode ser crescente ou decrescente).*/

#include "inteiros.h"
#include <stdio.h>
#include <locale.h>

int main() {
    Lista lista;
    inicializarLista(&lista);  

    int n, valor;

    printf("Quantos números deseja inserir na lista? ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Número inválido! A quantidade deve ser entre 1 e %d.\n", MAX);
        return 1;
    }

    printf("Digite os %d números:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &valor);
        inserirElemento(&lista, valor);
    }

    int resultado = verificarOrdenacao(&lista);
    if (resultado == 1)
        printf("A lista está ordenada em ordem CRESCENTE.\n");
    else if (resultado == -1)
        printf("A lista está ordenada em ordem DECRESCENTE.\n");
    else
        printf("A lista NÃO está ordenada.\n");

    return 0;
}
