#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

int main() {
    Ponto *p, *q, *r;

    p = criaPto(10, 21);
    q = criaPto(7, 25);
    r = criaPto(4, 29);

    if (saoColineares(p, q, r)) {
        printf("Os pontos p, q e r são colineares.\n");
    } else {
        printf("Os pontos p, q e r não são colineares.\n");
    }

    calculaDistancias(p, q, r);

    liberaPto(p);
    liberaPto(q);
    liberaPto(r);

    return 0;
}