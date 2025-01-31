#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "aeroporto.h"

FilaPrioridade* criarFila() {
    FilaPrioridade* fila = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    fila->inicio = NULL;
    return fila;
}

void inserirAviao(FilaPrioridade* fila, char* id, int combustivel) {
    Aviao* novo = (Aviao*)malloc(sizeof(Aviao));
    strcpy(novo->id, id);
    novo->combustivel = combustivel;
    novo->proximo = NULL;

    if (fila->inicio == NULL || combustivel < fila->inicio->combustivel) { //se a fila está vazia ou o novo avião tem maior prioridade (menor combustível)
        novo->proximo = fila->inicio;
        fila->inicio = novo;
    } else {
        Aviao* atual = fila->inicio;
        while (atual->proximo != NULL && atual->proximo->combustivel <= combustivel) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
    }

    printf("\nAvião %s adicionado à fila com combustível: %d\n", id, combustivel);
}

void pousarAviao(FilaPrioridade* fila) {
    if (fila->inicio == NULL) {
        printf("\nNenhum avião na fila de pouso!\n");
        return;
    }

    Aviao* remover = fila->inicio;
    printf("\nAvião %s pousou (combustível restante: %d).\n", remover->id, remover->combustivel);
    fila->inicio = fila->inicio->proximo;
    free(remover);
}

void listarFila(FilaPrioridade* fila) {
    if (fila->inicio == NULL) {
        printf("\nNenhum avião na fila de pouso!\n");
        return;
    }

    printf("\nFila de Pouso (ordem de prioridade):\n");
    Aviao* atual = fila->inicio;
    while (atual != NULL) {
        printf("\nAvião %s - Combustível: %d\n", atual->id, atual->combustivel);
        atual = atual->proximo;
    }
}

void liberarFila(FilaPrioridade* fila) {
    Aviao* atual = fila->inicio;
    while (atual != NULL) {
        Aviao* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(fila);
}