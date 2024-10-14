/*Escreva uma função que dobre o valor de uma variável*/

#include <stdio.h>
#include <locale.h>

void dobra(int *p);

int main() {
    int x;
    int *p;

    printf("Digite o valor de X: ");
    scanf("%d", &x);

    dobra(&x);

    printf("Dobro de X: %d\n", x);

    return 0;
}

void dobra(int *p) {
    int q = *p
    *p = q*2;
}
