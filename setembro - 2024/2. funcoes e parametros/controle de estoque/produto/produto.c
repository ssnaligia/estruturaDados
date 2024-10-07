#include <stdio.h>
#include "produto.h"
#define MAX_PRODUTOS 15

typedef struct {
    int codigo;
    char nome[60];
    float preco;
    char validade[11];
    int estoque;
} Produto;

Produto Produtos[MAX_PRODUTOS];
int numProdutos = 0;
int codigoAtual = 1;

void cadastroProduto() {
    if (numProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto novoProduto;
    novoProduto.codigo = codigoAtual;  
    codigoAtual++;  

    printf("\n\nDigite o nome do produto: ");
    scanf(" %[^\n]", novoProduto.nome);
    printf("\nDigite o preço: ");
    scanf("%f", &novoProduto.preco);  
    printf("\nDigite a data de vencimento (DD/MM/AAAA): ");
    scanf("%s", novoProduto.validade);
    printf("\nDigite a quantidade: ");
    scanf("%d", &novoProduto.estoque);

    Produtos[numProdutos++] = novoProduto;  

    printf("\n\nProduto cadastrado com sucesso!\n");
}

void vendas() {
    int codigoProduto, quantidade, quantidades[MAX_PRODUTOS];
    int produtosComprados[MAX_PRODUTOS];
    int numProdutosComprados = 0;
    float total = 0.0, valorPago, troco;
    char continuar;

    do {
        printf("\n\nDigite o código do produto que deseja comprar: ");
        scanf("%d", &codigoProduto);

        int encontrado = 0;
        for (int i = 0; i < numProdutos; i++) {
            if (Produtos[i].codigo == codigoProduto) {
                printf("\nProduto encontrado: %s\n", Produtos[i].nome);
                printf("Digite a quantidade que deseja comprar: ");
                scanf("%d", &quantidade);

                if (quantidade <= Produtos[i].estoque) {
                    float subtotal = Produtos[i].preco * quantidade;
                    total += subtotal;

                    //armazena o produto e a quantidade para dar baixa após o pagamento
                    produtosComprados[numProdutosComprados] = i;  //armazena o índice do produto
                    quantidades[numProdutosComprados] = quantidade;
                    numProdutosComprados++;

                    printf("\nSubtotal: R$ %.2f\n", subtotal);
                } else {
                    printf("Estoque insuficiente! Quantidade disponível: %d\n", Produtos[i].estoque);
                }

                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Produto não encontrado.\n");
        }

        printf("\nDeseja continuar comprando? SIM(s) / NÃO(n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's');

    if(continuar == 's') {
        printf("\n\nTotal da compra: R$ %.2f\n", total);

    printf("Escolha a forma de pagamento:\n");
    printf("1. À vista (10%% de desconto)\n");
    printf("2. Parcelado em 3x (sem juros)\n");
    printf("3. Parcelado de 4x a 6x (com 10%% de juros)\n");

    int formaPagamento;
    scanf("%d", &formaPagamento);

    switch (formaPagamento) {
        case 1:
            //pagamento à vista com desconto de 10%
            total *= 0.9;  
            printf("Total com desconto (à vista): R$ %.2f\n", total);

            printf("Digite o valor pago pelo cliente: R$ ");
            scanf("%f", &valorPago);

            if (valorPago >= total) {
                troco = valorPago - total;
                printf("Pagamento aceito.\n");
                printf("Troco: R$ %.2f\n", troco);

                for (int i = 0; i < numProdutosComprados; i++) {
                    Produtos[produtosComprados[i]].estoque -= quantidades[i];
                }
                printf("Estoque atualizado com sucesso.\n");
            } else {
                printf("Valor pago insuficiente. Faltam R$ %.2f\n", total - valorPago);
                return; 
            }
            break;

        case 2: {
            //pagamento parcelado em 3x sem juros
            float parcela = total / 3;
            printf("Total parcelado em 3x de R$ %.2f\n", parcela);

            printf("Digite o valor pago referente à primeira parcela: R$ ");
            scanf("%f", &valorPago);

            if (valorPago >= parcela) {
                troco = valorPago - parcela;
                printf("Pagamento da primeira parcela aceito.\n");
                printf("Troco da primeira parcela: R$ %.2f\n", troco);

                for (int i = 0; i < numProdutosComprados; i++) {
                    Produtos[produtosComprados[i]].estoque -= quantidades[i];
                }
                printf("Estoque atualizado com sucesso.\n");
            } else {
                printf("Valor pago insuficiente para a primeira parcela. Faltam R$ %.2f\n", parcela - valorPago);
                return; 
            }
            break;
        }

        case 3: {
            //pagamento parcelado de 4x a 6x com 10% de juros
            total *= 1.1; 
            int parcelas;
            printf("Escolha entre 4 a 6 parcelas: ");
            scanf("%d", &parcelas);

            if (parcelas >= 4 && parcelas <= 6) {
                float parcela = total / parcelas;
                printf("Total parcelado em %dx de R$ %.2f\n", parcelas, parcela);

                printf("Digite o valor pago referente à primeira parcela: R$ ");
                scanf("%f", &valorPago);

                if (valorPago >= parcela) {
                    troco = valorPago - parcela;
                    printf("Pagamento da primeira parcela aceito.\n");
                    printf("Troco da primeira parcela: R$ %.2f\n", troco);

                    for (int i = 0; i < numProdutosComprados; i++) {
                        Produtos[produtosComprados[i]].estoque -= quantidades[i];
                    }
                    printf("Estoque atualizado com sucesso.\n");
                } else {
                    printf("Valor pago insuficiente para a primeira parcela. Faltam R$ %.2f\n", parcela - valorPago);
                    return; 
                }
            } else {
                printf("Número de parcelas inválido!\n");
            }
            break;
        }

        default:
            printf("Forma de pagamento inválida.\n");
            return;
    }

    printf("Venda concluída!\n");
    
    }
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