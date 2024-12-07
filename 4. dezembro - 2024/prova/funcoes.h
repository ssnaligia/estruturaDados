#ifndef FUNCOES_H
    #define FUNCOES_H

    typedef struct {
        char bloco[2];
        char identificacao[4];
        int capacidadeAtual;
        int capacidadeMaxima;
    } SalaTeorica;

    typedef struct {
        char bloco[2];
        char identificacao[4];
        int capacidadeAtual;
        int capacidadeMaxima;
    } Laboratorio;

    double calcularTaxaOcupacao(SalaTeorica *salas, int quantidadeSalas);
    int calcularComputadoresNecessarios(Laboratorio *labs, int quantidadeLabs);
    void exibirEspacosOrdenados(SalaTeorica *salas, int quantidadeSalas, Laboratorio *labs, int quantidadeLabs);
    void definirDadosIniciais(SalaTeorica *salas, Laboratorio *labs);
#endif
