#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

int indexSalaTeorica = 10;
int indexLaboratorio = 18;
int indexSalaAdm = 10;
int indexEspacoGeral = 2;
int indexSalaProfessor = 15;
int indexPatio = 1;
int indexGeral = 10;
int indexManutencao = 4;

void definirDadosIniciais(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan) {
    //BLOCO A
    strcpy(gerais[0].bloco, "A"); strcpy(gerais[0].descricao, "Coordenadoria de Registros Acadêmicos"); strcpy(gerais[0].identificacao, "A106"); gerais[0].capacidadeAtual = 25; gerais[0].capacidadeMaxima = 40;
    strcpy(gerais[1].bloco, "A"); strcpy(gerais[1].descricao, "CBI - Coord. de Biblioteca"); strcpy(gerais[1].identificacao, "A105"); gerais[1].capacidadeAtual = 20; gerais[1].capacidadeMaxima = 40;
    strcpy(gerais[2].bloco, "A"); strcpy(gerais[2].descricao, "Almoxarifado"); strcpy(gerais[2].identificacao, "A104"); gerais[2].capacidadeAtual = 25; gerais[2].capacidadeMaxima = 30;
    strcpy(gerais[3].bloco, "A"); strcpy(gerais[3].descricao, "Sala de Estudos"); strcpy(gerais[3].identificacao, "A103"); gerais[3].capacidadeAtual = 35; gerais[3].capacidadeMaxima = 45;
    strcpy(gerais[4].bloco, "A"); strcpy(gerais[4].descricao, "Sala de Estudos"); strcpy(gerais[4].identificacao, "A102"); gerais[4].capacidadeAtual = 20; gerais[4].capacidadeMaxima = 35;
    strcpy(espacos[0].bloco, "A"); strcpy(espacos[0].descricao, "Biblioteca"); strcpy(espacos[0].identificacao, "A101"); espacos[0].capacidadeAtual = 35; espacos[0].capacidadeMaxima = 50;

    //BLOCO B
    strcpy(gerais[5].bloco, "B"); strcpy(gerais[5].descricao, "Camarim"); strcpy(gerais[5].identificacao, "B113"); gerais[5].capacidadeAtual = 15; gerais[5].capacidadeMaxima = 20;
    strcpy(gerais[6].bloco, "B"); strcpy(gerais[6].descricao, "Camarim"); strcpy(gerais[6].identificacao, "B112"); gerais[6].capacidadeAtual = 15; gerais[6].capacidadeMaxima = 20;
    strcpy(gerais[7].bloco, "B"); strcpy(gerais[7].descricao, "Depósito"); strcpy(gerais[7].identificacao, "B111"); gerais[7].capacidadeAtual = 10; gerais[7].capacidadeMaxima = 15;
    strcpy(espacos[1].bloco, "B"); strcpy(espacos[1].descricao, "Auditório"); strcpy(espacos[1].identificacao, "B109"); espacos[1].capacidadeAtual = 50; espacos[1].capacidadeMaxima = 110;
    strcpy(gerais[8].bloco, "B"); strcpy(gerais[8].descricao, "Auditório"); strcpy(gerais[8].identificacao, "B101"); gerais[8].capacidadeAtual = 30; gerais[8].capacidadeMaxima = 40;

    //BLOCO C
    //strcpy(salasAdm[6].bloco, "C"); strcpy(salasAdm[6].descricao, "Coord. Sociopedagógica"); strcpy(salasAdm[6].identificacao, "C103"); salasAdm[6].capacidadeAtual = 27; salasAdm[6].capacidadeMaxima = 40;
    strcpy(salasAdm[0].bloco, "C"); strcpy(salasAdm[0].descricao, "Dir. Adjunta Administrativa"); strcpy(salasAdm[0].identificacao, "C109"); salasAdm[0].capacidadeAtual = 10; salasAdm[0].capacidadeMaxima = 20;
    strcpy(salasAdm[1].bloco, "C"); strcpy(salasAdm[1].descricao, "Dir. Adjunta Educacional e Coord. de Pesquisa"); strcpy(salasAdm[1].identificacao, "C108"); salasAdm[1].capacidadeAtual = 10; salasAdm[1].capacidadeMaxima = 25;
    strcpy(salasAdm[2].bloco, "C"); strcpy(salasAdm[2].descricao, "Direção Geral"); strcpy(salasAdm[2].identificacao, "C107"); salasAdm[2].capacidadeAtual = 12; salasAdm[2].capacidadeMaxima = 22;
    strcpy(salasAdm[3].bloco, "C"); strcpy(salasAdm[3].descricao, "NAPNE"); strcpy(salasAdm[3].identificacao, "C106"); salasAdm[3].capacidadeAtual = 10; salasAdm[3].capacidadeMaxima = 20;
    strcpy(salasAdm[4].bloco, "C"); strcpy(salasAdm[4].descricao, "Coord. de Extensão"); strcpy(salasAdm[4].identificacao, "C105"); salasAdm[4].capacidadeAtual = 15; salasAdm[4].capacidadeMaxima = 20;
    strcpy(salasAdm[5].bloco, "C"); strcpy(salasAdm[5].descricao, "Coord. de Gestão de Pessoas"); strcpy(salasAdm[5].identificacao, "C104"); salasAdm[5].capacidadeAtual = 10; salasAdm[5].capacidadeMaxima = 15;
    strcpy(salasAdm[6].bloco, "C"); strcpy(salasAdm[6].descricao, "Coord. de Apoio à Direção"); strcpy(salasAdm[6].identificacao, "C102"); salasAdm[6].capacidadeAtual = 10; salasAdm[6].capacidadeMaxima = 15;
    strcpy(salasAdm[7].bloco, "C"); strcpy(salasAdm[7].descricao, "Sala de Reuniões"); strcpy(salasAdm[7].identificacao, "C101"); salasAdm[7].capacidadeAtual = 20; salasAdm[7].capacidadeMaxima = 25;

    //BLOCO D
    //strcpy(salas[0].bloco, "D"); strcpy(salas[0].identificacao, "D106"); salas[0].capacidadeAtual = 27; salas[0].capacidadeMaxima = 40;
    //strcpy(salas[1].bloco, "D"); strcpy(salas[1].identificacao, "D105"); salas[1].capacidadeAtual = 27; salas[1].capacidadeMaxima = 40;
    strcpy(salas[0].bloco, "D"); strcpy(salas[0].identificacao, "D104"); salas[0].capacidadeAtual = 30; salas[0].capacidadeMaxima = 45;
    strcpy(salas[1].bloco, "D"); strcpy(salas[1].identificacao, "D103"); salas[1].capacidadeAtual = 25; salas[1].capacidadeMaxima = 40;
    strcpy(salas[2].bloco, "D"); strcpy(salas[2].identificacao, "D102"); salas[2].capacidadeAtual = 25; salas[2].capacidadeMaxima = 45;
    strcpy(salas[3].bloco, "D"); strcpy(salas[3].identificacao, "D101"); salas[3].capacidadeAtual = 32; salas[3].capacidadeMaxima = 40;

    //BLOCO E
    //strcpy(laboratorios[0].bloco, "E"); strcpy(laboratorios[0].descricao, "Lab. de Ensino de Matemática"); strcpy(laboratorios[0].identificacao, "E105"); laboratorios[0].capacidadeAtual = 35; laboratorios[0].capacidadeMaxima = 40;
    //strcpy(salas[6].bloco, "E"); strcpy(salas[6].identificacao, "E104"); salas[6].capacidadeAtual = 27; salas[6].capacidadeMaxima = 40;
    strcpy(salas[4].bloco, "E"); strcpy(salas[4].identificacao, "E103"); salas[4].capacidadeAtual = 27; salas[4].capacidadeMaxima = 35;
    strcpy(salas[5].bloco, "E"); strcpy(salas[5].identificacao, "E102"); salas[5].capacidadeAtual = 22; salas[5].capacidadeMaxima = 40;
    strcpy(salas[6].bloco, "E"); strcpy(salas[6].identificacao, "E101"); salas[6].capacidadeAtual = 35; salas[6].capacidadeMaxima = 45;

    //BLOCO F
    //strcpy(laboratorios[1].bloco, "F"); strcpy(laboratorios[1].descricao, "Estúdio Audiovisual"); strcpy(laboratorios[1].identificacao, "F104"); laboratorios[1].capacidadeAtual = 35; laboratorios[1].capacidadeMaxima = 40;
    strcpy(salas[7].bloco, "F"); strcpy(salas[7].identificacao, "F103"); salas[7].capacidadeAtual = 28; salas[7].capacidadeMaxima = 35;
    strcpy(salas[8].bloco, "F"); strcpy(salas[8].identificacao, "F102"); salas[8].capacidadeAtual = 30; salas[8].capacidadeMaxima = 42;
    strcpy(salas[9].bloco, "F"); strcpy(salas[9].identificacao, "F101"); salas[9].capacidadeAtual = 34; salas[9].capacidadeMaxima = 40;

    //BLOCO G
    //strcpy(salasAdm[9].bloco, "G"); strcpy(salasAdm[9].descricao, "Coord. de Apoio ao Ensino"); strcpy(salasAdm[9].identificacao, "G102"); salasAdm[9].capacidadeAtual = 35; salasAdm[9].capacidadeMaxima = 40;
    strcpy(patios[0].bloco, "G"); strcpy(patios[0].descricao, "Pátio"); strcpy(patios[0].identificacao, "Pátio"); patios[0].capacidadeAtual = 50; patios[0].capacidadeMaxima = 65;
    strcpy(salasAdm[8].bloco, "G"); strcpy(salasAdm[8].descricao, "Coord. de Apoio ao Ensino"); strcpy(salasAdm[8].identificacao, "G101"); salasAdm[8].capacidadeAtual = 10; salasAdm[8].capacidadeMaxima = 15;
    strcpy(laboratorios[0].bloco, "G"); strcpy(laboratorios[0].descricao, "Lab. Iniciação Científica"); strcpy(laboratorios[0].identificacao, "G107"); laboratorios[0].capacidadeAtual = 10; laboratorios[0].capacidadeMaxima = 20;
    strcpy(gerais[9].bloco, "G"); strcpy(gerais[9].descricao, "Cantina"); strcpy(gerais[9].identificacao, "G103"); gerais[9].capacidadeAtual = 12; gerais[9].capacidadeMaxima = 20;

    //BLOCO H
    strcpy(salasMan[0].bloco, "H"); strcpy(salasMan[0].descricao, "Veículos Oficiais"); strcpy(salasMan[0].identificacao, "H104"); salasMan[0].capacidadeAtual = 5; salasMan[0].capacidadeMaxima = 10;
    strcpy(salasMan[1].bloco, "H"); strcpy(salasMan[1].descricao, "Almoxarifado"); strcpy(salasMan[1].identificacao, "H103"); salasMan[1].capacidadeAtual = 7; salasMan[1].capacidadeMaxima = 12;
    strcpy(salasMan[2].bloco, "H"); strcpy(salasMan[2].descricao, "Manutenção"); strcpy(salasMan[2].identificacao, "H102"); salasMan[2].capacidadeAtual = 14; salasMan[2].capacidadeMaxima = 20;
    strcpy(salasMan[3].bloco, "H"); strcpy(salasMan[3].descricao, "Terceirizados"); strcpy(salasMan[3].identificacao, "H101"); salasMan[3].capacidadeAtual = 10; salasMan[3].capacidadeMaxima = 15;

   // BLOCO I
    //strcpy(laboratorios[4].bloco, "I"); strcpy(laboratorios[4].descricao, "LDA - Lab. de Desenvolvimento Avançado"); strcpy(laboratorios[4].identificacao, "I111"); laboratorios[4].capacidadeAtual = 35; laboratorios[4].capacidadeMaxima = 40;
    //strcpy(salasAdm[12].bloco, "I"); strcpy(salasAdm[12].descricao, "CTI - Coordenadoria de Tecnologia da Informação"); strcpy(salasAdm[12].identificacao, "I107"); salasAdm[12].capacidadeAtual = 35; salasAdm[12].capacidadeMaxima = 40;
    //strcpy(laboratorios[12].bloco, "I"); strcpy(laboratorios[12].descricao, "Lab. de Informática"); strcpy(laboratorios[12].identificacao, "I101"); laboratorios[12].capacidadeAtual = 35; laboratorios[12].capacidadeMaxima = 40;
    strcpy(salasAdm[9].bloco, "I"); strcpy(salasAdm[9].descricao, "CPD - Centro de Processamento de Dados"); strcpy(salasAdm[9].identificacao, "I113"); salasAdm[9].capacidadeAtual = 5; salasAdm[9].capacidadeMaxima = 10;
    strcpy(laboratorios[1].bloco, "I"); strcpy(laboratorios[1].descricao, "LDA - Lab. de Desenvolvimento Avançado"); strcpy(laboratorios[1].identificacao, "I112"); laboratorios[1].capacidadeAtual = 22; laboratorios[1].capacidadeMaxima = 25;
    strcpy(laboratorios[2].bloco, "I"); strcpy(laboratorios[2].descricao, "Lab. de Química e Biologia"); strcpy(laboratorios[2].identificacao, "I109"); laboratorios[2].capacidadeAtual = 20; laboratorios[2].capacidadeMaxima = 30;
    strcpy(laboratorios[3].bloco, "I"); strcpy(laboratorios[3].descricao, "Lab. de Física"); strcpy(laboratorios[3].identificacao, "I108"); laboratorios[3].capacidadeAtual = 22; laboratorios[3].capacidadeMaxima = 25;
    strcpy(laboratorios[4].bloco, "I"); strcpy(laboratorios[4].descricao, "Lab. de Redes"); strcpy(laboratorios[4].identificacao, "I106"); laboratorios[4].capacidadeAtual = 15; laboratorios[4].capacidadeMaxima = 25;
    strcpy(laboratorios[5].bloco, "I"); strcpy(laboratorios[5].descricao, "Lab. de Hardware"); strcpy(laboratorios[5].identificacao, "I105"); laboratorios[5].capacidadeAtual = 15; laboratorios[5].capacidadeMaxima = 30;
    strcpy(laboratorios[6].bloco, "I"); strcpy(laboratorios[6].descricao, "Lab. de Informática"); strcpy(laboratorios[6].identificacao, "I104"); laboratorios[6].capacidadeAtual = 15; laboratorios[6].capacidadeMaxima = 20;
    strcpy(laboratorios[7].bloco, "I"); strcpy(laboratorios[7].descricao, "Lab. de Informática"); strcpy(laboratorios[7].identificacao, "I103"); laboratorios[7].capacidadeAtual = 16; laboratorios[7].capacidadeMaxima = 25;
    strcpy(laboratorios[8].bloco, "I"); strcpy(laboratorios[8].descricao, "Lab. de Informática"); strcpy(laboratorios[8].identificacao, "I102"); laboratorios[8].capacidadeAtual = 20; laboratorios[8].capacidadeMaxima = 20;

    // BLOCO J
    //strcpy(laboratorios[17].bloco, "J"); strcpy(laboratorios[17].descricao, "Lab. de CNC e Metrologia"); strcpy(laboratorios[17].identificacao, "J107"); laboratorios[17].capacidadeAtual = 35; laboratorios[17].capacidadeMaxima = 40;
    strcpy(laboratorios[9].bloco, "J"); strcpy(laboratorios[9].descricao, "Sala de Iniciação Científica"); strcpy(laboratorios[9].identificacao, "J112"); laboratorios[9].capacidadeAtual = 20; laboratorios[9].capacidadeMaxima = 28;
    strcpy(laboratorios[10].bloco, "J"); strcpy(laboratorios[10].descricao, "Lab. de Eletrônica e Física Experimental"); strcpy(laboratorios[10].identificacao, "J110"); laboratorios[10].capacidadeAtual = 18; laboratorios[10].capacidadeMaxima = 35;
    strcpy(laboratorios[11].bloco, "J"); strcpy(laboratorios[11].descricao, "Lab. de Informática da Indústria"); strcpy(laboratorios[11].identificacao, "J109"); laboratorios[11].capacidadeAtual = 22; laboratorios[11].capacidadeMaxima = 25;
    strcpy(laboratorios[12].bloco, "J"); strcpy(laboratorios[12].descricao, "Lab. de Hidráulica e Pneumática"); strcpy(laboratorios[12].identificacao, "J108"); laboratorios[12].capacidadeAtual = 32; laboratorios[12].capacidadeMaxima = 35;
    strcpy(laboratorios[13].bloco, "J"); strcpy(laboratorios[13].descricao, "Lab. de Fabricação Mecânica"); strcpy(laboratorios[13].identificacao, "J106"); laboratorios[13].capacidadeAtual = 28; laboratorios[13].capacidadeMaxima = 40;
    strcpy(laboratorios[14].bloco, "J"); strcpy(laboratorios[14].descricao, "Lab. de Fabricação Mecânica"); strcpy(laboratorios[14].identificacao, "J105"); laboratorios[14].capacidadeAtual = 35; laboratorios[14].capacidadeMaxima = 40;
    strcpy(laboratorios[15].bloco, "J"); strcpy(laboratorios[15].descricao, "Lab. de Materiais"); strcpy(laboratorios[15].identificacao, "J103"); laboratorios[15].capacidadeAtual = 15; laboratorios[15].capacidadeMaxima = 20;
    strcpy(laboratorios[16].bloco, "J"); strcpy(laboratorios[16].descricao, "Lab. de Eletrônica"); strcpy(laboratorios[16].identificacao, "J102"); laboratorios[16].capacidadeAtual = 18; laboratorios[16].capacidadeMaxima = 25;
    strcpy(laboratorios[17].bloco, "J"); strcpy(laboratorios[17].descricao, "Lab. de Robótica e CLP/Labmaker"); strcpy(laboratorios[17].identificacao, "J101"); laboratorios[17].capacidadeAtual = 35; laboratorios[17].capacidadeMaxima = 45;

    // BLOCO J PISO PROFESSORES
    strcpy(salasProf[0].bloco, "J"); strcpy(salasProf[0].identificacao, "J215"); salasProf[0].capacidadeAtual = 8; salasProf[0].capacidadeMaxima = 10;
    strcpy(salasProf[1].bloco, "J"); strcpy(salasProf[1].identificacao, "J214"); salasProf[1].capacidadeAtual = 8; salasProf[1].capacidadeMaxima = 10;
    strcpy(salasProf[2].bloco, "J"); strcpy(salasProf[2].identificacao, "J213"); salasProf[2].capacidadeAtual = 8; salasProf[2].capacidadeMaxima = 10;
    strcpy(salasProf[3].bloco, "J"); strcpy(salasProf[3].identificacao, "J212"); salasProf[3].capacidadeAtual = 8; salasProf[3].capacidadeMaxima = 10;
    strcpy(salasProf[4].bloco, "J"); strcpy(salasProf[4].identificacao, "J211"); salasProf[4].capacidadeAtual = 8; salasProf[4].capacidadeMaxima = 10;
    strcpy(salasProf[5].bloco, "J"); strcpy(salasProf[5].identificacao, "J210"); salasProf[5].capacidadeAtual = 8; salasProf[5].capacidadeMaxima = 10;
    strcpy(salasProf[6].bloco, "J"); strcpy(salasProf[6].identificacao, "J209"); salasProf[6].capacidadeAtual = 8; salasProf[6].capacidadeMaxima = 10;
    strcpy(salasProf[7].bloco, "J"); strcpy(salasProf[7].identificacao, "J208"); salasProf[7].capacidadeAtual = 8; salasProf[7].capacidadeMaxima = 10;
    strcpy(salasProf[8].bloco, "J"); strcpy(salasProf[8].identificacao, "J207"); salasProf[8].capacidadeAtual = 8; salasProf[8].capacidadeMaxima = 10;
    strcpy(salasProf[9].bloco, "J"); strcpy(salasProf[9].identificacao, "J206"); salasProf[9].capacidadeAtual = 8; salasProf[9].capacidadeMaxima = 10;
    strcpy(salasProf[10].bloco, "J"); strcpy(salasProf[10].identificacao, "J205"); salasProf[10].capacidadeAtual = 8; salasProf[10].capacidadeMaxima = 10;
    strcpy(salasProf[11].bloco, "J"); strcpy(salasProf[11].identificacao, "J204"); salasProf[11].capacidadeAtual = 8; salasProf[11].capacidadeMaxima = 10;
    strcpy(salasProf[12].bloco, "J"); strcpy(salasProf[12].identificacao, "J203"); salasProf[12].capacidadeAtual = 8; salasProf[12].capacidadeMaxima = 10;
    strcpy(salasProf[13].bloco, "J"); strcpy(salasProf[13].identificacao, "J202"); salasProf[13].capacidadeAtual = 8; salasProf[13].capacidadeMaxima = 10;
    strcpy(salasProf[14].bloco, "J"); strcpy(salasProf[14].identificacao, "J201"); salasProf[14].capacidadeAtual = 8; salasProf[14].capacidadeMaxima = 10;
}

void cadastrarEspacos(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan, const char* tipoEspaco) {
    if (strcmp(tipoEspaco, "SalaTeorica") == 0) {
        if (indexSalaTeorica < MAX_SALAS) {
            printf("\nBloco: ");
            scanf("%s", salas[indexSalaTeorica].bloco);
            printf("Identificação: ");
            scanf("%s", salas[indexSalaTeorica].identificacao);
            printf("Capacidade Atual: ");
            scanf("%d", &salas[indexSalaTeorica].capacidadeAtual);
            printf("Capacidade Máxima: ");
            scanf("%d", &salas[indexSalaTeorica].capacidadeMaxima);
            indexSalaTeorica++;
            printf("\nSala Teórica cadastrada com sucesso!\n");
        } else {
            printf("\nErro: Limite de salas teóricas atingido! Não é possível cadastrar mais salas.\n");
        }
    } 
    else if (strcmp(tipoEspaco, "Laboratorio") == 0) {
        if (indexLaboratorio < MAX_LABS) {
            printf("\nBloco: ");
            scanf("%s", laboratorios[indexLaboratorio].bloco);
            printf("Descrição: ");
            scanf(" %[^\n]", laboratorios[indexLaboratorio].descricao);
            printf("Identificação: ");
            scanf("%s", laboratorios[indexLaboratorio].identificacao);
            printf("Capacidade Atual: ");
            scanf("%d", &laboratorios[indexLaboratorio].capacidadeAtual);
            printf("Capacidade Máxima: ");
            scanf("%d", &laboratorios[indexLaboratorio].capacidadeMaxima);
            indexLaboratorio++;
            printf("\nLaboratório cadastrado com sucesso!\n");
        } else {
            printf("\nErro: Limite de laboratórios atingido! Não é possível cadastrar mais laboratórios.\n");
        }
    } 
    else if (strcmp(tipoEspaco, "SalaAdministrativa") == 0) {
        if (indexSalaAdm < MAX_SALAS_ADM) {
            printf("\nBloco: ");
            scanf("%s", salasAdm[indexSalaAdm].bloco);
            printf("Descrição: ");
            scanf(" %[^\n]", salasAdm[indexSalaAdm].descricao);
            printf("Identificação: ");
            scanf("%s", salasAdm[indexSalaAdm].identificacao);
            printf("Capacidade Atual: ");
            scanf("%d", &salasAdm[indexSalaAdm].capacidadeAtual);
            printf("Capacidade Máxima: ");
            scanf("%d", &salasAdm[indexSalaAdm].capacidadeMaxima);
            indexSalaAdm++;
            printf("\nSala Administrativa cadastrada com sucesso!\n");
        } else {
            printf("\nErro: Limite de salas administrativas atingido! Não é possível cadastrar mais salas administrativas.\n");
        }
    } 
    else if (strcmp(tipoEspaco, "EspacoGeral") == 0) {
        if (indexEspacoGeral < MAX_ESPACOS) {
            printf("\nBloco: ");
            scanf("%s", espacos[indexEspacoGeral].bloco);
            printf("Descrição: ");
            scanf(" %[^\n]", espacos[indexEspacoGeral].descricao);
            printf("Identificação: ");
            scanf("%s", espacos[indexEspacoGeral].identificacao);
            printf("Capacidade Atual: ");
            scanf("%d", &espacos[indexEspacoGeral].capacidadeAtual);
            printf("Capacidade Máxima: ");
            scanf("%d", &espacos[indexEspacoGeral].capacidadeMaxima);
            indexEspacoGeral++;
            printf("\nEspaço de Uso Geral cadastrado com sucesso!\n");
        } else {
            printf("\nErro: Limite de espaço de uso geral atingido! Não é possível cadastrar mais espaços de usos gerais.\n");
        }
    } 
    else if (strcmp(tipoEspaco, "SalaProfessor") == 0) {
        if (indexSalaProfessor < MAX_SALAS_PROF) {
            printf("\nBloco: ");
            scanf("%s", salasProf[indexSalaProfessor].bloco);
            printf("Identificação: ");
            scanf("%s", salasProf[indexSalaProfessor].identificacao);
            printf("Capacidade Atual: ");
            scanf("%d", &salasProf[indexSalaProfessor].capacidadeAtual);
            printf("Capacidade Máxima: ");
            scanf("%d", &salasProf[indexSalaProfessor].capacidadeMaxima);
            indexSalaProfessor++;
            printf("\nSala de Professor cadastrada com sucesso!\n");
        } else {
            printf("\nErro: Limite de salas de professor atingido! Não é possível cadastrar mais salas de professor.\n");
        }
    }
    else if (strcmp(tipoEspaco, "Patio") == 0) {
        if (indexPatio < MAX_PATIOS) {
            printf("\nBloco: ");
            scanf("%s", patios[indexPatio].bloco);
            printf("Descrição: ");
            scanf(" %[^\n]", patios[indexPatio].descricao);
            printf("Identificação: ");
            scanf("%s", patios[indexPatio].identificacao);
            printf("Capacidade Atual: ");
            scanf("%d", &patios[indexPatio].capacidadeAtual);
            printf("Capacidade Máxima: ");
            scanf("%d", &patios[indexPatio].capacidadeMaxima);
            indexPatio++;
            printf("\nPátio cadastrado com sucesso!\n");
        } else {
            printf("\nErro: Limite de pátios atingido! Não é possível cadastrar mais pátios.\n");
        }
    } 
    else if (strcmp(tipoEspaco, "Geral") == 0) {
        if (indexGeral < MAX_GERAIS) {
            printf("\nBloco: ");
            scanf("%s", gerais[indexGeral].bloco);
            printf("Descrição: ");
            scanf(" %[^\n]", gerais[indexGeral].descricao);
            printf("Identificação: ");
            scanf("%s", gerais[indexGeral].identificacao);
            printf("Capacidade Atual: ");
            scanf("%d", &gerais[indexGeral].capacidadeAtual);
            printf("Capacidade Máxima: ");
            scanf("%d", &gerais[indexGeral].capacidadeMaxima);
            indexGeral++;
            printf("\nSala Geral cadastrada com sucesso!\n");
        } else {
            printf("\nErro: Limite de salas gerais atingido! Não é possível cadastrar mais salas gerais.\n");
        }
    } 
    else if (strcmp(tipoEspaco, "Manutencao") == 0) {
        if (indexManutencao < MAX_MANUTENCAO) {
            printf("\nBloco: ");
            scanf("%s", salasMan[indexManutencao].bloco);
            printf("Descrição: ");
            scanf(" %[^\n]", salasMan[indexManutencao].descricao);
            printf("Identificação da Sala de Manutenção: ");
            scanf("%s", salasMan[indexManutencao].identificacao);
            printf("Capacidade Atual da Sala de Manutenção: ");
            scanf("%d", &salasMan[indexManutencao].capacidadeAtual);
            printf("Capacidade Máxima da Sala de Manutenção: ");
            scanf("%d", &salasMan[indexManutencao].capacidadeMaxima);
            indexManutencao++;
            printf("\nSala de Manutenção cadastrada com sucesso!\n");
        } else {
            printf("\nErro: Limite de salas de manutenção atingido! Não é possível cadastrar mais salas de manutenção.\n");
        }
    } 
    else {
        printf("\nErro: Tipo de espaço desconhecido. Tente novamente.\n");
    }
}

void listarTodosEspacos(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan) {
    printf("\n--- Salas Teóricas ---\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        if (salas[i].capacidadeAtual > 0) {
            printf("Bloco: %s | Identificação: %s | Capacidade Atual: %d | Capacidade Máxima: %d\n", 
                salas[i].bloco, salas[i].identificacao, salas[i].capacidadeAtual, salas[i].capacidadeMaxima);
        }
    }
    printf("\n--- Laboratórios ---\n");
    for (int i = 0; i < MAX_LABS; i++) {
        if (laboratorios[i].capacidadeAtual > 0) {
            printf("Bloco: %s | Descrição: %s | Identificação: %s | Capacidade Atual: %d | Capacidade Máxima: %d\n", 
                laboratorios[i].bloco, laboratorios[i].descricao, laboratorios[i].identificacao, 
                laboratorios[i].capacidadeAtual, laboratorios[i].capacidadeMaxima);
        }
    }
    printf("\n--- Salas Administrativas ---\n");
    for (int i = 0; i < MAX_SALAS_ADM; i++) {
        if (salasAdm[i].capacidadeAtual > 0) {
            printf("Bloco: %s | Descrição: %s | Identificação: %s | Capacidade Atual: %d | Capacidade Máxima: %d\n", 
                salasAdm[i].bloco, salasAdm[i].descricao, salasAdm[i].identificacao, 
                salasAdm[i].capacidadeAtual, salasAdm[i].capacidadeMaxima);
        }
    }
    printf("\n--- Salas dos Professores ---\n");
    for (int i = 0; i < MAX_SALAS_PROF; i++) {
        if (salasProf[i].capacidadeAtual > 0) {
            printf("Bloco: %s | Identificação: %s | Capacidade Atual: %d | Capacidade Máxima: %d\n", 
                salasProf[i].bloco, salasProf[i].identificacao, salasProf[i].capacidadeAtual, salasProf[i].capacidadeMaxima);
        }
    }
    printf("\n--- Espaços de Uso Geral ---\n");
    for (int i = 0; i < MAX_ESPACOS; i++) {
        if (espacos[i].capacidadeAtual > 0) {
            printf("Bloco: %s | Descrição: %s | Identificação: %s | Capacidade Atual: %d | Capacidade Máxima: %d\n", 
                espacos[i].bloco, espacos[i].descricao, espacos[i].identificacao, espacos[i].capacidadeAtual, espacos[i].capacidadeMaxima);
        }
    }
    printf("\n--- Pátio ---\n");
    for (int i = 0; i < MAX_PATIOS; i++) {
        if (patios[i].capacidadeAtual > 0) {
            printf("Bloco: %s | Descrição: %s | Identificação: %s | Capacidade Atual: %d | Capacidade Máxima: %d\n", 
                patios[i].bloco, patios[i].descricao, patios[i].identificacao, patios[i].capacidadeAtual, patios[i].capacidadeMaxima);
        }
    }
    printf("\n--- Manutenção ---\n");
    for (int i = 0; i < MAX_MANUTENCAO; i++) {
        if (salasMan[i].capacidadeAtual > 0) {
            printf("Bloco: %s | Descrição: %s | Identificação: %s | Capacidade Atual: %d | Capacidade Máxima: %d\n", 
                salasMan[i].bloco, salasMan[i].descricao, salasMan[i].identificacao, salasMan[i].capacidadeAtual, salasMan[i].capacidadeMaxima);
        }
    }
    printf("\n--- Gerais ---\n");
    for (int i = 0; i < MAX_GERAIS; i++) {
        if (gerais[i].capacidadeAtual > 0) {
            printf("Bloco: %s | Descrição: %s | Identificação: %s | Capacidade Atual: %d | Capacidade Máxima: %d\n", 
                gerais[i].bloco, gerais[i].descricao, gerais[i].identificacao, gerais[i].capacidadeAtual, gerais[i].capacidadeMaxima);
        }
    }
}

void listarPorBloco(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan) {
    char bloco[2];
    printf("\nDigite o bloco a ser listado: ");
    scanf("%s", bloco);

    for (int i = 0; bloco[i]; i++) {
        bloco[i] = tolower(bloco[i]);
    }

    printf("\nEspaços no Bloco %s:\n", bloco);

    int espacoEncontrado = 0;

    for (int i = 0; i < MAX_SALAS; i++) {
        char salaBloco[2];
        for (int j = 0; salas[i].bloco[j]; j++) {
            salaBloco[j] = tolower(salas[i].bloco[j]);
        }

        if (strcmp(salaBloco, bloco) == 0) {
            printf("Sala Teórica - Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                   salas[i].identificacao, salas[i].capacidadeAtual, salas[i].capacidadeMaxima);
            espacoEncontrado = 1;
        }
    }
    for (int i = 0; i < MAX_LABS; i++) {
        char labBloco[2];
        for (int j = 0; laboratorios[i].bloco[j]; j++) {
            labBloco[j] = tolower(laboratorios[i].bloco[j]);
        }

        if (strcmp(labBloco, bloco) == 0) {
            printf("Laboratório - Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                   laboratorios[i].descricao, laboratorios[i].identificacao, laboratorios[i].capacidadeAtual, laboratorios[i].capacidadeMaxima);
            espacoEncontrado = 1;
        }
    }
    for (int i = 0; i < MAX_SALAS_ADM; i++) {
        char admBloco[2];
        for (int j = 0; salasAdm[i].bloco[j]; j++) {
            admBloco[j] = tolower(salasAdm[i].bloco[j]);
        }

        if (strcmp(admBloco, bloco) == 0) {
            printf("Sala Administrativa - Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                   salasAdm[i].descricao, salasAdm[i].identificacao, salasAdm[i].capacidadeAtual, salasAdm[i].capacidadeMaxima);
            espacoEncontrado = 1;
        }
    }
    for (int i = 0; i < MAX_SALAS_PROF; i++) { 
        char profBloco[2];
        for (int j = 0; salasProf[i].bloco[j]; j++) {
            profBloco[j] = tolower(salasProf[i].bloco[j]);
        }

        if (strcmp(profBloco, bloco) == 0) {
            printf("Sala de Professor - Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                   salasProf[i].identificacao, salasProf[i].capacidadeAtual, salasProf[i].capacidadeMaxima);
            espacoEncontrado = 1;
        }
    }
    for (int i = 0; i < MAX_ESPACOS; i++) { 
        char espacoBloco[2];
        for (int j = 0; espacos[i].bloco[j]; j++) {
            espacoBloco[j] = tolower(espacos[i].bloco[j]);
        }

        if (strcmp(espacoBloco, bloco) == 0) {
            printf("Espaço Geral - Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                   espacos[i].descricao, espacos[i].identificacao, espacos[i].capacidadeAtual, espacos[i].capacidadeMaxima);
            espacoEncontrado = 1;
        }
    }
    for (int i = 0; i < MAX_PATIOS; i++) { 
        char patioBloco[2];
        for (int j = 0; patios[i].bloco[j]; j++) {
            patioBloco[j] = tolower(patios[i].bloco[j]);
        }

        if (strcmp(patioBloco, bloco) == 0) {
            printf("Pátio - Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                   patios[i].identificacao, patios[i].capacidadeAtual, patios[i].capacidadeMaxima);
            espacoEncontrado = 1;
        }
    }
    for (int i = 0; i < MAX_MANUTENCAO; i++) { 
        char manBloco[2];
        for (int j = 0; salasMan[i].bloco[j]; j++) {
            manBloco[j] = tolower(salasMan[i].bloco[j]);
        }

        if (strcmp(manBloco, bloco) == 0) {
            printf("Manutenção - Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                   salasMan[i].identificacao, salasMan[i].capacidadeAtual, salasMan[i].capacidadeMaxima);
            espacoEncontrado = 1;
        }
    }
    for (int i = 0; i < MAX_GERAIS; i++) { 
        char geraisBloco[2];
        for (int j = 0; gerais[i].bloco[j]; j++) {
            geraisBloco[j] = tolower(gerais[i].bloco[j]);
        }

        if (strcmp(geraisBloco, bloco) == 0) {
            printf("Salas Gerais - Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                   gerais[i].descricao, gerais[i].identificacao, gerais[i].capacidadeAtual, gerais[i].capacidadeMaxima);
            espacoEncontrado = 1;
        }
    }
    if (!espacoEncontrado) {
        printf("Não há espaços cadastrados no bloco %s.\n", bloco);
    }
}

void listarPorTipo(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan, const char *tipo) {
    printf("\n");
    if (strcmp(tipo, "SalaTeorica") == 0) {
        for (int i = 0; i < MAX_SALAS; i++) {
            if (salas[i].capacidadeAtual > 0) {
                printf("Sala Teórica - Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                       salas[i].identificacao, salas[i].capacidadeAtual, salas[i].capacidadeMaxima);
            }
        }
    } else if (strcmp(tipo, "Laboratorio") == 0) {
        for (int i = 0; i < MAX_LABS; i++) {
            if (laboratorios[i].capacidadeAtual > 0) {
                printf("Laboratório - Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                       laboratorios[i].descricao, laboratorios[i].identificacao, laboratorios[i].capacidadeAtual, laboratorios[i].capacidadeMaxima);
            }
        }
    } else if (strcmp(tipo, "SalaProfessor") == 0) {
        for (int i = 0; i < MAX_SALAS_PROF; i++) {
            if (salasProf[i].capacidadeAtual > 0) {
                printf("Sala de Professor - Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                       salasProf[i].identificacao, salasProf[i].capacidadeAtual, salasProf[i].capacidadeMaxima);
            }
        }
    } else if (strcmp(tipo, "SalaAdministrativa") == 0) {
        for (int i = 0; i < MAX_SALAS_ADM; i++) {
            if (salasAdm[i].capacidadeAtual > 0) {
                printf("Sala Administrativa - Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                       salasAdm[i].descricao, salasAdm[i].identificacao, salasAdm[i].capacidadeAtual, salasAdm[i].capacidadeMaxima);
            }
        }
    } else if (strcmp(tipo, "EspacoGeral") == 0) {
        for (int i = 0; i < MAX_ESPACOS; i++) {
            if (espacos[i].capacidadeAtual > 0) {
                printf("Espaço Geral - Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                       espacos[i].descricao, espacos[i].identificacao, espacos[i].capacidadeAtual, espacos[i].capacidadeMaxima);
            }
        }
    } else if (strcmp(tipo, "Patio") == 0) {
        for (int i = 0; i < MAX_PATIOS; i++) {
            if (patios[i].capacidadeAtual > 0) {
                printf("Pátio - Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                       patios[i].identificacao, patios[i].capacidadeAtual, patios[i].capacidadeMaxima);
            }
        }
    } else if (strcmp(tipo, "Manutencao") == 0) {
        for (int i = 0; i < MAX_MANUTENCAO; i++) {
            if (salasMan[i].capacidadeAtual > 0) {
                printf("Manutenção - Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                       salasMan[i].identificacao, salasMan[i].capacidadeAtual, salasMan[i].capacidadeMaxima);
            }
        }
    } else if (strcmp(tipo, "SalaGeral") == 0) {
        for (int i = 0; i < MAX_GERAIS; i++) {
            if (gerais[i].capacidadeAtual > 0) {
                printf("Sala Geral - Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                       gerais[i].descricao, gerais[i].identificacao, gerais[i].capacidadeAtual, gerais[i].capacidadeMaxima);
            }
        }
    } else {
        printf("Tipo de espaço desconhecido.\n");
    }
}

double calcularTaxaOcupacao(void *espacos, int quantidade, int tamanhoElemento) {
    int somaAtual = 0, somaMaxima = 0;

    for (int i = 0; i < quantidade; i++) {
        void *espaco = (char *)espacos + i * tamanhoElemento;
        int capacidadeAtual = *(int *)((char *)espaco + sizeof(char) * 20 + sizeof(char) * 10);  
        int capacidadeMaxima = *(int *)((char *)espaco + sizeof(char) * 20 + sizeof(char) * 10 + sizeof(int));

        if (capacidadeMaxima > 0) {  
            somaAtual += capacidadeAtual;
            somaMaxima += capacidadeMaxima;
        }
    }

    return somaMaxima == 0 ? 0 : (double)somaAtual / somaMaxima;
}

int calcularComputadoresNecessarios(void *espacos, int quantidade, int tamanhoElemento, int tipoEspaco) {
    int totalNecessario = 0;

    for (int i = 0; i < quantidade; i++) {
        void *espaco = (char *)espacos + i * tamanhoElemento;

        if (tipoEspaco == 1) {  
            int capacidadeAtual = *(int *)((char *)espaco + sizeof(char) * 20 + sizeof(char) * 10);
            int capacidadeMaxima = *(int *)((char *)espaco + sizeof(char) * 20 + sizeof(char) * 10 + sizeof(int));

            if (capacidadeMaxima > capacidadeAtual) {
                totalNecessario += capacidadeMaxima - capacidadeAtual;
            }
        }
    }

    return totalNecessario;
}


void exibirEstatisticas( SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan) {
    printf("\n--- Estatísticas de Ocupação ---\n");
    printf("Taxa de Ocupação das Salas Teóricas: %.2f%%\n", calcularTaxaOcupacao(salas, MAX_SALAS, sizeof(SalaTeorica)) * 100);
    printf("Taxa de Ocupação dos Laboratórios: %.2f%%\n", calcularTaxaOcupacao(laboratorios, MAX_LABS, sizeof(Laboratorio)) * 100);
    printf("Taxa de Ocupação das Salas Administrativas: %.2f%%\n", calcularTaxaOcupacao(salasAdm, MAX_SALAS_ADM, sizeof(SalaAdministrativa)) * 100);
    printf("Taxa de Ocupação das Salas dos Professores: %.2f%%\n", calcularTaxaOcupacao(salasProf, MAX_SALAS_PROF, sizeof(SalaProfessor)) * 100);
    printf("Taxa de Ocupação dos Espaços de Uso Geral: %.2f%%\n", calcularTaxaOcupacao(espacos, MAX_ESPACOS, sizeof(EspacoDeUso)) * 100);
    printf("Taxa de Ocupação dos Pátios: %.2f%%\n", calcularTaxaOcupacao(patios, MAX_PATIOS, sizeof(Patio)) * 100);
    printf("Taxa de Ocupação das Salas de Manutenção: %.2f%%\n", calcularTaxaOcupacao(salasMan, MAX_MANUTENCAO, sizeof(Manutencao)) * 100);
    printf("Taxa de Ocupação dos Espaços Gerais: %.2f%%\n", calcularTaxaOcupacao(gerais, MAX_GERAIS, sizeof(Geral)) * 100);

    int computadoresNecessarios = calcularComputadoresNecessarios(laboratorios, MAX_LABS, sizeof(Laboratorio), 1);
    printf("Computadores necessários para 100%% de ocupação nos Laboratórios: %d\n", computadoresNecessarios);
}