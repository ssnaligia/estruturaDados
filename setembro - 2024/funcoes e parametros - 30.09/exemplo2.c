#include <stdio.h>
#include <locale.h>

int main() {
    int x = 0;
    int *ponteiro;

    printf("Digite o valor de X: ");
    scanf("%d", &x);

    ponteiro = &x;

    printf("Valor de X: %d | Endereço de X: %x\n", x, ponteiro);
    printf("Valor de X: %d | Endereço de X: %x\n", x, &x);

    return 0;
}