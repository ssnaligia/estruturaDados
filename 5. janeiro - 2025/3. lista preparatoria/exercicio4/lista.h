#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct Lista {
    No* cabeca;
} Lista;

void inicializarLista(Lista* lista);
void inserirFinal(Lista* lista, int valor);
void imprimirLista(Lista* lista);
void mergeOrdenado(Lista* l1, Lista* l2, Lista* l3);

#endif
