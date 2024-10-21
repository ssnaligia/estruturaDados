#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000     // Tamanho do array (1 milhão de registros)
#define BLOCK_SIZE 1000  // Tamanho do bloco para a tabela de índices
#define INDEX_SIZE (SIZE / BLOCK_SIZE)  // Tamanho da tabela de índices
#define MAX_VALUE 1000000  // Valor máximo permitido para os números

// Função para carregar o arquivo de números ordenados
void load_file_classified(int array[], int size) {
    srand((unsigned) time(NULL));

    array[0] = rand() % MAX_VALUE;
    for (int i = 1; i < size; i++) {
        int incremento = rand() % 1000;  // Gera um incremento aleatório entre 0 e 999
        if (array[i-1] + incremento >= MAX_VALUE) {
            array[i] = MAX_VALUE;  // Limita ao valor máximo
        } else {
            array[i] = array[i-1] + incremento;  // Adiciona incremento
        }
    }
}

// Função para imprimir o array
void print_file(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

// Função para criar a tabela de índices
void criar_indice(int array[], int index[], int block_size, int index_size) {
    for (int i = 0; i < index_size; i++) {
        index[i] = array[i * block_size];  // Primeiro valor de cada bloco
    }
}

// Função para realizar a busca sequencial em um bloco específico
int busca_sequencial(int array[], int inicio, int fim, int chave) {
    for (int i = inicio; i <= fim; i++) {
        if (array[i] == chave) {
            return i;  // Retorna o índice da chave se for encontrada
        }
    }
    return -1;  // Retorna -1 se a chave não for encontrada
}

// Função para realizar a busca sequencial indexada
int busca_indexada(int array[], int index[], int chave, int block_size, int index_size) {
    int bloco = -1;

    // Primeiro, localizamos o bloco correto através do índice
    for (int i = 0; i < index_size; i++) {
        if (chave < index[i]) {
            bloco = i - 1;  // A chave está no bloco anterior
            break;
        }
    }
    if (bloco == -1) {
        bloco = index_size - 1;  // Se a chave for maior que todos, pode estar no último bloco
    }

    // Definimos os limites do bloco
    int inicio = bloco * block_size;
    int fim = (bloco + 1) * block_size - 1;
    if (fim >= SIZE) fim = SIZE - 1;  // Limitar o fim ao tamanho total do array

    // Realizamos a busca sequencial no bloco determinado
    return busca_sequencial(array, inicio, fim, chave);
}

int main() {
    int arquivo[SIZE];  // Array principal
    int indice[INDEX_SIZE];  // Tabela de índices

    // Carrega o arquivo com os números ordenados
    load_file_classified(arquivo, SIZE);

    // Cria a tabela de índices
    criar_indice(arquivo, indice, BLOCK_SIZE, INDEX_SIZE);

    // Teste de busca sequencial indexada
    int chave;
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &chave);

    int resultado = busca_indexada(arquivo, indice, chave, BLOCK_SIZE, INDEX_SIZE);

    if (resultado != -1) {
        printf("Chave %d encontrada na posição %d\n", chave, resultado);
    } else {
        printf("Chave %d não encontrada.\n", chave);
    }

    return 0;
}
