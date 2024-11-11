#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto {
    float x;
    float y;
} Ponto;

Ponto* criaPto(float x, float y) {
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

void liberaPto(Ponto* p) {
    free(p);
}

Ponto* acessaPto(Ponto* p, float* x, float* y) {
    if (p != NULL) {
        *x = p->x;
        *y = p->y;
    }
    return p;
}

float distanciaPto(Ponto* p1, Ponto* p2) {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

int saoColineares(Ponto* p1, Ponto* p2, Ponto* p3) {
    float determinante = (p2->x - p1->x) * (p3->y - p1->y) - (p3->x - p1->x) * (p2->y - p1->y);
    return (determinante == 0); 
}

void calculaDistancias(Ponto* p, Ponto* q, Ponto* r) {
    float d1 = distanciaPto(p, q);
    float d2 = distanciaPto(q, r);
    float d3 = distanciaPto(p, r);

    printf("Distância entre p e q: %.2f\n", d1);
    printf("Distância entre q e r: %.2f\n", d2);
    printf("Distância entre p e r: %.2f\n", d3);
}