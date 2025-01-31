#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "retangulo.h"

Retangulo* criarLista() {
    return NULL;
}

Retangulo* adicionarRetangulo(Retangulo* lista, float base, float altura) {
    Retangulo* novo = (Retangulo*)malloc(sizeof(Retangulo));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    novo->base = base;
    novo->altura = altura;
    novo->proximo = lista; 

    return novo;
}

void imprimirRetangulos(Retangulo* lista) {
    Retangulo* atual = lista;
    while (atual != NULL) {
        printf("Retângulo - Base: %.2f, Altura: %.2f, Área: %.2f\n",
               atual->base, atual->altura, calcularArea(atual));
        atual = atual->proximo;
    }
}

float calcularArea(Retangulo* ret) {
    if (ret == NULL) return 0;
    return ret->base * ret->altura;
}

void liberarLista(Retangulo* lista) {
    Retangulo* atual = lista;
    while (atual != NULL) {
        Retangulo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}
