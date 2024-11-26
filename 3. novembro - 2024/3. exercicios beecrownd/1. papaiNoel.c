#include <stdio.h>
#include <string.h>

#define MAX_NOME 21  
#define MAX_CRINÇAS 100 

void bubbleSort(char nomes[][MAX_NOME], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                char temp[MAX_NOME];
                strcpy(temp, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], temp);
            }
        }
    }
}

int main() {
    int N;
    char nomes[MAX_CRINÇAS][MAX_NOME]; 
    char comportamentos[MAX_CRINÇAS]; 
    
    int bemComportadas = 0;
    int malComportadas = 0;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf(" %c %s", &comportamentos[i], nomes[i]);
        
        if (comportamentos[i] == '+') {
            bemComportadas++;
        } else if (comportamentos[i] == '-') {
            malComportadas++;
        }
    }
    
    bubbleSort(nomes, N);
    
    for (int i = 0; i < N; i++) {
        printf("%s\n", nomes[i]);
    }
    
    printf("Se comportaram: %d | Nao se comportaram: %d\n", bemComportadas, malComportadas);

    
    return 0;
}

