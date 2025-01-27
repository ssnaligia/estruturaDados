#include <stdio.h>
#include <string.h>
#include "lista.h"

void obterData(Data* data) {
    printf("Digite a data da última compra (dd mm aaaa): ");
    scanf("%d %d %d", &data->dia, &data->mes, &data->ano);
}

void obterProduto(Produto** lista) {
    int codigo, quantidade;
    float valor;
    char descricao[100];
    Data ultima_compra;

    printf("\nDigite o código do produto: ");
    scanf("%d", &codigo);
    printf("Digite a descrição do produto: ");
    getchar(); 
    fgets(descricao, sizeof(descricao), stdin);
    descricao[strcspn(descricao, "\n")] = 0; 
    printf("Digite o valor do produto: ");
    scanf("%f", &valor);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &quantidade);

    obterData(&ultima_compra);

    cadastrarProduto(lista, codigo, descricao, valor, quantidade, ultima_compra);
}

void cadastrarProduto(Produto** lista, int codigo, const char* descricao, float valor, int quantidade, Data ultima_compra) {
    Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
    novoProduto->codigo = codigo;
    strcpy(novoProduto->descricao, descricao);
    novoProduto->valor = valor;
    novoProduto->quantidade = quantidade;
    novoProduto->ultima_compra = ultima_compra;
    novoProduto->proximo = *lista; //insere no início da lista
    *lista = novoProduto;
}

Produto* buscarProdutoPorCodigo(Produto* lista, int codigo) {
    Produto* temp = lista;
    while (temp != NULL) {
        if (temp->codigo == codigo) {
            return temp; 
        }
        temp = temp->proximo;
    }
    return NULL; 
}

Produto* buscarProdutoMenorPreco(Produto* lista) {
    Produto* menor = lista;
    while (lista != NULL) {
        if (lista->valor < menor->valor) {
            menor = lista;  
        }
        lista = lista->proximo;
    }
    return menor;
}

Produto* buscarProdutoEstoqueInferior(Produto* lista, int quantidade) {
    Produto* resultados = NULL;
    while (lista != NULL) {
        if (lista->quantidade < quantidade) {
            Produto* novoProduto = (Produto*)malloc(sizeof(Produto));
            *novoProduto = *lista;
            novoProduto->proximo = resultados;
            resultados = novoProduto;
        }
        lista = lista->proximo;
    }
    return resultados;
}

void apagarProduto(Produto** lista, int codigo) {
    Produto* temp = *lista;
    Produto* anterior = NULL;

    //se o produto a ser apagado for o primeiro
    if (temp != NULL && temp->codigo == codigo) {
        *lista = temp->proximo; //move a cabeça
        free(temp);
        return;
    }

    while (temp != NULL && temp->codigo != codigo) {  //procura o produto a ser apagado
        anterior = temp;
        temp = temp->proximo;
    }

    if (temp == NULL) return;

    //desvincula o produto da lista
    anterior->proximo = temp->proximo;
    free(temp);
}


void atualizarProduto(Produto* lista, int codigo, const char* descricao, float valor, int quantidade, Data ultima_compra) {
    Produto* produto = buscarProdutoPorCodigo(lista, codigo);
    if (produto != NULL) {
        strcpy(produto->descricao, descricao);
        produto->valor = valor;
        produto->quantidade = quantidade;
        produto->ultima_compra = ultima_compra;
    } else {
        printf("Produto não encontrado.\n");
    }
}

void gerarRelatorioCrescente(Produto* lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    
    int count = 0;
    Produto* temp = lista;
    while (temp != NULL) {
        count++;
        temp = temp->proximo;
    }
    
    Produto** produtos = (Produto**)malloc(count * sizeof(Produto*));
    temp = lista;
    for (int i = 0; i < count; i++) {
        produtos[i] = temp;
        temp = temp->proximo;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (produtos[i]->quantidade > produtos[j]->quantidade) {
                Produto* tempProduto = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = tempProduto;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        imprimirProduto(produtos[i]);
    }

    free(produtos);
}

void gerarRelatorioDecrescente(Produto* lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    
    int count = 0;
    Produto* temp = lista;
    while (temp != NULL) {
        count++;
        temp = temp->proximo;
    }
    
    Produto** produtos = (Produto**)malloc(count * sizeof(Produto*));
    temp = lista;
    for (int i = 0; i < count; i++) {
        produtos[i] = temp;
        temp = temp->proximo;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (produtos[i]->quantidade < produtos[j]->quantidade) {
                Produto* tempProduto = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = tempProduto;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        imprimirProduto(produtos[i]);
    }

    free(produtos);
}


void imprimirProduto(Produto* p) {
    printf("\nCodigo: %d\n", p->codigo);
    printf("Descricao: %s\n", p->descricao);
    printf("Valor: %.2f\n", p->valor);
    printf("Quantidade: %d\n", p->quantidade);
    printf("Ultima compra: %02d/%02d/%04d\n", p->ultima_compra.dia, p->ultima_compra.mes, p->ultima_compra.ano);
    printf("----------------------------\n");
}