#include "media.h"
#define TAM 3

float mediaPonderada(float a, int peso1, float b, int peso2) {
    return ((a*peso1)+(b*peso2))/(peso1+peso2);
}

float mediaAritmetica(float medias[TAM]) {
    float soma = 0;
    for(int i = 0; i < TAM; i++) {
        soma += medias[i];
    }
    return soma / TAM;
}

