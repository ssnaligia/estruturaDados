#include <stdio.h>
#include <stdlib.h>

int foo();

int main(int argc, char const *argv[]){
 
 int ptr;
 foo(ptr);
 printf(" %d \n\n", ptr);
}

int* foo(int* p) {
    int *p = malloc(sizeof(int));
    *p = 5;
    return p;
}
