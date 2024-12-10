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

void definirDadosIniciais(SalaTeorica *salas, Laboratorio *labs, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan) {

    //BLOCO A
    strcpy(gerais[0].bloco, "A");
    strcpy(gerais[0].descricao, "Coordenadoria de Registros Acadêmicos");
    strcpy(gerais[0].identificacao, "A106");
    gerais[0].capacidadeAtual = 35;
    gerais[0].capacidadeMaxima = 40;

    strcpy(gerais[1].bloco, "A");
    strcpy(gerais[1].descricao, "CBI - Coord. de Biblioteca");
    strcpy(gerais[1].identificacao, "A105");
    gerais[1].capacidadeAtual = 35;
    gerais[1].capacidadeMaxima = 40;

    strcpy(gerais[2].bloco, "A");
    strcpy(gerais[2].descricao, "Almoxarifado");
    strcpy(gerais[2].identificacao, "A104");
    gerais[2].capacidadeAtual = 35;
    gerais[2].capacidadeMaxima = 40;

    strcpy(gerais[3].bloco, "A");
    strcpy(gerais[3].descricao, "Sala de Estudos");
    strcpy(gerais[3].identificacao, "A103");
    gerais[3].capacidadeAtual = 35;
    gerais[3].capacidadeMaxima = 40;

    strcpy(gerais[4].bloco, "A");
    strcpy(gerais[4].descricao, "Sala de Estudos");
    strcpy(gerais[4].identificacao, "A102");
    gerais[4].capacidadeAtual = 35;
    gerais[4].capacidadeMaxima = 40;

    strcpy(espacos[0].bloco, "A");
    strcpy(espacos[0].descricao, "Biblioteca");
    strcpy(espacos[0].identificacao, "A101");
    espacos[0].capacidadeAtual = 27;
    espacos[0].capacidadeMaxima = 40;


    //BLOCO B
    strcpy(gerais[5].bloco, "B");
    strcpy(gerais[5].descricao, "Camarim");
    strcpy(gerais[5].identificacao, "B113");
    gerais[5].capacidadeAtual = 35;
    gerais[5].capacidadeMaxima = 40;

    strcpy(gerais[6].bloco, "B");
    strcpy(gerais[6].descricao, "Camarim");
    strcpy(gerais[6].identificacao, "B112");
    gerais[6].capacidadeAtual = 35;
    gerais[6].capacidadeMaxima = 40;

    strcpy(gerais[7].bloco, "B");
    strcpy(gerais[7].descricao, "Depósito");
    strcpy(gerais[7].identificacao, "B111");
    gerais[7].capacidadeAtual = 35;
    gerais[7].capacidadeMaxima = 40;

    strcpy(espacos[1].bloco, "B");
    strcpy(espacos[1].descricao, "Auditório");
    strcpy(espacos[1].identificacao, "B109");
    espacos[1].capacidadeAtual = 27;
    espacos[1].capacidadeMaxima = 40;

    strcpy(gerais[8].bloco, "B");
    strcpy(gerais[8].descricao, "Auditório");
    strcpy(gerais[8].identificacao, "B101");
    gerais[8].capacidadeAtual = 35;
    gerais[8].capacidadeMaxima = 40;

    //BLOCO C
    strcpy(salasAdm[0].bloco, "C");
    strcpy(salasAdm[0].descricao, "Dir. Adjunta Administrativa");
    strcpy(salasAdm[0].identificacao, "C109");
    salasAdm[0].capacidadeAtual = 27;
    salasAdm[0].capacidadeMaxima = 40;

    strcpy(salasAdm[1].bloco, "C");
    strcpy(salasAdm[1].descricao, "Dir. Adjunta Educacional e Coord. de Pesquisa");
    strcpy(salasAdm[1].identificacao, "C108");
    salasAdm[1].capacidadeAtual = 27;
    salasAdm[1].capacidadeMaxima = 40;

    strcpy(salasAdm[2].bloco, "C");
    strcpy(salasAdm[2].descricao, "Direção Geral");
    strcpy(salasAdm[2].identificacao, "C107");
    salasAdm[2].capacidadeAtual = 27;
    salasAdm[2].capacidadeMaxima = 40;

    strcpy(salasAdm[3].bloco, "C");
    strcpy(salasAdm[3].descricao, "NAPNE");
    strcpy(salasAdm[3].identificacao, "C106");
    salasAdm[3].capacidadeAtual = 27;
    salasAdm[3].capacidadeMaxima = 40;

    strcpy(salasAdm[4].bloco, "C");
    strcpy(salasAdm[4].descricao, "Coord. de Extensão");
    strcpy(salasAdm[4].identificacao, "C105");
    salasAdm[4].capacidadeAtual = 27;
    salasAdm[4].capacidadeMaxima = 40;

    strcpy(salasAdm[5].bloco, "C");
    strcpy(salasAdm[5].descricao, "Coord. de Gestão de Pessoas");
    strcpy(salasAdm[5].identificacao, "C104");
    salasAdm[5].capacidadeAtual = 27;
    salasAdm[5].capacidadeMaxima = 40;

    strcpy(salasAdm[6].bloco, "C");
    strcpy(salasAdm[6].descricao, "Coord. Sociopedagógica");
    strcpy(salasAdm[6].identificacao, "C103");
    salasAdm[6].capacidadeAtual = 27;
    salasAdm[6].capacidadeMaxima = 40;

    strcpy(salasAdm[7].bloco, "C");
    strcpy(salasAdm[7].descricao, "Coord. de Apoio à Direção");
    strcpy(salasAdm[7].identificacao, "C102");
    salasAdm[7].capacidadeAtual = 27;
    salasAdm[7].capacidadeMaxima = 40;

    strcpy(salasAdm[8].bloco, "C");
    strcpy(salasAdm[8].descricao, "Sala de Reuniões");
    strcpy(salasAdm[8].identificacao, "C101");
    salasAdm[8].capacidadeAtual = 27;
    salasAdm[8].capacidadeMaxima = 40;

    //BLOCO D

    strcpy(salas[0].bloco, "D");
    strcpy(salas[0].identificacao, "D106");
    salas[0].capacidadeAtual = 27;
    salas[0].capacidadeMaxima = 40;

    strcpy(salas[1].bloco, "D");
    strcpy(salas[1].identificacao, "D105");
    salas[1].capacidadeAtual = 27;
    salas[1].capacidadeMaxima = 40;

    strcpy(salas[2].bloco, "D");
    strcpy(salas[2].identificacao, "D104");
    salas[2].capacidadeAtual = 27;
    salas[2].capacidadeMaxima = 40;

    strcpy(salas[3].bloco, "D");
    strcpy(salas[3].identificacao, "D103");
    salas[3].capacidadeAtual = 27;
    salas[3].capacidadeMaxima = 40;

    strcpy(salas[4].bloco, "D");
    strcpy(salas[4].identificacao, "D102");
    salas[4].capacidadeAtual = 27;
    salas[4].capacidadeMaxima = 40;

    strcpy(salas[5].bloco, "D");
    strcpy(salas[5].identificacao, "D101");
    salas[5].capacidadeAtual = 27;
    salas[5].capacidadeMaxima = 40;

    //BLOCO E

    strcpy(labs[0].bloco, "E");
    strcpy(labs[0].descricao, "Lab. de Ensino de Matemática");
    strcpy(labs[0].identificacao, "E105");
    labs[0].capacidadeAtual = 35;
    labs[0].capacidadeMaxima = 40;

    strcpy(salas[6].bloco, "E");
    strcpy(salas[6].identificacao, "E104");
    salas[6].capacidadeAtual = 27;
    salas[6].capacidadeMaxima = 40;

    strcpy(salas[7].bloco, "E");
    strcpy(salas[7].identificacao, "E103");
    salas[7].capacidadeAtual = 27;
    salas[7].capacidadeMaxima = 40;

    strcpy(salas[8].bloco, "E");
    strcpy(salas[8].identificacao, "E102");
    salas[8].capacidadeAtual = 27;
    salas[8].capacidadeMaxima = 40;

    strcpy(salas[9].bloco, "E");
    strcpy(salas[9].identificacao, "E101");
    salas[9].capacidadeAtual = 27;
    salas[9].capacidadeMaxima = 40;

    //BLOCO F

    strcpy(labs[1].bloco, "F");
    strcpy(labs[1].descricao, "Estúdio Audiovisual");
    strcpy(labs[1].identificacao, "F104");
    labs[1].capacidadeAtual = 35;
    labs[1].capacidadeMaxima = 40;

    strcpy(salas[10].bloco, "F");
    strcpy(salas[10].identificacao, "F103");
    salas[10].capacidadeAtual = 35;
    salas[10].capacidadeMaxima = 40;

    strcpy(salas[11].bloco, "F");
    strcpy(salas[11].identificacao, "F102");
    salas[11].capacidadeAtual = 35;
    salas[11].capacidadeMaxima = 40;

    strcpy(salas[12].bloco, "F");
    strcpy(salas[12].identificacao, "F101");
    salas[12].capacidadeAtual = 35;
    salas[12].capacidadeMaxima = 40;

    //BLOCO G

    strcpy(patios[0].bloco, "G");
    strcpy(patios[0].descricao, "Pátio");
    strcpy(patios[0].identificacao, "Pátio");
    patios[0].capacidadeAtual = 35;
    patios[0].capacidadeMaxima = 40;

    strcpy(salasAdm[9].bloco, "G");
    strcpy(salasAdm[9].descricao, "Coord. de Apoio ao Ensino");
    strcpy(salasAdm[9].identificacao, "G102");
    salasAdm[9].capacidadeAtual = 35;
    salasAdm[9].capacidadeMaxima = 40;

    strcpy(salasAdm[10].bloco, "G");
    strcpy(salasAdm[10].descricao, "Coord. de Apoio ao Ensino");
    strcpy(salasAdm[10].identificacao, "G101");
    salasAdm[10].capacidadeAtual = 35;
    salasAdm[10].capacidadeMaxima = 40;

    strcpy(labs[2].bloco, "G");
    strcpy(labs[2].descricao, "Lab. Iniciação Científica");
    strcpy(labs[2].identificacao, "G107");
    labs[2].capacidadeAtual = 35;
    labs[2].capacidadeMaxima = 40;

    strcpy(gerais[9].bloco, "G");
    strcpy(gerais[9].descricao, "Cantina");
    strcpy(gerais[9].identificacao, "G103");
    gerais[9].capacidadeAtual = 35;
    gerais[9].capacidadeMaxima = 40;

    //BLOCO H
    
    strcpy(salasMan[0].bloco, "H");
    strcpy(salasMan[0].descricao, "Veículos Oficiais");
    strcpy(salasMan[0].identificacao, "H104");
    salasMan[0].capacidadeAtual = 35;
    salasMan[0].capacidadeMaxima = 40;

    strcpy(salasMan[1].bloco, "H");
    strcpy(salasMan[1].descricao, "Almoxarifado");
    strcpy(salasMan[1].identificacao, "H103");
    salasMan[1].capacidadeAtual = 35;
    salasMan[1].capacidadeMaxima = 40;

    strcpy(salasMan[2].bloco, "H");
    strcpy(salasMan[2].descricao, "Manutenção");
    strcpy(salasMan[2].identificacao, "H102");
    salasMan[2].capacidadeAtual = 35;
    salasMan[2].capacidadeMaxima = 40;

    strcpy(salasMan[3].bloco, "H");
    strcpy(salasMan[3].descricao, "Terceirizados");
    strcpy(salasMan[3].identificacao, "H101");
    salasMan[3].capacidadeAtual = 35;
    salasMan[3].capacidadeMaxima = 40;

    //BLOCO I

    strcpy(salasAdm[11].bloco, "I");
    strcpy(salasAdm[11].descricao, "CPD - Centro de Processamento de Dados");
    strcpy(salasAdm[11].identificacao, "I113");
    salasAdm[11].capacidadeAtual = 35;
    salasAdm[11].capacidadeMaxima = 40;

    strcpy(labs[3].bloco, "I");
    strcpy(labs[3].descricao, "LDA - Lab. de Desenvolvimento Avançado");
    strcpy(labs[3].identificacao, "I112");
    labs[3].capacidadeAtual = 35;
    labs[3].capacidadeMaxima = 40;

    strcpy(labs[4].bloco, "I");
    strcpy(labs[4].descricao, "LDA - Lab. de Desenvolvimento Avançado");
    strcpy(labs[4].identificacao, "I111");
    labs[4].capacidadeAtual = 35;
    labs[4].capacidadeMaxima = 40;

    strcpy(labs[5].bloco, "I");
    strcpy(labs[5].descricao, "Lab. de Química e Biologia");
    strcpy(labs[5].identificacao, "I109");
    labs[5].capacidadeAtual = 35;
    labs[5].capacidadeMaxima = 40;

    strcpy(labs[6].bloco, "I");
    strcpy(labs[6].descricao, "Lab. de Física");
    strcpy(labs[6].identificacao, "I108");
    labs[6].capacidadeAtual = 35;
    labs[6].capacidadeMaxima = 40;

    strcpy(salasAdm[12].bloco, "I");
    strcpy(salasAdm[12].descricao, "CTI - Coordenadoria de Tecnologia da Informação");
    strcpy(salasAdm[12].identificacao, "I107");
    salasAdm[12].capacidadeAtual = 35;
    salasAdm[12].capacidadeMaxima = 40;

    strcpy(labs[7].bloco, "I");
    strcpy(labs[7].descricao, "Lab. de Redes");
    strcpy(labs[7].identificacao, "I106");
    labs[7].capacidadeAtual = 35;
    labs[7].capacidadeMaxima = 40;

    strcpy(labs[8].bloco, "I");
    strcpy(labs[8].descricao, "Lab. de Hardware");
    strcpy(labs[8].identificacao, "I105");
    labs[8].capacidadeAtual = 35;
    labs[8].capacidadeMaxima = 40;

    strcpy(labs[9].bloco, "I");
    strcpy(labs[9].descricao, "Lab. de Informática");
    strcpy(labs[9].identificacao, "I104");
    labs[9].capacidadeAtual = 35;
    labs[9].capacidadeMaxima = 40;

    strcpy(labs[10].bloco, "I");
    strcpy(labs[10].descricao, "Lab. de Informática");
    strcpy(labs[10].identificacao, "I103");
    labs[10].capacidadeAtual = 35;
    labs[10].capacidadeMaxima = 40;

    strcpy(labs[11].bloco, "I");
    strcpy(labs[11].descricao, "Lab. de Informática");
    strcpy(labs[11].identificacao, "I102");
    labs[11].capacidadeAtual = 35;
    labs[11].capacidadeMaxima = 40;

    strcpy(labs[12].bloco, "I");
    strcpy(labs[12].descricao, "Lab. de Informática");
    strcpy(labs[12].identificacao, "I101");
    labs[12].capacidadeAtual = 35;
    labs[12].capacidadeMaxima = 40;

    //BLOCO J

    strcpy(labs[13].bloco, "J");
    strcpy(labs[13].descricao, "Sala de Iniciação Científica");
    strcpy(labs[13].identificacao, "J112");
    labs[13].capacidadeAtual = 35;
    labs[13].capacidadeMaxima = 40;

    strcpy(labs[14].bloco, "J");
    strcpy(labs[14].descricao, "Lab. de Eletrônica e Física Experimental");
    strcpy(labs[14].identificacao, "J110");
    labs[14].capacidadeAtual = 35;
    labs[14].capacidadeMaxima = 40;

    strcpy(labs[15].bloco, "J");
    strcpy(labs[15].descricao, "Lab. de Informática da Indústria");
    strcpy(labs[15].identificacao, "J109");
    labs[15].capacidadeAtual = 35;
    labs[15].capacidadeMaxima = 40;

    strcpy(labs[16].bloco, "J");
    strcpy(labs[16].descricao, "Lab. de Hidráulica e Pneumática");
    strcpy(labs[16].identificacao, "J108");
    labs[16].capacidadeAtual = 35;
    labs[16].capacidadeMaxima = 40;

    strcpy(labs[17].bloco, "J");
    strcpy(labs[17].descricao, "Lab. de CNC e Metrologia");
    strcpy(labs[17].identificacao, "J107");
    labs[17].capacidadeAtual = 35;
    labs[17].capacidadeMaxima = 40;

    strcpy(labs[18].bloco, "J");
    strcpy(labs[18].descricao, "Lab. de Fabricação Mecânica");
    strcpy(labs[18].identificacao, "J106");
    labs[18].capacidadeAtual = 35;
    labs[18].capacidadeMaxima = 40;

    strcpy(labs[19].bloco, "J");
    strcpy(labs[19].descricao, "Lab. de Fabricação Mecânica");
    strcpy(labs[19].identificacao, "J105");
    labs[19].capacidadeAtual = 35;
    labs[19].capacidadeMaxima = 40;

    strcpy(labs[20].bloco, "J");
    strcpy(labs[20].descricao, "Lab. de Materiais");
    strcpy(labs[20].identificacao, "J103");
    labs[20].capacidadeAtual = 35;
    labs[20].capacidadeMaxima = 40;

    strcpy(labs[21].bloco, "J");
    strcpy(labs[21].descricao, "Lab. de Eletrônica");
    strcpy(labs[21].identificacao, "J102");
    labs[21].capacidadeAtual = 35;
    labs[21].capacidadeMaxima = 40;

    strcpy(labs[22].bloco, "J");
    strcpy(labs[22].descricao, "Lab. de Robótica e CLP/Labmaker");
    strcpy(labs[22].identificacao, "J101");
    labs[22].capacidadeAtual = 35;
    labs[22].capacidadeMaxima = 40;

    //BLOCO J PISO PROFESSORES

    strcpy(salasProf[0].bloco, "J");
    strcpy(salasProf[0].identificacao, "J215");
    salasProf[0].capacidadeAtual = 35;
    salasProf[0].capacidadeMaxima = 40;

    strcpy(salasProf[1].bloco, "J");
    strcpy(salasProf[1].identificacao, "J214");
    salasProf[1].capacidadeAtual = 35;
    salasProf[1].capacidadeMaxima = 40;

    strcpy(salasProf[2].bloco, "J");
    strcpy(salasProf[2].identificacao, "J213");
    salasProf[2].capacidadeAtual = 35;
    salasProf[2].capacidadeMaxima = 40;

    strcpy(salasProf[3].bloco, "J");
    strcpy(salasProf[3].identificacao, "J212");
    salasProf[3].capacidadeAtual = 35;
    salasProf[3].capacidadeMaxima = 40;

    strcpy(salasProf[4].bloco, "J");
    strcpy(salasProf[4].identificacao, "J211");
    salasProf[4].capacidadeAtual = 35;
    salasProf[4].capacidadeMaxima = 40;

    strcpy(salasProf[5].bloco, "J");
    strcpy(salasProf[5].identificacao, "J210");
    salasProf[5].capacidadeAtual = 35;
    salasProf[5].capacidadeMaxima = 40;

    strcpy(salasProf[6].bloco, "J");
    strcpy(salasProf[6].identificacao, "J209");
    salasProf[6].capacidadeAtual = 35;
    salasProf[6].capacidadeMaxima = 40;

    strcpy(salasProf[7].bloco, "J");
    strcpy(salasProf[7].identificacao, "J208");
    salasProf[7].capacidadeAtual = 35;
    salasProf[7].capacidadeMaxima = 40;

    strcpy(salasProf[8].bloco, "J");
    strcpy(salasProf[8].identificacao, "J207");
    salasProf[8].capacidadeAtual = 35;
    salasProf[8].capacidadeMaxima = 40;

    strcpy(salasProf[9].bloco, "J");
    strcpy(salasProf[9].identificacao, "J206");
    salasProf[9].capacidadeAtual = 35;
    salasProf[9].capacidadeMaxima = 40;

    strcpy(salasProf[10].bloco, "J");
    strcpy(salasProf[10].identificacao, "J205");
    salasProf[10].capacidadeAtual = 35;
    salasProf[10].capacidadeMaxima = 40;

    strcpy(salasProf[11].bloco, "J");
    strcpy(salasProf[11].identificacao, "J204");
    salasProf[11].capacidadeAtual = 35;
    salasProf[11].capacidadeMaxima = 40;

    strcpy(salasProf[12].bloco, "J");
    strcpy(salasProf[12].identificacao, "J203");
    salasProf[12].capacidadeAtual = 35;
    salasProf[12].capacidadeMaxima = 40;

    strcpy(salasProf[13].bloco, "J");
    strcpy(salasProf[13].identificacao, "J202");
    salasProf[13].capacidadeAtual = 35;
    salasProf[13].capacidadeMaxima = 40;

    strcpy(salasProf[14].bloco, "J");
    strcpy(salasProf[14].identificacao, "J201");
    salasProf[14].capacidadeAtual = 35;
    salasProf[14].capacidadeMaxima = 40;
}

