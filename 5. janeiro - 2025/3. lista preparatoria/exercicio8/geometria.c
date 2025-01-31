#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "geometria.h"

#define PI 3.14159265359

Forma* criarLista() {
    return NULL;
}

Forma* adicionarForma(Forma* lista, TipoForma tipo, float p1, float p2) {
    Forma* nova = (Forma*)malloc(sizeof(Forma));
    if (nova == NULL) {
        printf("\nErro ao alocar memória.\n");
        exit(1);
    }

    nova->tipo = tipo;
    nova->parametro1 = p1;
    nova->parametro2 = p2;
    nova->proximo = lista; 

    return nova;
}

float calcularArea(Forma* forma) {
    if (forma == NULL) return 0;

    switch (forma->tipo) {
        case RETANGULO:
            return forma->parametro1 * forma->parametro2;
        case TRIANGULO:
            return (forma->parametro1 * forma->parametro2) / 2;
        case CIRCULO:
            return PI * pow(forma->parametro1, 2);
        default:
            return 0;
    }
}

void imprimirFormas(Forma* lista) {
    Forma* atual = lista;
    while (atual != NULL) {
        switch (atual->tipo) {
            case RETANGULO:
                printf("\nRetângulo - Base: %.2f, Altura: %.2f, Área: %.2f\n",
                       atual->parametro1, atual->parametro2, calcularArea(atual));
                break;
            case TRIANGULO:
                printf("\nTriângulo - Base: %.2f, Altura: %.2f, Área: %.2f\n",
                       atual->parametro1, atual->parametro2, calcularArea(atual));
                break;
            case CIRCULO:
                printf("\nCírculo - Raio: %.2f, Área: %.2f\n",
                       atual->parametro1, calcularArea(atual));
                break;
        }
        atual = atual->proximo;
    }
}

void liberarLista(Forma* lista) {
    Forma* atual = lista;
    while (atual != NULL) {
        Forma* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}
