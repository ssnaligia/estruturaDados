#include <stdio.h>
#include <locale.h>
#include "pilha.h"

void inicializarPilha(PilhaDupla* p) {
    p->topo1 = -1;   
    p->topo2 = MAX;  
}


int pushP1(PilhaDupla* p, int valor) { //insere um elemento na pilha 1
    if (p->topo1 + 1 == p->topo2) {
        printf("Erro: Overflow na Pilha 1!\n");
        return 0;
    }
    p->dados[++p->topo1] = valor;
    return 1;
}

int pushP2(PilhaDupla* p, int valor) { //insere um elemento na pilha 2
    if (p->topo1 + 1 == p->topo2) {
        printf("Erro: Overflow na Pilha 2!\n");
        return 0;
    }
    p->dados[--p->topo2] = valor;
    return 1;
}

int popP1(PilhaDupla* p) { //remove um elemento da pilha 1
    if (p->topo1 == -1) {
        printf("\nErro: Underflow na Pilha 1!\n");
        return -1;
    }
    return p->dados[p->topo1--];
}

int popP2(PilhaDupla* p) { //remove um elemento da pilha 2
    if (p->topo2 == MAX) {
        printf("\nErro: Underflow na Pilha 2!\n");
        return -1;
    }
    return p->dados[p->topo2++];
}

void mostrarPilhas(PilhaDupla* p) {
    printf("\nPilha 1: ");
    for (int i = 0; i <= p->topo1; i++) {
        printf("%d ", p->dados[i]);
    }

    printf("\nPilha 2: ");
    for (int i = MAX - 1; i >= p->topo2; i--) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}
