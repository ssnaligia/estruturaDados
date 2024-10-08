#include <stdio.h>
#include <string.h> 
#include <locale.h>
#include "cliente/cliente.c"
#include "produto/produto.c"          

int main() {
    int escolha, eConsulta;
    char produtos[MAX_PRODUTOS][60]; 
    char datas[MAX_PRODUTOS][11];     
    int numProdutos = 0;

    do {
        printf("\n\n--- MENU CONTROLE DE ESTOQUE ---\n");
        printf("\n1. Cadastro de Clientes");
        printf("\n2. Cadastro de Produtos");
        printf("\n3. Consultas");
        printf("\n4. Venda");
        printf("\n5. Baixa em Estoque");
        printf("\n6. Encerrar");
        printf("\n\nDigite a opção desejada: ");
        scanf("%d", &escolha);

        if(escolha < 1 || escolha > 6) {
            printf("\nOpção Inválida!\n");
            continue;
        }

        switch (escolha) {
            case 1: {
                cadastroCliente();
                break;
            }
            case 2: {
                cadastroProduto();
                break;
            }
            case 3: {
                do {
                    printf("\n\n-- CONSULTAS --");
                    printf("\n1. Produtos Cadastrados");
                    printf("\n2. Produtos a Vencer");
                    printf("\n3. Produtos Vencidos");
                    printf("\n4. Clientes Cadastrados");
                    printf("\n5. Total de Vendas por Período");
                    printf("\n6. Quantidade em Estoque por Produto");
                    printf("\n7. Encerrar");
                    printf("\n\nDigite a opção desejada: ");
                    scanf("%d", &eConsulta);

                    if(eConsulta < 1 || eConsulta > 7) {
                        printf("\nOpção Inválida!\n");
                        continue;
                    }

                    switch (eConsulta) {
                        case 1: {
                            produtosCadastrados();
                            break;
                        }
                        case 2: {
                            produtosAVencer(produtos, datas, numProdutos);
                            break;
                        }
                        case 3: {
                            // produtosVencidos();
                            printf("\nConsulta: Produtos Vencidos.\n");
                            break;
                        }
                        case 4: {
                            // clientesCadastrados();
                            printf("\nConsulta: Clientes Cadastrados.\n");
                            break;
                        }
                        case 5: {
                            // totalVendas();
                            printf("\nConsulta: Total de Vendas por Período.\n");
                            break;
                        }
                        case 6: {
                            // quantidadeEmEstoque();
                            printf("\nConsulta: Quantidade em Estoque por Produto.\n");
                            break;
                        }
                        case 7: {
                            printf("\nSaindo do menu de consultas...\n");
                            break;
                        }
                    }
                } while(eConsulta != 7);
                break;
            }
            case 4: {
                vendas();
                break;
            }
            case 5: {
                baixaEstoque();
                break;
            }
            case 6: {
                printf("\nSaindo...\n");
                break;
            }
        }
    } while(escolha != 6); 
}
