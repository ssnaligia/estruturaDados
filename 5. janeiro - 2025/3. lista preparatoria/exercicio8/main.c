/* Implemente uma variação do programa escrito no exercício anterior, mas desta vez você deverá trabalhar
com o conceito de “listas heterogêneas”. Neste caso, você deverá armazenar objetos geométricos planos
para cálculos de área. Para simplificar, considere o armazenamento de apenas 3 tipos de objetos: retângulos,
triângulos e círculos. Implemente a operação de cálculo de área do objeto.*/

#include <stdio.h>
#include <locale.h>
#include "geometria.h"

int main() {
    Forma* lista = criarLista();
    int opcao, tipo;
    float p1, p2;

    do {
        printf("\nMenu de Opções:\n");
        printf("1 - Adicionar Forma\n");
        printf("2 - Listar Formas e Áreas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nEscolha o tipo de forma:\n");
                printf("1 - Retângulo\n2 - Triângulo\n3 - Círculo\n");
                printf("Opção: ");
                scanf("%d", &tipo);

                if (tipo == 1) { //retângulo
                    printf("\nDigite a base: ");
                    scanf("%f", &p1);
                    printf("Digite a altura: ");
                    scanf("%f", &p2);
                    lista = adicionarForma(lista, RETANGULO, p1, p2);
                } else if (tipo == 2) { //triângulo
                    printf("\nDigite a base: ");
                    scanf("%f", &p1);
                    printf("Digite a altura: ");
                    scanf("%f", &p2);
                    lista = adicionarForma(lista, TRIANGULO, p1, p2);
                } else if (tipo == 3) { //círculo
                    printf("\nDigite o raio: ");
                    scanf("%f", &p1);
                    lista = adicionarForma(lista, CIRCULO, p1, 0);
                } else {
                    printf("\nOpção inválida!\n");
                }
                break;
            case 2:
                if (lista == NULL) {
                    printf("\nNenhuma forma cadastrada.\n");
                } else {
                    imprimirFormas(lista);
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
