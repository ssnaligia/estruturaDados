#ifndef PILHA_H
#define PILHA_H

#define MAX 10  

typedef struct {
    int topo1, topo2;
    int dados[MAX];
} PilhaDupla;

void inicializarPilha(PilhaDupla* p);
int pushP1(PilhaDupla* p, int valor);
int pushP2(PilhaDupla* p, int valor);
int popP1(PilhaDupla* p);
int popP2(PilhaDupla* p);
void mostrarPilhas(PilhaDupla* p);

#endif
