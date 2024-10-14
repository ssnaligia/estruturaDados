/*Escreva uma função para trocar os valores de duas 
variáveis do tipo inteiro*/

#include <stdio.h>
#include <locale.h>

void troca(int *p, int *q);

int main() {
    int x, y;
    int *p, *q;

    printf("Digite o valor de X: ");
    scanf("%d", &x);

    printf("\nDigite o valor de Y: ");
    scanf("%d", &y);

    troca(&x, &y); //passando os endereços das variáveis x e y usando o operador &, isso permite que a função altere os valores originais de x e y

    printf("\n\nValor de X: %d", x);
    printf("\nValor de Y: %d\n", y); 

    return 0;
}

void troca(int *p, int *q) {
    int r = *p; //armazena o valor que "p" aponta (o valor original de x) em uma variável temporária "r"
    *p = *q; //troca o valor que "p" aponta (originalmente x) pelo valor que "q" aponta (originalmente y)
    *q = r; //coloca o valor armazenado em "r" (o antigo valor de x) em "y"
}