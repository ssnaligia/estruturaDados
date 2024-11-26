#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    char *livros[1000];
    
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            livros[i] = (char *)malloc(5 * sizeof(char));
            scanf("%s", livros[i]);
        }
        
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - i - 1; j++) {
                if (strcmp(livros[j], livros[j + 1]) > 0) {
                    char *temp = livros[j];
                    livros[j] = livros[j + 1];
                    livros[j + 1] = temp;
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            printf("%s\n", livros[i]);
            free(livros[i]);
        }
    }

    return 0;
}
