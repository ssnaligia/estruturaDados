#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.c"


int main(){
    elemento aluno;

    Lista *inicio = criaLista(); /*cria ponteiro especial (inicio**) que aponta
								para outro ponteiro (Lista*), que é ponteiro para struct com 2 campos (tipoNo)
								desta forma, o "início" da lista é ponteiro para ponteiro*/
    int opcao;

    do {
        printf("--- MENU ---\n\n");
        printf("1. Inserir elemento no início\n");
        printf("2. Inserir elemento no final\n");
        printf("3. Inserir ordenado pela matrícula\n");
        printf("4. Remover elemento do início\n");
        printf("5. Remover elemento do final\n");
        printf("6. Remover elemento pela matrícula\n");
        printf("7. Exibir a lista\n");
        printf("8. Exibir a quantidade de elementos na lista\n");
        printf("9. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\nDigite a matrícula: ");
            scanf("%d", &aluno.matricula);
            printf("\nDigite o nome do aluno: ");
            scanf("%s", aluno.nome);
            aluno.n1 = 0;
            aluno.n2 = 0;
            aluno.n3 = 0;
            insereInicio(inicio, aluno);
            break;
        case 2:
            printf("\nDigite a matrícula: ");
            scanf("%d", &aluno.matricula);
            printf("\nDigite o nome do aluno: ");
            scanf("%s", aluno.nome);
            aluno.n1 = 0;
            aluno.n2 = 0;
            aluno.n3 = 0;
            insereFinal(inicio, aluno);
            break;
        case 3:
            removeInicio(inicio);
            break;
        case 4:
            removeFinal(inicio);
            break;                                                                                              
        default:
            break;
        }
    } while(opcao != 8);
    apagaLista(inicio);
    return 0;
}
