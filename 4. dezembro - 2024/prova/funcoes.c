#include <stdio.h>
#include <string.h>
#include "funcoes.h"

double calcularTaxaOcupacao(SalaTeorica *salas, int quantidadeSalas) {
    int somaAtual = 0, somaMaxima = 0;
    for (int i = 0; i < quantidadeSalas; i++) {
        somaAtual += salas[i].capacidadeAtual;
        somaMaxima += salas[i].capacidadeMaxima;
    }
    return (double)somaAtual / somaMaxima;
}

int calcularComputadoresNecessarios(Laboratorio *labs, int quantidadeLabs) {
    int totalNecessario = 0;
    for (int i = 0; i < quantidadeLabs; i++) {
        if (labs[i].capacidadeAtual < labs[i].capacidadeMaxima) {
            totalNecessario += labs[i].capacidadeMaxima - labs[i].capacidadeAtual;
        }
    }
    return totalNecessario;
}

void exibirEspacosOrdenados(SalaTeorica *salas, int quantidadeSalas, Laboratorio *labs, int quantidadeLabs) {
    int total = quantidadeSalas + quantidadeLabs;
    int capacidades[total];
    char descricoes[total][50];

    for (int i = 0; i < quantidadeSalas; i++) {
        capacidades[i] = salas[i].capacidadeMaxima;
        sprintf(descricoes[i], "Sala Teórica %s%s", salas[i].bloco, salas[i].identificacao);
    }

    for (int i = 0; i < quantidadeLabs; i++) {
        capacidades[quantidadeSalas + i] = labs[i].capacidadeMaxima;
        sprintf(descricoes[quantidadeSalas + i], "Laboratório %s%s", labs[i].bloco, labs[i].identificacao);
    }

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (capacidades[i] < capacidades[j]) {
                int temp = capacidades[i];
                capacidades[i] = capacidades[j];
                capacidades[j] = temp;

                char tempDesc[50];
                strcpy(tempDesc, descricoes[i]);
                strcpy(descricoes[i], descricoes[j]);
                strcpy(descricoes[j], tempDesc);
            }
        }
    }

    printf("\n");
    for (int i = 0; i < total; i++) {
        printf("%s - Capacidade Máxima: %d\n", descricoes[i], capacidades[i]);
    }
}

void definirDadosIniciais(SalaTeorica *salas, Laboratorio *labs) {
    strcpy(salas[0].bloco, "E");
    strcpy(salas[0].identificacao, "01");
    salas[0].capacidadeAtual = 27;
    salas[0].capacidadeMaxima = 40;

    strcpy(salas[1].bloco, "F");
    strcpy(salas[1].identificacao, "01");
    salas[1].capacidadeAtual = 35;
    salas[1].capacidadeMaxima = 40;

    strcpy(salas[2].bloco, "F");
    strcpy(salas[2].identificacao, "02");
    salas[2].capacidadeAtual = 40;
    salas[2].capacidadeMaxima = 40;

    strcpy(labs[0].bloco, "I");
    strcpy(labs[0].identificacao, "111");
    labs[0].capacidadeAtual = 30;
    labs[0].capacidadeMaxima = 30;

    strcpy(labs[1].bloco, "I");
    strcpy(labs[1].identificacao, "112");
    labs[1].capacidadeAtual = 30;
    labs[1].capacidadeMaxima = 40;
}
