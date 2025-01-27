#include <stdio.h>
#include "lista.h"

Produto* buscarProdutoPorCodigo(Produto* lista, int codigo);  

int main() {
    Produto* lista = NULL;
    int opcao;

    do {
        printf("\nMenu de opções:\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Buscar Produto de Menor Preço\n");
        printf("3 - Buscar Produto com Estoque Inferior\n");
        printf("4 - Apagar Produto\n");
        printf("5 - Atualizar Produto\n");
        printf("6 - Gerar Relatório Crescente\n");
        printf("7 - Gerar Relatório Decrescente\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                obterProduto(&lista);
                break;
            case 2: {
                Produto* menorPreco = buscarProdutoMenorPreco(lista);
                if (menorPreco != NULL) {
                    printf("\n\nProduto de menor preço:\n");
                    imprimirProduto(menorPreco);
                } else {
                    printf("\nNenhum produto cadastrado.\n");
                }
                break;
            }
            case 3: {
                int quantidade;
                printf("\nDigite a quantidade limite para estoque: ");
                scanf("%d", &quantidade);
                Produto* produtosComEstoqueBaixo = buscarProdutoEstoqueInferior(lista, quantidade);
                if (produtosComEstoqueBaixo != NULL) {
                    printf("\n\nProdutos com estoque inferior a %d:\n", quantidade);
                    Produto* temp = produtosComEstoqueBaixo;
                    while (temp != NULL) {
                        imprimirProduto(temp);
                        temp = temp->proximo;
                    }
                } else {
                    printf("\nNenhum produto com estoque inferior a %d.\n", quantidade);
                }
                break;
            }
            case 4: {
                int codigo;
                printf("\nDigite o código do produto a ser apagado: ");
                scanf("%d", &codigo);

                Produto* produto = buscarProdutoPorCodigo(lista, codigo);
                if (produto != NULL) {
                    apagarProduto(&lista, codigo);
                    printf("\nProduto apagado!\n");
                } else {
                    printf("\nProduto não encontrado.\n");
                }
                break;
            }
            case 5: {
                int codigo;
                printf("\nDigite o código do produto a ser atualizado: ");
                scanf("%d", &codigo);
                
                Produto* produto = buscarProdutoPorCodigo(lista, codigo);  
                if (produto != NULL) {
                    char descricao[100];
                    float valor;
                    int quantidade;
                    Data ultima_compra;

                    printf("\nDigite a nova descrição do produto: ");
                    getchar(); 
                    fgets(descricao, sizeof(descricao), stdin);
                    descricao[strcspn(descricao, "\n")] = 0; 
                    printf("\nDigite o novo valor do produto: ");
                    scanf("%f", &valor);
                    printf("\nDigite a nova quantidade em estoque: ");
                    scanf("%d", &quantidade);
                    
                    obterData(&ultima_compra);

                    atualizarProduto(lista, codigo, descricao, valor, quantidade, ultima_compra);
                    printf("\nProduto atualizado!\n");
                } else {
                    printf("\nProduto não encontrado.\n");
                }
                break;
            }
            case 6:
                gerarRelatorioCrescente(lista);
                break;
            case 7:
                gerarRelatorioDecrescente(lista);
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida, tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}