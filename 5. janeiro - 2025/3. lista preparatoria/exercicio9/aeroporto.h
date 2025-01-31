#ifndef AEROPORTO_H
#define AEROPORTO_H

typedef struct Aviao {
    char id[10];        
    int combustivel;    
    struct Aviao* proximo;
} Aviao;

typedef struct {
    Aviao* inicio;
} FilaPrioridade;

FilaPrioridade* criarFila();
void inserirAviao(FilaPrioridade* fila, char* id, int combustivel);
void pousarAviao(FilaPrioridade* fila);
void listarFila(FilaPrioridade* fila);
void liberarFila(FilaPrioridade* fila);

#endif 
