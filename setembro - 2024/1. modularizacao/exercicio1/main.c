#include <stdio.h>
#include <locale.h>
#include "media.c"
#define TAM 3

int main() {
    float a=0, b=0;
    int peso1=0, peso2=0;
    float medias[TAM];
    float nota;

    printf("Digite a N1: ");
    scanf("%f", &a);

    printf("\nDigite o peso da N1: ");
    scanf("%d", &peso1);

    printf("\nDigite a N2: ");
    scanf("%f", &b);

    printf("\nDigite o peso da N2: ");
    scanf("%d", &peso2);

    printf("\nMédia Ponderada: %.1f", mediaPonderada(a, peso1, b, peso2));

    for(int i=0; i<TAM; i++) {
        printf("\n\nDigite a nota [%d]: ", i);
        scanf("%f", & medias[i]);
    }
    printf("\nMédia Aritmética: %.1f", mediaAritmetica(medias));
}


