#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"

void carregarNumerosOrdenados(int array[], int tamanho) {
    srand((unsigned) time(NULL));
    
    array[0] = rand() % 1000; 
    for (int i = 1; i < tamanho; i++) {
        array[i] = array[i - 1] + (rand() % 100 + 1); 
    }
}

void criarTabelaIndices(int array[], int indices[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (i % INTERVALO_INDEX == 0) {
            indices[i / INTERVALO_INDEX] = i; 
        }
    }
}

int buscaSequencialIndexada(int array[], int indices[], int tamanhoIndices, int valorBuscado, int *posicaoEncontrada, int *indiceTabela) {
    int inicioIntervalo = 0, fimIntervalo = 0;

    for (int i = 0; i < tamanhoIndices; i++) {
        if (i == tamanhoIndices - 1 || valorBuscado < (array[indices[i + 1]])) {
            inicioIntervalo = indices[i];
            fimIntervalo = (i == tamanhoIndices - 1) ? TOTAL_REGISTROS : indices[i + 1];
            *indiceTabela = i; 
            break;
        }
    }

    for (int i = inicioIntervalo; i < fimIntervalo; i++) {
        if (array[i] == valorBuscado) {
            *posicaoEncontrada = i; 
            return array[i]; 
        }
    }

    return -1; 
}

void imprimirNumeros(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

void imprimirPrimeirosEUltimosNumeros(int array[], int tamanho, int quantidade) {
    printf("Primeiros %d números do array:\n", quantidade);
    for (int i = 0; i < quantidade && i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Últimos %d números do array:\n", quantidade);
    for (int i = tamanho - quantidade; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
