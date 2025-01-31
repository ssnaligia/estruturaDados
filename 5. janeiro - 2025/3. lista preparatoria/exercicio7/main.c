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
                printf("Digite a base do retângulo: ");
                scanf("%f", &base);
                printf("Digite a altura do retângulo: ");
                scanf("%f", &altura);
                lista = adicionarRetangulo(lista, base, altura);
                printf("Retângulo adicionado!\n");
                break;
            case 2:
                if (lista == NULL) {
                    printf("Nenhum retângulo cadastrado.\n");
                } else {
                    imprimirRetangulos(lista);
                }
                break;
            case 0:
                printf("Saindo...\n");
                liberarLista(lista);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
