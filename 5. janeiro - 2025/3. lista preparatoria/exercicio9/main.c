/*. Implemente um código para controle de pouso de aviões em um aeroporto. Utilize o conceito de fila
dinâmica e considere uma característica adicional em relação à fila comum: prioridade. Faça o controle de
prioridade de acordo com o combustível disponível nos aviões que aguardam na fila.
Observe que as operações de inserção, remoção e consulta deverão considerar a prioridade do elemento para
ordenação. Implemente utilizando lista dinâmica encadeada. Coloque comentários no início do seu código
justificando sua lógica.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "aeroporto.h"

int main() {
    FilaPrioridade* fila = criarFila();
    int opcao;
    char id[10];
    int combustivel;

    do {
        printf("\nMenu de Controle de Pouso:\n");
        printf("1 - Adicionar Avião à Fila\n");
        printf("2 - Autorizar Pouso (Remover Avião)\n");
        printf("3 - Listar Aviões na Fila\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite o ID do avião: ");
                scanf("%s", id);
                printf("Digite o nível de combustível: ");
                scanf("%d", &combustivel);
                inserirAviao(fila, id, combustivel);
                break;
            case 2:
                pousarAviao(fila);
                break;
            case 3:
                listarFila(fila);
                break;
            case 0:
                printf("\nEncerrando o sistema...\n");
                liberarFila(fila);
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
