/*Desenvolva um programa para armazenar um conjunto de retângulos em uma lista. Cada retângulo é
definido pela base b e pela altura h. Além das operações tradicionais, crie uma operação que calcula a área do
retângulo (fique à vontade para definir os parâmetros).*/

#include <stdio.h>
#include <locale.h>
#include "retangulo.h"

int main() {
    Retangulo* lista = criarLista();
    int opcao;
    float base, altura;

    do {
        printf("\nMenu de Opções:\n");
        printf("1 - Adicionar Retângulo\n");
        printf("2 - Listar Retângulos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite a base do retângulo: ");
                scanf("%f", &base);
                printf("\nDigite a altura do retângulo: ");
                scanf("%f", &altura);
                lista = adicionarRetangulo(lista, base, altura);
                printf("\nRetângulo adicionado!\n");
                break;
            case 2:
                if (lista == NULL) {
                    printf("\nNenhum retângulo cadastrado.\n");
                } else {
                    imprimirRetangulos(lista);
                }
                break;
            case 0:
                printf("\nSaindo...\n");
                liberarLista(lista);
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
