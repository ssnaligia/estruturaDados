#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(int argc, char const *argv[]) {
    int arrayNumerosOrdenados[TOTAL_REGISTROS];
    int indices[TOTAL_REGISTROS / INTERVALO_INDEX];

    //1: carrega números ordenados
    carregarNumerosOrdenados(arrayNumerosOrdenados, TOTAL_REGISTROS);

    //2: cria tabela de índices
    criarTabelaIndices(arrayNumerosOrdenados, indices, TOTAL_REGISTROS);

    //3: exibe os primeiros e últimos números do array (só para testar)
    imprimirPrimeirosEUltimosNumeros(arrayNumerosOrdenados, TOTAL_REGISTROS, NUMEROS_EXIBIR);

    //4: loop para pedir valores buscados ao usuário
    while (1) {
        int valorBuscado;
        printf("Digite o valor que deseja buscar (0 a %d) ou um número negativo para sair: ", arrayNumerosOrdenados[TOTAL_REGISTROS - 1]);
        scanf("%d", &valorBuscado);

        // Verifica se o valor buscado é negativo, caso sim, sai do loop
        if (valorBuscado < 0) {
            printf("Saindo do programa...\n");
            break;
        }

        //5: realiza busca sequencial indexada
        int posicaoEncontrada = -1, indiceTabela = -1;
        int resultado = buscaSequencialIndexada(arrayNumerosOrdenados, indices, TOTAL_REGISTROS / INTERVALO_INDEX, valorBuscado, &posicaoEncontrada, &indiceTabela);

        //exibe resultado da busca
        if (resultado != -1) {
            printf("Valor %d encontrado na posição %d e no índice %d da tabela de índices.\n", resultado, posicaoEncontrada, indiceTabela);
        } else {
            printf("Valor %d não encontrado!\n", valorBuscado);
        }
    }

    return 0;
}
