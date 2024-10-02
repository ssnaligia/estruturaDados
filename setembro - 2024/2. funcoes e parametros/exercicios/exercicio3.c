#include <stdio.h>
#include <locale.h>

int somaArray(int *array, int tam);

int main() {
    int tam;

    do {
        printf("Digite o tamanho do array: ");
        scanf("%d", &tam);
    } while (tam <= 0);
    
    int array[tam]; 

    for (int i = 0; i < tam; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &array[i]); 
    }

    int soma = somaArray(array, tam); 

    printf("\nSoma: %d\n", soma); 

    return 0;
}

int somaArray(int *array, int tam) {
    int soma = 0; 
    for (int i = 0; i < tam; i++) {
        soma += *(array + i); 
    }
    return soma; 
}
