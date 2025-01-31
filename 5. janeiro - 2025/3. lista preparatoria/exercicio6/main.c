/*Crie um TAD que represente os números racionais e que contenha as seguintes funções:
(a) Cria racional; 
(b) Soma racionais; 
(c) Multiplica racionais;
(d) Testa se são iguais*/

#include <stdio.h>
#include <locale.h>
#include "racional.h"

int main() {
    Racional r1 = criarRacional(4, 8);
    Racional r2 = criarRacional(3, 5);

    printf("Racional 1: ");
    imprimirRacional(r1);
    printf("Racional 2: ");
    imprimirRacional(r2);

    Racional soma = somaRacional(r1, r2);
    printf("Soma: ");
    imprimirRacional(soma);

    Racional produto = multiplicaRacional(r1, r2);
    printf("Multiplicação: ");
    imprimirRacional(produto);

    Racional r3 = criarRacional(1, 2);
    if (saoIguais(r1, r3)) {
        printf("Os racionais são iguais.\n");
    } else {
        printf("Os racionais são diferentes.\n");
    }

    return 0;
}
