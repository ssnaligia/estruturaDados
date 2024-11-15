#ifndef REMOVER_H
#define REMOVER_H

#define MAX 100 

typedef struct {
    int valor;
} No;

int removerDuplicados(No lista[], int n);
void imprimirLista(No lista[], int n);

#endif 