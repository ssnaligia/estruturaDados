#include "utilitario.h"
#define SIZE 1000000
#define MAX_VALUE 1000000 

int main(int argc, char const *argv[]){
    int arquivo[SIZE];

    load_file_classified(arquivo, SIZE);  

    print_file(arquivo, SIZE);  

    return 0;
}
