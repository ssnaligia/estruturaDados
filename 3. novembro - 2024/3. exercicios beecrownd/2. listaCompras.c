#include <stdio.h>
#include <string.h>

#define MAX_ITENS 1000
#define MAX_TAMANHO_ITEM 21

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    for (int t = 0; t < N; t++) {
        char itens[MAX_ITENS][MAX_TAMANHO_ITEM];
        int numItens = 0;
        char temp[MAX_TAMANHO_ITEM];

        while (1) {
            if (scanf("%20s", temp) != 1) {
                break;
            }
            int existe = 0;
            for (int i = 0; i < numItens; i++) {
                if (strcmp(itens[i], temp) == 0) {
                    existe = 1;
                    break;
                }
            }
            if (!existe) {
                strcpy(itens[numItens], temp);
                numItens++;
            }
            if (getchar() == '\n') {
                break;
            }
        }

        for (int i = 0; i < numItens - 1; i++) {
            for (int j = 0; j < numItens - 1 - i; j++) {
                if (strcmp(itens[j], itens[j + 1]) > 0) {
                    char temp[21];
                    strcpy(temp, itens[j]);
                    strcpy(itens[j], itens[j + 1]);
                    strcpy(itens[j + 1], temp);
                }
            }
        }

        for (int i = 0; i < numItens; i++) {
            if (i > 0) printf(" ");
            printf("%s", itens[i]);
        }
        printf("\n");
    }

    return 0;
}
