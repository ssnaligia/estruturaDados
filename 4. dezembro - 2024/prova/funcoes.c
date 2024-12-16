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

int calcularComputadoresNecessarios(Laboratorio *laboratorios, int quantidadelaboratorios) {
    int totalNecessario = 0;
    for (int i = 0; i < quantidadelaboratorios; i++) {
        if (laboratorios[i].capacidadeAtual < laboratorios[i].capacidadeMaxima) {
            totalNecessario += laboratorios[i].capacidadeMaxima - laboratorios[i].capacidadeAtual;
        }
    }
    return totalNecessario;
}

void cadastrarEspacos(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan) {
    char tipo[20];
    printf("\nDigite o tipo de espaço a cadastrar (SalaTeorica, Laboratorio, SalaAdministrativa, etc.): ");
    scanf("%s", tipo);

    if (strcmp(tipo, "SalaTeorica") == 0) {
        static int indexSala = 10; 
        if (indexSala <= MAX_SALAS) {
            printf("Bloco: ");
            scanf("%s", salas[indexSala].bloco);
            printf("Identificação: ");
            scanf("%s", salas[indexSala].identificacao);
            printf("Capacidade Atual: ");
            scanf("%d", &salas[indexSala].capacidadeAtual);
            printf("Capacidade Máxima: ");
            scanf("%d", &salas[indexSala].capacidadeMaxima);
            indexSala++;
        } else {
            printf("Erro: Limite de salas teóricas atingido! Não é possível cadastrar mais salas.\n");
        }
    } 
    else if (strcmp(tipo, "Laboratorio") == 0) {
        static int indexLab = 18; 
        if (indexLab <= MAX_LABS) {
            printf("Bloco: ");
            scanf("%s", laboratorios[indexLab].bloco);
            printf("Descrição: ");
            scanf(" %[^\n]", laboratorios[indexLab].descricao); 
            printf("Identificação: ");
            scanf("%s", laboratorios[indexLab].identificacao);
            printf("Capacidade Atual: ");
            scanf("%d", &laboratorios[indexLab].capacidadeAtual);
            printf("Capacidade Máxima: ");
            scanf("%d", &laboratorios[indexLab].capacidadeMaxima);
            indexLab++;
        } else {
            printf("Erro: Limite de laboratórios atingido! Não é possível cadastrar mais laboratórios.\n");
        }
    } 
    else if (strcmp(tipo, "SalaAdministrativa") == 0) {
        static int indexAdm = 10; 
        if (indexAdm <= MAX_SALAS_ADM) {
            printf("Bloco: ");
            scanf("%s", salasAdm[indexAdm].bloco);
            printf("Descrição: ");
            scanf(" %[^\n]", salasAdm[indexAdm].descricao); 
            printf("Identificação: ");
            scanf("%s", salasAdm[indexAdm].identificacao);
            printf("Capacidade Atual: ");
            scanf("%d", &salasAdm[indexAdm].capacidadeAtual);
            printf("Capacidade Máxima: ");
            scanf("%d", &salasAdm[indexAdm].capacidadeMaxima);
            indexAdm++;
        } else {
            printf("Erro: Limite de salas administrativas atingido! Não é possível cadastrar mais salas administrativas.\n");
        }
    } 
    else if (strcmp(tipo, "Patio") == 0) {
        static int indexPatio = 0; 
        if (indexPatio == 0) {
            printf("Identificação do pátio: ");
            scanf("%s", patios[indexPatio].identificacao);
            printf("Capacidade Atual do pátio: ");
            scanf("%d", &patios[indexPatio].capacidadeAtual);
            printf("Capacidade Máxima do pátio: ");
            scanf("%d", &patios[indexPatio].capacidadeMaxima);
            indexPatio++;
        } else {
            printf("Erro: Limite de pátios atingido! Não é possível cadastrar mais pátios.\n");
        }
    } 
    else {
        printf("Erro: Tipo de espaço desconhecido. Tente novamente.\n");
    }
}

void definirDadosIniciais(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan) {
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

    /*strcpy(salasAdm[6].bloco, "C");
    strcpy(salasAdm[6].descricao, "Coord. Sociopedagógica");
    strcpy(salasAdm[6].identificacao, "C103");
    salasAdm[6].capacidadeAtual = 27;
    salasAdm[6].capacidadeMaxima = 40;*/

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
    /*strcpy(salas[0].bloco, "D");
    strcpy(salas[0].identificacao, "D106");
    salas[0].capacidadeAtual = 27;
    salas[0].capacidadeMaxima = 40;

    strcpy(salas[1].bloco, "D");
    strcpy(salas[1].identificacao, "D105");
    salas[1].capacidadeAtual = 27;
    salas[1].capacidadeMaxima = 40;*/

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
    /*strcpy(laboratorios[0].bloco, "E");
    strcpy(laboratorios[0].descricao, "Lab. de Ensino de Matemática");
    strcpy(laboratorios[0].identificacao, "E105");
    laboratorios[0].capacidadeAtual = 35;
    laboratorios[0].capacidadeMaxima = 40;

    strcpy(salas[6].bloco, "E");
    strcpy(salas[6].identificacao, "E104");
    salas[6].capacidadeAtual = 27;
    salas[6].capacidadeMaxima = 40;*/

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
    /*strcpy(laboratorios[1].bloco, "F");
    strcpy(laboratorios[1].descricao, "Estúdio Audiovisual");
    strcpy(laboratorios[1].identificacao, "F104");
    laboratorios[1].capacidadeAtual = 35;
    laboratorios[1].capacidadeMaxima = 40;*/

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

    /*strcpy(salasAdm[9].bloco, "G");
    strcpy(salasAdm[9].descricao, "Coord. de Apoio ao Ensino");
    strcpy(salasAdm[9].identificacao, "G102");
    salasAdm[9].capacidadeAtual = 35;
    salasAdm[9].capacidadeMaxima = 40;*/

    strcpy(salasAdm[10].bloco, "G");
    strcpy(salasAdm[10].descricao, "Coord. de Apoio ao Ensino");
    strcpy(salasAdm[10].identificacao, "G101");
    salasAdm[10].capacidadeAtual = 35;
    salasAdm[10].capacidadeMaxima = 40;

    strcpy(laboratorios[2].bloco, "G");
    strcpy(laboratorios[2].descricao, "Lab. Iniciação Científica");
    strcpy(laboratorios[2].identificacao, "G107");
    laboratorios[2].capacidadeAtual = 35;
    laboratorios[2].capacidadeMaxima = 40;

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

    strcpy(laboratorios[3].bloco, "I");
    strcpy(laboratorios[3].descricao, "LDA - Lab. de Desenvolvimento Avançado");
    strcpy(laboratorios[3].identificacao, "I112");
    laboratorios[3].capacidadeAtual = 35;
    laboratorios[3].capacidadeMaxima = 40;

    /*strcpy(laboratorios[4].bloco, "I");
    strcpy(laboratorios[4].descricao, "LDA - Lab. de Desenvolvimento Avançado");
    strcpy(laboratorios[4].identificacao, "I111");
    laboratorios[4].capacidadeAtual = 35;
    laboratorios[4].capacidadeMaxima = 40;*/

    strcpy(laboratorios[5].bloco, "I");
    strcpy(laboratorios[5].descricao, "Lab. de Química e Biologia");
    strcpy(laboratorios[5].identificacao, "I109");
    laboratorios[5].capacidadeAtual = 35;
    laboratorios[5].capacidadeMaxima = 40;

    strcpy(laboratorios[6].bloco, "I");
    strcpy(laboratorios[6].descricao, "Lab. de Física");
    strcpy(laboratorios[6].identificacao, "I108");
    laboratorios[6].capacidadeAtual = 35;
    laboratorios[6].capacidadeMaxima = 40;

    /*strcpy(salasAdm[12].bloco, "I");
    strcpy(salasAdm[12].descricao, "CTI - Coordenadoria de Tecnologia da Informação");
    strcpy(salasAdm[12].identificacao, "I107");
    salasAdm[12].capacidadeAtual = 35;
    salasAdm[12].capacidadeMaxima = 40;*/

    strcpy(laboratorios[7].bloco, "I");
    strcpy(laboratorios[7].descricao, "Lab. de Redes");
    strcpy(laboratorios[7].identificacao, "I106");
    laboratorios[7].capacidadeAtual = 35;
    laboratorios[7].capacidadeMaxima = 40;

    strcpy(laboratorios[8].bloco, "I");
    strcpy(laboratorios[8].descricao, "Lab. de Hardware");
    strcpy(laboratorios[8].identificacao, "I105");
    laboratorios[8].capacidadeAtual = 35;
    laboratorios[8].capacidadeMaxima = 40;

    strcpy(laboratorios[9].bloco, "I");
    strcpy(laboratorios[9].descricao, "Lab. de Informática");
    strcpy(laboratorios[9].identificacao, "I104");
    laboratorios[9].capacidadeAtual = 35;
    laboratorios[9].capacidadeMaxima = 40;

    strcpy(laboratorios[10].bloco, "I");
    strcpy(laboratorios[10].descricao, "Lab. de Informática");
    strcpy(laboratorios[10].identificacao, "I103");
    laboratorios[10].capacidadeAtual = 35;
    laboratorios[10].capacidadeMaxima = 40;

    strcpy(laboratorios[11].bloco, "I");
    strcpy(laboratorios[11].descricao, "Lab. de Informática");
    strcpy(laboratorios[11].identificacao, "I102");
    laboratorios[11].capacidadeAtual = 35;
    laboratorios[11].capacidadeMaxima = 40;

    /*strcpy(laboratorios[12].bloco, "I");
    strcpy(laboratorios[12].descricao, "Lab. de Informática");
    strcpy(laboratorios[12].identificacao, "I101");
    laboratorios[12].capacidadeAtual = 35;
    laboratorios[12].capacidadeMaxima = 40;*/

    //BLOCO J
    strcpy(laboratorios[13].bloco, "J");
    strcpy(laboratorios[13].descricao, "Sala de Iniciação Científica");
    strcpy(laboratorios[13].identificacao, "J112");
    laboratorios[13].capacidadeAtual = 35;
    laboratorios[13].capacidadeMaxima = 40;

    strcpy(laboratorios[14].bloco, "J");
    strcpy(laboratorios[14].descricao, "Lab. de Eletrônica e Física Experimental");
    strcpy(laboratorios[14].identificacao, "J110");
    laboratorios[14].capacidadeAtual = 35;
    laboratorios[14].capacidadeMaxima = 40;

    strcpy(laboratorios[15].bloco, "J");
    strcpy(laboratorios[15].descricao, "Lab. de Informática da Indústria");
    strcpy(laboratorios[15].identificacao, "J109");
    laboratorios[15].capacidadeAtual = 35;
    laboratorios[15].capacidadeMaxima = 40;

    strcpy(laboratorios[16].bloco, "J");
    strcpy(laboratorios[16].descricao, "Lab. de Hidráulica e Pneumática");
    strcpy(laboratorios[16].identificacao, "J108");
    laboratorios[16].capacidadeAtual = 35;
    laboratorios[16].capacidadeMaxima = 40;

    /*strcpy(laboratorios[17].bloco, "J");
    strcpy(laboratorios[17].descricao, "Lab. de CNC e Metrologia");
    strcpy(laboratorios[17].identificacao, "J107");
    laboratorios[17].capacidadeAtual = 35;
    laboratorios[17].capacidadeMaxima = 40;*/

    strcpy(laboratorios[18].bloco, "J");
    strcpy(laboratorios[18].descricao, "Lab. de Fabricação Mecânica");
    strcpy(laboratorios[18].identificacao, "J106");
    laboratorios[18].capacidadeAtual = 35;
    laboratorios[18].capacidadeMaxima = 40;

    strcpy(laboratorios[19].bloco, "J");
    strcpy(laboratorios[19].descricao, "Lab. de Fabricação Mecânica");
    strcpy(laboratorios[19].identificacao, "J105");
    laboratorios[19].capacidadeAtual = 35;
    laboratorios[19].capacidadeMaxima = 40;

    strcpy(laboratorios[20].bloco, "J");
    strcpy(laboratorios[20].descricao, "Lab. de Materiais");
    strcpy(laboratorios[20].identificacao, "J103");
    laboratorios[20].capacidadeAtual = 35;
    laboratorios[20].capacidadeMaxima = 40;

    strcpy(laboratorios[21].bloco, "J");
    strcpy(laboratorios[21].descricao, "Lab. de Eletrônica");
    strcpy(laboratorios[21].identificacao, "J102");
    laboratorios[21].capacidadeAtual = 35;
    laboratorios[21].capacidadeMaxima = 40;

    strcpy(laboratorios[22].bloco, "J");
    strcpy(laboratorios[22].descricao, "Lab. de Robótica e CLP/Labmaker");
    strcpy(laboratorios[22].identificacao, "J101");
    laboratorios[22].capacidadeAtual = 35;
    laboratorios[22].capacidadeMaxima = 40;

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

void listarTodosEspacos(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan) {
    printf("\nSalas Teóricas:\n");
    for (int i = 0; i < MAX_SALAS; i++) {
        printf("Bloco: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
               salas[i].bloco, salas[i].identificacao, salas[i].capacidadeAtual, salas[i].capacidadeMaxima);
    }

    printf("\nLaboratórios:\n");
    for (int i = 0; i < MAX_LABS; i++) {
        printf("Bloco: %s, Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
               laboratorios[i].bloco, laboratorios[i].descricao, laboratorios[i].identificacao, laboratorios[i].capacidadeAtual, laboratorios[i].capacidadeMaxima);
    }

    printf("\nSalas Administrativas:\n");
    for (int i = 0; i < MAX_SALAS_ADM; i++) {
        printf("Bloco: %s, Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
               salasAdm[i].bloco, salasAdm[i].descricao, salasAdm[i].identificacao, salasAdm[i].capacidadeAtual, salasAdm[i].capacidadeMaxima);
    }

    printf("\nSalas dos Professores:\n");
    for (int i = 0; i < MAX_SALAS_PROF; i++) {
        printf("Bloco: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
               salasProf[i].bloco, salasProf[i].identificacao, salasProf[i].capacidadeAtual, salasProf[i].capacidadeMaxima);
    }

    printf("\nEspaços de Uso Geral:\n");
    for (int i = 0; i < MAX_SALAS_ADM; i++) {
        printf("Bloco: %s, Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
               espacos[i].bloco, espacos[i].descricao, espacos[i].identificacao, espacos[i].capacidadeAtual, espacos[i].capacidadeMaxima);
    }

    printf("\nPátio:\n");
    for (int i = 0; i < MAX_PATIOS; i++) {
        printf("Bloco: %s, Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
               patios[i].bloco, patios[i].descricao, patios[i].identificacao, patios[i].capacidadeAtual, patios[i].capacidadeMaxima);
    }

    printf("\nManutenção:\n");
    for (int i = 0; i < MAX_MANUTENCAO; i++) {
        printf("Bloco: %s, Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
               salasMan[i].bloco, salasMan[i].descricao, salasMan[i].identificacao, salasMan[i].capacidadeAtual, salasMan[i].capacidadeMaxima);
    }

    printf("\nGerais:\n");
    for (int i = 0; i < MAX_GERAIS; i++) {
        printf("Bloco: %s, Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
               gerais[i].bloco, gerais[i].descricao, gerais[i].identificacao, gerais[i].capacidadeAtual, gerais[i].capacidadeMaxima);
    }
}

void listarPorBloco(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan) {
    char bloco[2];
    printf("\nDigite o bloco a ser listado: ");
    scanf("%s", bloco);

    printf("\nEspaços no Bloco %s:\n", bloco);

    for (int i = 0; i < 12; i++) {
        if (strcmp(salas[i].bloco, bloco) == 0) {
            printf("Sala Teórica - Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                   salas[i].identificacao, salas[i].capacidadeAtual, salas[i].capacidadeMaxima);
        }
    }

    for (int i = 0; i < 2; i++) {
        if (strcmp(laboratorios[i].bloco, bloco) == 0) {
            printf("Laboratório - Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                   laboratorios[i].descricao, laboratorios[i].identificacao, laboratorios[i].capacidadeAtual, laboratorios[i].capacidadeMaxima);
        }
    }
}

void listarPorTipo(SalaTeorica *salas, Laboratorio *laboratorios, SalaAdministrativa *salasAdm, SalaProfessor *salasProf, EspacoDeUso *espacos, Patio *patios, Geral *gerais, Manutencao *salasMan) {
    char tipo[20];
    printf("\nDigite o tipo de espaço a ser listado (SalaTeorica, Laboratorio, etc.): ");
    scanf("%s", tipo);

    if (strcmp(tipo, "SalaTeorica") == 0) {
        printf("\nSalas Teóricas:\n");
        for (int i = 0; i < 12; i++) {
            printf("Bloco: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                   salas[i].bloco, salas[i].identificacao, salas[i].capacidadeAtual, salas[i].capacidadeMaxima);
        }
    } else if (strcmp(tipo, "Laboratorio") == 0) {
        printf("\nLaboratórios:\n");
        for (int i = 0; i < 2; i++) {
            printf("Bloco: %s, Descrição: %s, Identificação: %s, Capacidade Atual: %d, Capacidade Máxima: %d\n",
                   laboratorios[i].bloco, laboratorios[i].descricao, laboratorios[i].identificacao, laboratorios[i].capacidadeAtual, laboratorios[i].capacidadeMaxima);
        }
    }
}

void exibirEstatisticas(SalaTeorica *salas, Laboratorio *laboratorios) {
    double taxaOcupacao = calcularTaxaOcupacao(salas, 12);
    int computadoresNecessarios = calcularComputadoresNecessarios(laboratorios, 2);

    printf("\nEstatísticas:\n");
    printf("Taxa de Ocupação das Salas Teóricas: %.2f%%\n", taxaOcupacao * 100);
    printf("Computadores necessários para 100%% de ocupação: %d\n", computadoresNecessarios);
}

