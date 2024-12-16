#ifndef FUNCOES_H
    #define FUNCOES_H
    #define MAX_SALAS 13
    #define MAX_LABS 23
    #define MAX_SALAS_ADM 13
    #define MAX_SALAS_PROF 15
    #define MAX_ESPACOS 2
    #define MAX_PATIOS 2
    #define MAX_GERAIS 10
    #define MAX_MANUTENCAO 4

    typedef struct {
        char bloco[2];
        char identificacao[8];
        int capacidadeAtual;
        int capacidadeMaxima;
    } SalaTeorica;

    typedef struct {
        char bloco[2];
        char descricao[50];
        char identificacao[4];
        int capacidadeAtual;
        int capacidadeMaxima;
    } Laboratorio;

    typedef struct {
        char bloco[2];
        char identificacao[4];
        int capacidadeAtual;
        int capacidadeMaxima;
    } SalaProfessor;

    typedef struct {
        char bloco[2];
        char descricao[50];
        char identificacao[4];
        int capacidadeAtual;
        int capacidadeMaxima;
    } EspacoDeUso;

    typedef struct {
        char bloco[2];
        char descricao[50];
        char identificacao[4];
        int capacidadeAtual;
        int capacidadeMaxima;
    } SalaAdministrativa;

    typedef struct {
        char bloco[2];
        char descricao[50];
        char identificacao[4];
        int capacidadeAtual;
        int capacidadeMaxima;
    } Patio;

    typedef struct {
        char bloco[2];
        char descricao[50];
        char identificacao[4];
        int capacidadeAtual;
        int capacidadeMaxima;
    } Manutencao;

    typedef struct {
        char bloco[2];
        char descricao[50];
        char identificacao[4];
        int capacidadeAtual;
        int capacidadeMaxima;
    } Geral;

    void cadastrarEspacos(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan);

    void listarTodosEspacos(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan);

    void listarPorBloco(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan);

    void listarPorTipo(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan);

    void exibirEstatisticas(SalaTeorica *salas, Laboratorio *laboratorios);
#endif
