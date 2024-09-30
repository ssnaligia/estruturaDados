#include <stdio.h>

int main(void) {
	int *ptr;
	int valor = 10;

	ptr = &valor;

	printf("\n Endereco valor= %d", &valor);
	printf("\n Endereco ptr = %d", ptr);
	printf("\n Valor = %d", *ptr);
    printf("\n Valor = %d", valor);
    
    *ptr = 20;

	printf("\n Endereco valor= %d", &valor);
	printf("\n Endereco ptr = %d", ptr);
	printf("\n Valor = %d", *ptr);
    printf("\n Valor = %d", valor);

	return 0;
}