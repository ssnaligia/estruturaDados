#ifndef LISTA_H
#define LISTA_H

#define MAX 100

typedef struct {
    int elementos[MAX];
    int tamanho;
} Lista;

void inicializarLista(Lista *lista);
int inserirElemento(Lista *lista, int valor);
int verificarOrdenacao(Lista *lista);

#endif 