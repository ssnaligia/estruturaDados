#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "funcoes.h"

int main() {
    SalaTeorica *salas = malloc(MAX_SALAS * sizeof(SalaTeorica));
    Laboratorio *laboratorios = malloc(MAX_LABS * sizeof(Laboratorio));
    SalaAdministrativa *salasAdm = malloc(MAX_SALAS_ADM * sizeof(SalaAdministrativa));
    SalaProfessor *salasProf = malloc(MAX_SALAS_PROF * sizeof(SalaProfessor));
    EspacoDeUso *espacos = malloc(MAX_ESPACOS * sizeof(EspacoDeUso));
    Patio *patios = malloc(MAX_PATIOS * sizeof(Patio));
    Geral *gerais = malloc(MAX_GERAIS * sizeof(Geral));
    Manutencao *salasMan = malloc(MAX_MANUTENCAO * sizeof(Manutencao));
    ListaSalas *lista_salas = malloc(sizeof(ListaSalas));

    if (!salas || !laboratorios || !salasAdm || !salasProf || !espacos || !patios || !gerais || !salasMan) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    definirDadosIniciais(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan);

    int opcao;

    while (1) {
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
                {
                int tipoCadastro;
                int sairCadastro = 0;  
                
                while (!sairCadastro) {
                    printf("\nSubmenu - Cadastrar Espaços:\n");
                    printf("1. Sala Teórica\n");
                    printf("2. Laboratório\n");
                    printf("3. Sala Administrativa\n");
                    printf("4. Sala de Professor\n");
                    printf("5. Espaço Geral\n");
                    printf("6. Pátio\n");
                    printf("7. Manutenção\n");
                    printf("8. Salas Gerais\n");
                    printf("9. Voltar\n");
                    printf("Escolha uma opção: ");
                    scanf("%d", &tipoCadastro);

                    switch (tipoCadastro) {
                        case 1:
                            cadastrarEspacos(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "SalaTeorica");
                            break;
                        case 2:
                            cadastrarEspacos(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "Laboratorio");
                            break;
                        case 3:
                            cadastrarEspacos(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "SalaProfessor");
                            break;
                        case 4:
                            cadastrarEspacos(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "SalaAdministrativa");
                            break;
                        case 5:
                            cadastrarEspacos(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "EspacoGeral");
                            break;
                        case 6:
                            cadastrarEspacos(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "Patio");
                            break;
                        case 7:
                            cadastrarEspacos(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "Manutencao");
                            break;
                        case 8:
                            cadastrarEspacos(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "SalaGeral");
                            break;
                        case 9:
                            sairCadastro = 1; 
                            break;
                        default:
                            printf("Opção inválida.\n");
                    }
                }
            }
            break;
            case 2:
                listarTodosEspacos(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan);
                break;
            case 3:
                listarPorBloco(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan);
                break;
            case 4:
                    {
                    int tipoOpcao;
                    int sairSubmenu = 0;
                    while (!sairSubmenu) {
                        printf("\nSubmenu - Listar por Tipo:\n");
                        printf("1. Salas Teóricas\n");
                        printf("2. Laboratórios\n");
                        printf("3. Salas de Professores\n");
                        printf("4. Salas Administrativas\n");
                        printf("5. Espaços Gerais\n");
                        printf("6. Pátios\n");
                        printf("7. Manutenção\n");
                        printf("8. Salas Gerais\n");
                        printf("9. Voltar\n");
                        printf("Escolha uma opção: ");
                        scanf("%d", &tipoOpcao);

                        switch (tipoOpcao) {
                            case 1:
                                listarPorTipo(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "SalaTeorica");
                                break;
                            case 2:
                                listarPorTipo(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "Laboratorio");
                                break;
                            case 3:
                                listarPorTipo(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "SalaProfessor");
                                break;
                            case 4:
                                listarPorTipo(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "SalaAdministrativa");
                                break;
                            case 5:
                                listarPorTipo(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "EspacoGeral");
                                break;
                            case 6:
                                listarPorTipo(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "Patio");
                                break;
                            case 7:
                                listarPorTipo(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "Manutencao");
                                break;
                            case 8:
                                listarPorTipo(salas, laboratorios, salasAdm, salasProf, espacos, patios, gerais, salasMan, "SalaGeral");
                                break;
                            case 9:
                                sairSubmenu = 1;  
                                break;
                            default:
                                printf("Opção inválida.\n");
                        }
                    }
                }
                break;
            case 5:
                calcularTaxaOcupacaoPorTipo(lista_salas);
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
