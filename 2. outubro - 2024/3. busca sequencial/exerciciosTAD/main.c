#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    float dist;
    Ponto *p, *q;

    p = criaPto(10, 21);
    q = criaPto(7, 25);

    dist = distanciaPto(p, q);
    printf("Distância entre os pontos: %.1f\n", dist);

    liberaPto(p);
    liberaPto(q);

    return 0;
}