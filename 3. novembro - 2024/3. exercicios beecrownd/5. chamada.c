#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numero, posicao;
    scanf("%d %d", &numero, &posicao);
    
    char *alunos[numero];  
    
    for (int i = 0; i < numero; i++) {
        alunos[i] = (char *)malloc(21 * sizeof(char));  
        scanf("%s", alunos[i]);
    }
    
    for (int i = 0; i < numero - 1; i++) {
        for (int j = 0; j < numero - i - 1; j++) {
            if (strcmp(alunos[j], alunos[j + 1]) > 0) {
                char *temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
    
    printf("%s\n", alunos[posicao - 1]);  
    
    for (int i = 0; i < numero; i++) {
        free(alunos[i]);
    }

    return 0;
}