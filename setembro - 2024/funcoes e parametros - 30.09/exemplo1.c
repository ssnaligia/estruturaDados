#include <stdio.h>

void exibe(int a);

int main() {
    int a = 10;
    exibe(a);   
    return 0;
}

void exibe(int a) {
    printf("\nA: %d \n", a);
}