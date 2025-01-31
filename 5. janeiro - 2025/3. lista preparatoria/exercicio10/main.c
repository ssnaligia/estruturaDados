#include <stdio.h>
#include <locale.h>
#include "pilha.h"

int main() {
    PilhaDupla pilha;
    inicializarPilha(&pilha);

    pushP1(&pilha, 5);
    pushP1(&pilha, 10);
    pushP1(&pilha, 15);
    
    pushP2(&pilha, 20);
    pushP2(&pilha, 25);
    pushP2(&pilha, 30);

    mostrarPilhas(&pilha);

    printf("\nRemovendo de P1: %d\n", popP1(&pilha));
    printf("\nRemovendo de P2: %d\n", popP2(&pilha));

    mostrarPilhas(&pilha);

    return 0;
}
