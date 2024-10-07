#include <stdio.h>
#include "produto.h"
#define MAX_PRODUTOS 15

typedef struct {
    int codigo;
    char nome[60];
    float preco;
    char validade[11];
} Produto;

Produto Produtos[MAX_PRODUTOS];
int numProdutos = 0;
int codigoAtual = 1;  /

void cadastroProduto() {
    if (numProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto novoProduto;
    novoProduto.codigo = codigoAtual;  
    codigoAtual++;  

    printf("Digite o nome: ");
    scanf(" %[^\n]", novoProduto.nome);
    printf("Digite o preço: ");
    scanf("%f", &novoProduto.preco);  
    printf("Digite a data de vencimento (DD/MM/AAAA): ");
    scanf("%s", novoProduto.validade);

    Produtos[numProdutos++] = novoProduto;  

    printf("Produto cadastrado com sucesso!\n");
}

void baixaEstoque() {
    int codigoProduto, quantidade;

    printf("Digite o código do produto que deseja dar baixa no estoque: ");
    scanf("%d", &codigoProduto);

    int encontrado = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (Produtos[i].codigo == codigoProduto) {
            printf("Produto encontrado: %s\n", Produtos[i].nome);
            printf("Digite a quantidade que deseja dar baixa: ");
            scanf("%d", &quantidade);

            if (quantidade <= Produtos[i].estoque) {
                Produtos[i].estoque -= quantidade; 
                printf("Baixa realizada com sucesso! Nova quantidade em estoque: %d\n", Produtos[i].estoque);
            } else {
                printf("Quantidade inválida! O estoque disponível é %d.\n", Produtos[i].estoque);
            }

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto não encontrado.\n");
    }
}