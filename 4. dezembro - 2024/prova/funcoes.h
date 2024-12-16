#ifndef FUNCOES_H
    #define FUNCOES_H
    #define MAX_SALAS 14
    #define MAX_LABS 24
    #define MAX_SALAS_ADM 14
    #define MAX_SALAS_PROF 17
    #define MAX_ESPACOS 4
    #define MAX_PATIOS 2
    #define MAX_GERAIS 12
    #define MAX_MANUTENCAO 6

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

    typedef struct {
        SalaTeorica salas[MAX_SALAS];
        Laboratorio laboratorios[MAX_LABS];
        SalaAdministrativa salasAdm[MAX_SALAS_ADM];
        SalaProfessor salasProf[MAX_SALAS_PROF];
        EspacoDeUso espacos[MAX_ESPACOS];
        Patio patios[MAX_PATIOS];
        Manutencao salasMan[MAX_MANUTENCAO];
        Geral gerais[MAX_GERAIS];
    } ListaSalas;

    void cadastrarEspacos(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan, const char *tipoEspaco);

    void definirDadosIniciais(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan);

    void listarTodosEspacos(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan);

    void listarPorBloco(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan);

    void listarPorTipo(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan, const char *tipo);

    void exibirEstatisticas( SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan);
#endif
