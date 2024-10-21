#include "utilitario.h"

void load_file_classified(int array[], int size){
    srand( (unsigned) time(NULL) ); 

    array[0] = rand() % MAX_VALUE;

    for(int i = 1; i < size; i++){
        int incremento = rand() % 1000;  

        if (array[i-1] + incremento >= MAX_VALUE) {
            array[i] = MAX_VALUE;  
        } else {
            array[i] = array[i-1] + incremento;
        }
    }
}

void print_file(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);  
    }
    printf("\n\n");
}
