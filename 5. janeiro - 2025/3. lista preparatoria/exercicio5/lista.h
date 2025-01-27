#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Produto {
    int codigo;
    char descricao[100];
    float valor;
    int quantidade;
    Data ultima_compra;
    struct Produto* proximo; 
} Produto;

void obterData(Data* data);
void obterProduto(Produto** lista);
void cadastrarProduto(Produto** lista, int codigo, const char* descricao, float valor, int quantidade, Data ultima_compra);
Produto* buscarProdutoMenorPreco(Produto* lista);
Produto* buscarProdutoEstoqueInferior(Produto* lista, int quantidade);
void apagarProduto(Produto** lista, int codigo);
void atualizarProduto(Produto* lista, int codigo, const char* descricao, float valor, int quantidade, Data ultima_compra);
void gerarRelatorioCrescente(Produto* lista);
void gerarRelatorioDecrescente(Produto* lista);
void imprimirProduto(Produto* p);

#endif
