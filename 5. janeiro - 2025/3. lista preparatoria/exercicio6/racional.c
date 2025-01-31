#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

int mdc(int a, int b) {
    if (b == 0) return abs(a);
    return mdc(b, a % b);
}

Racional criarRacional(int numerador, int denominador) {
    if (denominador == 0) {
        printf("Erro: Denominador não pode ser zero.\n");
        exit(1);
    }

    Racional r;
    int divisor = mdc(numerador, denominador);
    
    r.numerador = numerador / divisor;
    r.denominador = denominador / divisor;

    if (r.denominador < 0) {  //garante que o denominador seja sempre positivo
        r.numerador *= -1;
        r.denominador *= -1;
    }

    return r;
}

Racional somaRacional(Racional r1, Racional r2) {
    int num = r1.numerador * r2.denominador + r2.numerador * r1.denominador;
    int den = r1.denominador * r2.denominador;
    return criarRacional(num, den);
}

Racional multiplicaRacional(Racional r1, Racional r2) {
    int num = r1.numerador * r2.numerador;
    int den = r1.denominador * r2.denominador;
    return criarRacional(num, den);
}

int saoIguais(Racional r1, Racional r2) {
    return (r1.numerador == r2.numerador && r1.denominador == r2.denominador);
}

void imprimirRacional(Racional r) {
    printf("%d/%d\n", r.numerador, r.denominador);
}
