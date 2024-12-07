#include <stdio.h>
#include "funcoes.h"

int main() {
    SalaTeorica salas[3];
    Laboratorio labs[2];

    definirDadosIniciais(salas, labs);

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Taxa de Ocupação das Salas Teóricas\n");
        printf("2. Computadores Necessários nos Laboratórios\n");
        printf("3. Exibir Espaços Ordenados por Capacidade Máxima\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nTaxa de Ocupação: %.2f%%\n", calcularTaxaOcupacao(salas, 3) * 100);
                break;
            case 2:
                printf("\nComputadores Necessários: %d\n", calcularComputadoresNecessarios(labs, 2));
                break;
            case 3:
                exibirEspacosOrdenados(salas, 3, labs, 2);
                break;
            case 4:
                printf("\nEncerrando o programa.\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
