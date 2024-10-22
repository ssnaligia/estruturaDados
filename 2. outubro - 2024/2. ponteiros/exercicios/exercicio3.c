/* Implementa a função length_string(), conforme programa apresentado abaixo. A função calcula o tamanho
de uma string.

Fix1_Exerc2.c
#include <stdio.h>
void length_string(char*, int*);
int main(int argc, char const *argv[]) {
 char string[] = "Essa é uma string de tamanho 33.";
 int tamanho;
 length_string(string, &tamanho);
 printf("A string \n\t%s\n\tpossui tamanho igual a %d.\n\n", string, tamanho);
 return 0;
}

void length_string(char* str, int* size){
 //TODO: implementar função.
} */