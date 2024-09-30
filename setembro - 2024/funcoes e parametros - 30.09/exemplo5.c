#include <stdio.h>
#include <locale.h>

int main() {
    int x;
    int *p, *q;
    int **r;
    printf("Digite o valor de X: ");
    scanf("%d", &x);

    p = &x; //p aponta para o endereço de x
    q = p; //q recebe o mesmo valor de p (neste caso o endereço de x)
    r = &p; //r aponta para o endereço de p

    printf("Valor de X: %d", x);
    printf("\nEndereço de X - Guardado em P: %x | Guardado em Q: %x", p, q);
    *p = 30;
    printf("\nValor de X: %d", x);
    printf("\nValor armazenado na variável apontada por P: %d | Q: %d\n\n", *p, *q);

    return 0;
}