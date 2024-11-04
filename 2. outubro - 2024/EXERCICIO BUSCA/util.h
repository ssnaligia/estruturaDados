#ifndef UTIL_H
#define UTIL_H

#define INTERVALO_INDEX 1000
#define NUMEROS_EXIBIR 10 

void carregarNumerosOrdenados(int array[], int tamanho);
void criarTabelaIndices(int array[], int indices[], int tamanho);
int buscaSequencialIndexada(int array[], int indices[], int tamanhoIndices, int valorBuscado, int *posicaoEncontrada, int *indiceTabela);
void imprimirNumeros(int array[], int tamanho);
void imprimirPrimeirosEUltimosNumeros(int array[], int tamanho, int quantidade);

#endif // UTIL_H
