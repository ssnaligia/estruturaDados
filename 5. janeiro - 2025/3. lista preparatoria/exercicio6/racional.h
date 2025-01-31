#ifndef RACIONAL_H
#define RACIONAL_H

typedef struct {
    int numerador;
    int denominador;
} Racional;

Racional criarRacional(int numerador, int denominador);
Racional somaRacional(Racional r1, Racional r2);
Racional multiplicaRacional(Racional r1, Racional r2);
int saoIguais(Racional r1, Racional r2);
void imprimirRacional(Racional r);

#endif
