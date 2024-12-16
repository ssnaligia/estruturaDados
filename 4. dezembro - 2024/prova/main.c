#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

#define MAX_SALAS 12
#define MAX_LABS 22
#define MAX_SALAS_ADM 12
#define MAX_SALAS_PROF 14
#define MAX_ESPACOS 1
#define MAX_PATIOS 0
#define MAX_GERAIS 9
#define MAX_MANUTENCAO 3

int main() {
    SalaTeorica *salas = malloc(MAX_SALAS * sizeof(SalaTeorica));
    Laboratorio *laboratorios = malloc(MAX_LABS * sizeof(Laboratorio));
    SalaAdministrativa *salasAdm = malloc(MAX_SALAS_ADM * sizeof(SalaAdministrativa));
    SalaProfessor *salasProf = malloc(MAX_SALAS_PROF * sizeof(SalaProfessor));
    EspacoDeUso *espacos = malloc(MAX_ESPACOS * sizeof(EspacoDeUso));
    Patio *patios = malloc(MAX_PATIOS * sizeof(Patio));
    Geral *gerais = malloc(MAX_GERAIS * sizeof(Geral));
    Manutencao *salasMan = malloc(MAX_MANUTENCAO * sizeof(Manutencao));

    if (!salas || !laboratorios || !salasAdm || !salasProf || !espacos || !patios || !gerais || !salasMan) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    definirDadosIniciais(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan);

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Espaços\n");
        printf("2. Listar Todos Cadastrados\n");
        printf("3. Listar por Bloco\n");
        printf("4. Listar por Tipo\n");
        printf("5. Estatísticas e dados de ocupação\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarEspacos(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan);
                break;
            case 2:
                listarTodosEspacos(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan);
                break;
            case 3:
                listarPorBloco(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan);
                break;
            case 4:
                listarPorTipo(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan);
                break;
            case 5:
                exibirEstatisticas(salas, laboratorios);
                break;
            case 6:
                printf("\nEncerrando o programa.\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);

    free(salas);
    free(laboratorios);
    free(salasAdm);
    free(salasProf);
    free(espacos);
    free(patios);
    free(gerais);
    free(salasMan);

    return 0;
}
