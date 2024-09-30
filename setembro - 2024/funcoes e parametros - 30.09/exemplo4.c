#include <stdio.h>
#include <locale.h>

int main() {
    int x;
    int *p, *q;
    int **r; // é um ponteiro que aponta para outro ponteiro
    printf("Digite o valor de X: ");
    scanf("%d", &x);

    p = &x; //p aponta para o endereço de x
    q = p; //q recebe o mesmo valor de p (neste caso o endereço de x)
    r = &p; //r aponta para o endereço de p

    printf("Valor de X: %d", x);
    printf("\nEndereço de X - Guardado em P: %x | Guardado em Q: %x", p, q);
    printf("\nEndereço de P: %x | Endereço de Q: %x", &p, &q);
    printf("\nEndereço de P - Guardado em R: %x\n\n", r);

    return 0;
}