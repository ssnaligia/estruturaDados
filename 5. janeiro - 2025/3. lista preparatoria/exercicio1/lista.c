#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarLista(Lista *lista) { //inicializa a lista atribuindo tam zero
    lista->tamanho = 0;
}

int inserirElemento(Lista *lista, int valor) { //insere um elemento na lista se não estiver cheia
    if (lista->tamanho >= MAX)  //verifica se a lista está cheia
        return 0; //falha ao inserir
    
    lista->elementos[lista->tamanho++] = valor;  //adiciona o elemento e incrementa o tamanho
    return 1; 
}

int verificarOrdenacao(Lista *lista) { // verifica se a lista está ordenada em ordem crescente ou decrescente
    if (lista->tamanho < 2) { //listas com 0 ou 1 elemento são ordenadas por definição
        return 1;
    }  
    
    int crescente = 1, decrescente = 1;
    
    for (int i = 0; i < lista->tamanho - 1; i++) {
        if (lista->elementos[i] > lista->elementos[i + 1])  //se houver um número maior antes, não é crescente
            crescente = 0;
        if (lista->elementos[i] < lista->elementos[i + 1])  //se houver um número menor antes, não é decrescente
            decrescente = 0;
    }
    
    if (crescente) return 1;    //retorna 1 se a lista for crescente
    if (decrescente) return -1; //retorna -1 se a lista for decrescente
    return 0;
}
