#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_REGISTROS 1000000
#define INTERVALO_INDEX 1000
#define NUMEROS_EXIBIR 10 

void carregarNumerosOrdenados(int array[], int tamanho);
void criarTabelaIndices(int array[], int indices[], int tamanho);
int buscaSequencialIndexada(int array[], int indices[], int tamanhoIndices, int valorBuscado, int *posicaoEncontrada, int *indiceTabela);
void imprimirNumeros(int array[], int tamanho);
void imprimirPrimeirosEUltimosNumeros(int array[], int tamanho, int quantidade);
