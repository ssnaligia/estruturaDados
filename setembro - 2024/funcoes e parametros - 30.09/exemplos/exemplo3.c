#include <stdio.h>
#include <locale.h>

int main() {
    int x; //valor
    int *p, *q; //etiquetas que referencia o endereço
    printf("Digite o valor de X: ");
    scanf("%d", &x);

    p = &x; //p aponta para o endereço de x;
    q = p; // q aponta para o mesmo endereço de p

    printf("Valor de X: %d", x);
    printf("\nEndereço de X - Guardado em P: %x | Guardado em Q: %x", p, q); //só a variavel ele exibe o valor (neste caso o endereço de x)
    printf("\nEndereço de P: %x | Endereço de Q: %x\n\n", &p, &q); //& antes da variavel exibe o endereço da var

    return 0;
}