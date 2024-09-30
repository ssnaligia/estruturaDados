#include <stdio.h>
#include <locale.h>

int main(void) {
	int *ptr;
	int valor = 10;

	ptr = &valor; //& para trazer o endereço da variável

	printf("\n Endereço valor: %x", &valor);
	printf("\n Endereço ponteiro: %x", ptr);
	printf("\n Valor: %d", *ptr);
    printf("\n Valor: %d", valor);
    
    *ptr = 20;

	printf("\n Endereço valor: %x", &valor);
	printf("\n Endereço ponteiro: %x", ptr);
	printf("\n Valor: %d", *ptr);
    printf("\n Valor: %d \n", valor);

	return 0;
}