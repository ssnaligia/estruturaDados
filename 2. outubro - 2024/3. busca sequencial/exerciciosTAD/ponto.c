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

float distanciaPto(Ponto* p1, Ponto* p2) {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));  
}

Ponto* acessaPto(Ponto* p, float* x, float* y) {
    if (p != NULL) {
        *x = p->x;
        *y = p->y;
    }
    return p;  
}