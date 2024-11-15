#ifndef CONJUNTO_H
#define CONJUNTO_H
#define MAX 10  

typedef struct {
    int valor;
} No;

void imprimirLista(No lista[], int n);
int uniao(No A[], int nA, No B[], int nB, No C[]);        
int intersecao(No A[], int nA, No B[], int nB, No C[]);   
int diferenca(No A[], int nA, No B[], int nB, No C[]);

#endif
