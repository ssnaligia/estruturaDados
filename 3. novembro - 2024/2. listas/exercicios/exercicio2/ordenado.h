#ifndef ORDENADO_H
#define ORDENADO_H
#define MAX 10  

typedef struct {
    int valor;
} No;

void ordenarLista(No A[], No B[], int n);
void imprimirLista(No lista[], int n);

#endif
