#ifndef FUNCOES_H
    #define FUNCOES_H

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
    } Auditorio;

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

    double calcularTaxaOcupacao(SalaTeorica *salas, int quantidadeSalas);
    int calcularComputadoresNecessarios(Laboratorio *labs, int quantidadeLabs);
    void exibirEspacosOrdenados(SalaTeorica *salas, int quantidadeSalas, Laboratorio *labs, int quantidadeLabs);
    void definirDadosIniciais(SalaTeorica *salas, Laboratorio *labs, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan);
#endif
