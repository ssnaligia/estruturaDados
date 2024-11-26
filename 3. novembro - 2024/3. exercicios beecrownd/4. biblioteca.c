#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, posicao;
    scanf("%d %d", &N, &posicao);
    
    char *alunos[N];  
    
    for (int i = 0; i < N; i++) {
        alunos[i] = (char *)malloc(21 * sizeof(char));  
        scanf("%s", alunos[i]);
    }
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (strcmp(alunos[j], alunos[j + 1]) > 0) {
                char *temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
    
    printf("%s\n", alunos[posicao - 1]);  
    
    for (int i = 0; i < N; i++) {
        free(alunos[i]);
    }

    return 0;
}
