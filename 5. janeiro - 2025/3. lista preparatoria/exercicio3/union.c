#include <stdio.h>
#include <stdlib.h>
#include "union.h"

void inicializarLista(Lista* lista) {
    lista->cabeca = NULL;
}

void inserirFinal(Lista* lista, int valor) { //função para inserir um elemento no final da lista encadeada
    No* novoNo = (No*)malloc(sizeof(No));  // malloc retorna um ponteiro void, que é convertido para No*
    
    novoNo->valor = valor; //inicializa o valor do novo nó com o valor fornecido
    
    novoNo->proximo = NULL; //o campo 'proximo' do novo nó deve apontar para NULL, já que será o último nó

    if (lista->cabeca == NULL) {  
        lista->cabeca = novoNo; //se a lista estiver vazia, o novo nó será o primeiro nó da lista
    } else {
        No* temp = lista->cabeca; //se a lista não estiver vazia, percorre até o último nó
        
        while (temp->proximo != NULL) {  //enqt o nó atual não for o último (ou seja, o próximo nó não for NULL)
            temp = temp->proximo;  //move para o próximo nó
        }
        
        //temp aponta para o último nó e tualiza o campo 'proximo' do último nó para apontar para o novo nó.
        temp->proximo = novoNo;
    }
}

void imprimirLista(Lista* lista) {
    No* temp = lista->cabeca;
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->proximo;
    }
    printf("\n");
}

void unirListas(Lista* l1, Lista* l2, Lista* l3) {
    No* temp = l1->cabeca;
    
    while (temp != NULL) { //insere todos os elementos de l1 em l3
        inserirFinal(l3, temp->valor);
        temp = temp->proximo;
    }
    
    temp = l2->cabeca;
    
    while (temp != NULL) { //insere todos os elementos de l2 em l3
        inserirFinal(l3, temp->valor);
        temp = temp->proximo;
    }
}
