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

    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(Produtos[i].nome, novoProduto.nome) == 0) {
            printf("Produto com o nome '%s' já cadastrado! Cadastro não permitido.\n", novoProduto.nome);
            return;
        }
    }

    printf("\nDigite o preço: ");
    scanf("%f", &novoProduto.preco);  
    printf("\nDigite a data de vencimento (DD/MM/AAAA): ");
    scanf("%s", novoProduto.validade);
    printf("\nDigite a quantidade: ");
    scanf("%d", &novoProduto.estoque);

    Produtos[numProdutos++] = novoProduto;  

    printf("\n\nProduto cadastrado com sucesso!\n");
}

void produtosCadastrados() {
    if (numProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\n--- PRODUTOS CADASTRADOS ---\n");
    printf("\n\n%-10s %-30s %-10s %-12s %-10s\n", "Código", "Nome", "Preço", "Validade", "Estoque");
    printf("---------------------------------------------------------------------------------\n");

    for (int i = 0; i < numProdutos; i++) {
        printf("%-10d %-30s R$ %-9.2f %-12s %d\n", 
            Produtos[i].codigo, 
            Produtos[i].nome, 
            Produtos[i].preco, 
            Produtos[i].validade, 
            Produtos[i].estoque);
    }
    printf("----------------------------------------------------------------------------------\n");
}

int compararDatas(const char *data1, const char *data2) {
    int dia1, mes1, ano1;
    int dia2, mes2, ano2;

    sscanf(data1, "%d/%d/%d", &dia1, &mes1, &ano1);
    sscanf(data2, "%d/%d/%d", &dia2, &mes2, &ano2);

    // Comparar anos
    if (ano1 != ano2) {
        return ano1 - ano2;
    }

    // Comparar meses
    if (mes1 != mes2) {
        return mes1 - mes2;
    }

    // Comparar dias
    return dia1 - dia2;
}

// Função para adicionar dias a uma data
void adicionarDias(const char* data, int dias, char* novaData) {
    int dia, mes, ano;
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);

    // Ajustes para os meses e seus dias
    int diasPorMes[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // Meses de 1 a 12

    dia += dias;

    // Se a data está fora do mês, ajusta o mês e o ano
    while (dia > diasPorMes[mes]) {
        dia -= diasPorMes[mes];
        mes++;
        if (mes > 12) {
            mes = 1;
            ano++;
        }
    }

    sprintf(novaData, "%02d/%02d/%04d", dia, mes, ano);
}

void produtosAVencer(char produtos[][60], char datas[][11], int numProdutos) {
    char dataAtual[11];
    int xDias;

    // Solicitar ao usuário a data atual e a quantidade de dias
    printf("Digite a data atual (DD/MM/AAAA): ");
    scanf("%s", dataAtual);

    printf("Digite a quantidade de dias: ");
    scanf("%d", &xDias);

    char dataLimite[11];
    adicionarDias(dataAtual, xDias, dataLimite);  // Calcula a nova data

    int encontrouProduto = 0;

    printf("\nProdutos a vencer nos próximos %d dias a partir de %s:\n", xDias, dataAtual);
    for (int i = 0; i < numProdutos; i++) {
        // Verifica se a data de vencimento é maior ou igual à data atual e menor ou igual à data limite
        if (compararDatas(datas[i], dataAtual) >= 0 && compararDatas(datas[i], dataLimite) <= 0) {
            printf("%s - Vencimento: %s\n", produtos[i], datas[i]);
            encontrouProduto = 1;
        }
    }

    if (!encontrouProduto) {
        printf("Nenhum produto a vencer nos próximos %d dias a partir de %s.\n", xDias, dataAtual);
    }
}


void vendas() {
    int codigoProduto, quantidade, quantidades[MAX_PRODUTOS];
    int produtosComprados[MAX_PRODUTOS];
    int numProdutosComprados = 0;
    float total = 0.0, valorPago, troco;

    printf("\n\nDigite o código do produto que deseja comprar: ");
    scanf("%d", &codigoProduto);

    int encontrado = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (Produtos[i].codigo == codigoProduto) {
            printf("\nProduto encontrado: %s\n", Produtos[i].nome);
            printf("\nDigite a quantidade que deseja comprar: ");
            
            if (scanf("%d", &quantidade) != 1) {
                printf("Entrada inválida para quantidade! Tente novamente.\n");
                while (getchar() != '\n'); 
                return; 
            }

            if (quantidade <= Produtos[i].estoque) {
                float subtotal = Produtos[i].preco * quantidade;
                total += subtotal;

                produtosComprados[numProdutosComprados] = i; 
                quantidades[numProdutosComprados] = quantidade;
                numProdutosComprados++;

                printf("Subtotal: R$ %.2f\n", subtotal);
            } else {
                printf("\nEstoque insuficiente! Quantidade disponível: %d\n", Produtos[i].estoque);
                return; 
            }

            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        printf("\n\nTotal da compra: R$ %.2f\n", total);

        printf("\n\nFORMAS DE PAGAMENTO\n");
        printf("1. À vista (10%% de desconto)\n");
        printf("2. Parcelado em 3x (sem juros)\n");
        printf("3. Parcelado de 4x a 6x (com 10%% de juros)\n");
        printf("\nEscolha a forma de pagamento: ");
        int formaPagamento;
        scanf("%d", &formaPagamento);

        switch (formaPagamento) {
            case 1:
                //pagamento à vista com desconto de 10%
                total *= 0.9;  
                printf("\n\nTotal com desconto (à vista): R$ %.2f\n", total);

                printf("\nDigite o valor pago pelo cliente: R$ ");
                scanf("%f", &valorPago);

                if (valorPago >= total) {
                    troco = valorPago - total;
                    printf("Pagamento aceito.\n");
                    printf("\nTroco: R$ %.2f\n", troco);

                    for (int i = 0; i < numProdutosComprados; i++) {
                        Produtos[produtosComprados[i]].estoque -= quantidades[i];
                    }
                    printf("\nEstoque atualizado com sucesso.\n");
                } else {
                    printf("\nValor pago insuficiente. Faltam R$ %.2f\n", total - valorPago);
                    return; 
                }
                break;

            case 2: {
                //pagamento parcelado em 3x sem juros
                float parcela = total / 3;
                printf("\n\nTotal parcelado em 3x de R$ %.2f\n", parcela);

                printf("\nDigite o valor pago referente à primeira parcela: R$ ");
                scanf("%f", &valorPago);

                if (valorPago >= parcela) {
                    troco = valorPago - parcela;
                    printf("Pagamento da primeira parcela aceito.\n");
                    printf("\nTroco da primeira parcela: R$ %.2f\n", troco);

                    for (int i = 0; i < numProdutosComprados; i++) {
                        Produtos[produtosComprados[i]].estoque -= quantidades[i];
                    }
                    printf("\nEstoque atualizado com sucesso.\n");
                } else {
                    printf("\nValor pago insuficiente para a primeira parcela. Faltam R$ %.2f\n", parcela - valorPago);
                    return; 
                }
                break;
            }

            case 3: {
                //pagamento parcelado de 4x a 6x com 10% de juros
                total *= 1.1; 
                int parcelas;
                printf("\n\nEscolha entre 4 a 6 parcelas: ");
                scanf("%d", &parcelas);

                if (parcelas >= 4 && parcelas <= 6) {
                    float parcela = total / parcelas;
                    printf("\n\nTotal parcelado em %dx de R$ %.2f\n", parcelas, parcela);

                    printf("\nDigite o valor pago referente à primeira parcela: R$ ");
                    scanf("%f", &valorPago);

                    if (valorPago >= parcela) {
                        troco = valorPago - parcela;
                        printf("Pagamento da primeira parcela aceito.\n");
                        printf("\nTroco da primeira parcela: R$ %.2f\n", troco);

                        for (int i = 0; i < numProdutosComprados; i++) {
                            Produtos[produtosComprados[i]].estoque -= quantidades[i];
                        }
                        printf("\nEstoque atualizado com sucesso.\n");
                    } else {
                        printf("\nValor pago insuficiente para a primeira parcela. Faltam R$ %.2f\n", parcela - valorPago);
                        return; 
                    }
                } else {
                    printf("\nNúmero de parcelas inválido!\n");
                }
                break;
            }

            default:
                printf("\nForma de pagamento inválida.\n");
                return;
        }

        printf("\nVenda concluída!\n");
    } else {
        printf("\nProduto não encontrado.\n");
    }
}

void baixaEstoque() {
    int codigoProduto, quantidade;

    printf("\n\nDigite o código do produto que deseja dar baixa no estoque: ");
    scanf("%d", &codigoProduto);

    int encontrado = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (Produtos[i].codigo == codigoProduto) {
            printf("Produto encontrado: %s\n", Produtos[i].nome);
            printf("\n\nDigite a quantidade que deseja dar baixa: ");
            scanf("%d", &quantidade);

            if (quantidade <= Produtos[i].estoque) {
                Produtos[i].estoque -= quantidade; 
                printf("\n\nBaixa realizada com sucesso! Nova quantidade em estoque: %d\n", Produtos[i].estoque);
            } else {
                printf("\n\nQuantidade inválida! O estoque disponível é %d.\n", Produtos[i].estoque);
            }

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nProduto não encontrado.\n");
    }
}