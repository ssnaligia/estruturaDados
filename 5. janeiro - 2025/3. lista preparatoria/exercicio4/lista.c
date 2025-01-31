#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

void inicializarLista(Lista* lista) {
    lista->cabeca = NULL;
}

void inserirFinal(Lista* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if (lista->cabeca == NULL) {
        lista->cabeca = novoNo;
    } else {
        No* temp = lista->cabeca;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
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

void mergeOrdenado(Lista* l1, Lista* l2, Lista* l3) {
    No* temp1 = l1->cabeca;
    No* temp2 = l2->cabeca;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->valor < temp2->valor) { //se o valor de temp1 for menor, insira em l3
            if (l3->cabeca == NULL || l3->cabeca->valor != temp1->valor) {
                inserirFinal(l3, temp1->valor);
            }
            temp1 = temp1->proximo;
        }
        else if (temp1->valor > temp2->valor) { //se o valor de temp2 for menor, insira em l3
            if (l3->cabeca == NULL || l3->cabeca->valor != temp2->valor) {
                inserirFinal(l3, temp2->valor);
            }
            temp2 = temp2->proximo;
        }
        else { //se os valores forem iguais, insira apenas um
            if (l3->cabeca == NULL || l3->cabeca->valor != temp1->valor) {
                inserirFinal(l3, temp1->valor);
            }
            temp1 = temp1->proximo;
            temp2 = temp2->proximo;
        }
    }

    while (temp1 != NULL) { //insere os elementos restantes de l1, se houver
        if (l3->cabeca == NULL || l3->cabeca->valor != temp1->valor) {
            inserirFinal(l3, temp1->valor);
        }
        temp1 = temp1->proximo;
    }

    while (temp2 != NULL) { //insere os elementos restantes de l2, se houver
        if (l3->cabeca == NULL || l3->cabeca->valor != temp2->valor) {
            inserirFinal(l3, temp2->valor);
        }
        temp2 = temp2->proximo;
    }
}
