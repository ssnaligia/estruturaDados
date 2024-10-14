#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "produto.h"
#define MAX_PRODUTOS 15
#define MAX_VENDAS 100

typedef struct {
    int codigo;
    char nome[60];
    float preco;
    char validade[11];
    int estoque;
} Produto;

typedef struct {
    float valorTotal;
    char data[11]; 
} Venda;

Produto Produtos[MAX_PRODUTOS];
Venda Vendas[MAX_VENDAS];
int numProdutos = 0;
int codigoAtual = 1;
int numVendas = 0;

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
    printf("\n--- PRODUTOS CADASTRADOS ---\n\n");
    for (int i = 0; i <numProdutos; i++) {
        printf("Código: %d | Nome: %s | Valor: %.2f | Validade: %s | Quantidade: %d\n",
               Produtos[i].codigo, Produtos[i].nome, Produtos[i].preco,
               Produtos[i].validade, Produtos[i].estoque);
    }
}

void produtosAVencer(int dias) {
    int encontrouProduto = 0;

    time_t agora = time(NULL);
    struct tm *tm_atual = localtime(&agora);
    
    tm_atual->tm_mday += dias;
    time_t dataFutura = mktime(tm_atual);

    printf("\n--- PRODUTOS COM VALIDADE EM ATÉ %d DIAS (QUE AINDA NÃO VENCERAM) ---\n\n", dias);
    
    for (int i = 0; i < numProdutos; i++) {
        struct tm tm_validade = {0};
        
        strptime(Produtos[i].validade, "%d/%m/%Y", &tm_validade);
        time_t validadeProduto = mktime(&tm_validade);
        
        if (validadeProduto > agora && difftime(validadeProduto, agora) <= dias * 86400) {
            printf("Código: %d | Nome: %s | Validade: %s\n", 
                   Produtos[i].codigo, Produtos[i].nome, Produtos[i].validade);
            encontrouProduto = 1;
        }
    }

    if (!encontrouProduto) {
        printf("\n\nNenhum produto a vencer nos próximos %d dias.\n", dias);
    }
}

void produtosVencidos() {
    time_t agora = time(NULL);
    printf("\n--- PRODUTOS VENCIDOS ---\n\n");
    for (int i = 0; i < numProdutos; i++) {
        struct tm tm_validade;
        strptime(Produtos[i].validade, "%d/%m/%Y", &tm_validade);
        if (difftime(mktime(&tm_validade), agora) < 0) {
            printf("Código: %d | Nome: %s | Validade: %s\n", 
                   Produtos[i].codigo, Produtos[i].nome, Produtos[i].validade);
        }
    }
}

void vendas() {
    int codigo, quantidade;
    float subtotal = 0.0, total = 0.0, valorPago = 0.0, troco = 0.0;
    int opcaoPagamento, parcelas = 1;
    char dataVenda[11];
    
    printf("\n\nDigite o código do produto que deseja comprar: ");
    scanf("%d", &codigo);
    getchar();  

    int produtoIndex = -1;
    for (int i = 0; i < numProdutos; i++) {
        if (Produtos[i].codigo == codigo) {
            produtoIndex = i;
            break;
        }
    }

    if (produtoIndex == -1) {
        printf("\n\nProduto não encontrado!\n");
        return;
    }

    printf("\nProduto encontrado: %s\n", Produtos[produtoIndex].nome);
    
    printf("\nDigite a quantidade que deseja comprar: ");
    scanf("%d", &quantidade);
    getchar();  

    if (Produtos[produtoIndex].estoque < quantidade) {
        printf("\nEstoque insuficiente!\n");
        return;
    }

    subtotal = Produtos[produtoIndex].preco * quantidade;
    printf("\n\nSubtotal: R$ %.2f\n", subtotal);

    printf("\n\nFORMAS DE PAGAMENTO\n");
    printf("1. À vista (10%% de desconto)\n");
    printf("2. Parcelado em 3x (sem juros)\n");
    printf("3. Parcelado de 4x a 6x (com 10%% de juros)\n");

    printf("Escolha a forma de pagamento: ");
    scanf("%d", &opcaoPagamento);
    getchar();  

    switch(opcaoPagamento) {
        case 1:  //à vista com 10% de desconto
            total = subtotal * 0.9;
            printf("\nTotal à vista com 10%% de desconto: R$ %.2f\n", total);
            break;
        case 2:  //parcelado em 3x sem juros
            total = subtotal;
            parcelas = 3;
            printf("\nTotal parcelado em 3x de R$ %.2f\n", total / parcelas);
            break;
        case 3:  //parcelado de 4x a 6x com 10% de juros
            total = subtotal * 1.1;
            printf("\n\nDigite o número de parcelas (4 a 6): ");
            scanf("%d", &parcelas);
            getchar();  
            if (parcelas < 4 || parcelas > 6) {
                printf("\nNúmero de parcelas inválido!\n");
                return;
            }
            printf("\n\nTotal parcelado em %dx de R$ %.2f\n", parcelas, total / parcelas);
            break;
        default:
            printf("\nOpção de pagamento inválida!\n");
            return;
    }

    printf("\nDigite a data da venda (DD/MM/AAAA): ");
    fgets(dataVenda, sizeof(dataVenda), stdin);
    dataVenda[strcspn(dataVenda, "\n")] = 0; 

    printf("\nDigite o valor pago referente à primeira parcela: R$ ");
    scanf("%f", &valorPago);

    if (valorPago >= (total / parcelas)) {
        troco = valorPago - (total / parcelas);
        printf("\nPagamento aceito.\nTroco: R$ %.2f\n", troco);

        Produtos[produtoIndex].estoque -= quantidade;
        registrarVenda(total, dataVenda);  
        printf("\n\nEstoque atualizado com sucesso.\n");
        printf("\nVenda concluída!\n");
    } else {
        printf("\nValor insuficiente!\n");
    }
}

void registrarVenda(float total, const char *dataVenda) {
    if (numVendas >= MAX_VENDAS) {
        printf("\n\nLimite de vendas atingido!\n");
        return;
    }
    
    Vendas[numVendas].valorTotal = total;
    strcpy(Vendas[numVendas].data, dataVenda);
    numVendas++;
}

time_t converteData(const char *data) {
    struct tm tm_data = {0};
    strptime(data, "%d/%m/%Y", &tm_data);
    return mktime(&tm_data);
}

void totalVendas(const char *dataInicio, const char *dataFim) {
    time_t inicio = converteData(dataInicio); 
    time_t fim = converteData(dataFim); 
    
    float total = 0.0;

    printf("\n\n--- TOTAL DE VENDAS DE %s ATÉ %s ---\n", dataInicio, dataFim);

    for (int i = 0; i < numVendas; i++) {
        time_t dataVenda = converteData(Vendas[i].data);
        
        if (dataVenda >= inicio && dataVenda <= fim) {
            total += Vendas[i].valorTotal;
            printf("\nVENDA DE R$%.2f EM %s\n", Vendas[i].valorTotal, Vendas[i].data);
        }
    }

    printf("\n\nTOTAL DE VENDAS NO PERÍODO: R$%.2f\n", total);
}

void quantidadeEmEstoque() {
    if (numProdutos == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    printf("\n--- QUANTIDADE EM ESTOQUE EM PRODUTO ---\n\n");
    
    for (int i = 0; i < numProdutos; i++) {
        printf("Código: %d | Nome: %s | Estoque: %d\n", 
               Produtos[i].codigo, Produtos[i].nome, Produtos[i].estoque);
    }
}

void baixaEstoque() {
    int codigo, quantidade;

    printf("\n\nDigite o código do produto que deseja dar baixa no estoque: ");
    scanf("%d", &codigo);

    int produtoIndex = -1;
    for (int i = 0; i < numProdutos; i++) {
        if (Produtos[i].codigo == codigo) {
            produtoIndex = i;
            break;
        }
    }

    if (produtoIndex == -1) {
        printf("\nProduto não encontrado!\n");
        return;
    }

    printf("\nProduto encontrado: %s\n", Produtos[produtoIndex].nome);
    
    printf("\nDigite a quantidade que deseja dar baixa: ");
    scanf("%d", &quantidade);

    if (Produtos[produtoIndex].estoque < quantidade) {
        printf("\nQuantidade inválida, estoque insuficiente!\n");
    } else {
        Produtos[produtoIndex].estoque -= quantidade;
        printf("\nBaixa realizada com sucesso! Nova quantidade em estoque: %d\n", Produtos[produtoIndex].estoque);
    }
}