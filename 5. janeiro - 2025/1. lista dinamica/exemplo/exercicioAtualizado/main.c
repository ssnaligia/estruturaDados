#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int main(){
    elemento aluno;
    Lista *inicio = criaLista(); /*cria ponteiro especial (inicio**) que aponta
								para outro ponteiro (Lista*), que é ponteiro para struct com 2 campos (tipoNo)
								desta forma, o "início" da lista é ponteiro para ponteiro*/
    int opcao;

    do {
        printf("\n\n--- MENU ---\n\n");
        printf("1. Inserir elemento no início\n");
        printf("2. Inserir elemento no final\n");
        printf("3. Inserir ordenado pela matrícula\n");
        printf("4. Remover elemento do início\n");
        printf("5. Remover elemento do final\n");
        printf("6. Remover elemento pela matrícula\n");
        printf("7. Exibir a lista\n");
        printf("8. Exibir a quantidade de elementos na lista\n");
        printf("9. Sair\n");
        printf("\nDigite a opção escolhida: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\nDigite a matrícula: ");
            scanf("%d", &aluno.matricula);
            printf("Digite o nome do aluno: ");
            scanf("%s", aluno.nome);
            aluno.n1 = 0;
            aluno.n2 = 0;
            aluno.n3 = 0;
            insereInicio(inicio, aluno);
            break;
        case 2:
            printf("\nDigite a matrícula: ");
            scanf("%d", &aluno.matricula);
            printf("Digite o nome do aluno: ");
            scanf("%s", aluno.nome);
            aluno.n1 = 0;
            aluno.n2 = 0;
            aluno.n3 = 0;
            insereFinal(inicio, aluno);
            break;
        case 3:
            printf("\nDigite a matrícula: ");
            scanf("%d", &aluno.matricula);
            printf("Digite o nome do aluno: ");
            scanf("%s", aluno.nome);
            aluno.n1 = 0;
            aluno.n2 = 0;
            aluno.n3 = 0;
            insereOrdenado(inicio, aluno);
            break;
        case 4:
            removeInicio(inicio);
            break;
        case 5:
            removeFinal(inicio);
            break;  
        case 6:
            printf("\nDigite a matrícula: ");
            scanf("%d", &aluno.matricula);
            removeMatricula(inicio, aluno);
            break;
        case 7:
            imprimeLista(inicio);
            break;
        case 8:
            quantidadeElemento(inicio);
            break;
        case 9:
            printf("\nSaindo do programa...");
            break;
        default:
            printf("\nOpção Inválida!");
            break;
        }
    } while(opcao != 9);
    apagaLista(inicio);
    return 0;
}
