#include <stdio.h>
#include <ctype.h>

#define MAX_PALAVRAS 5000
#define TAMANHO_MAX_PALAVRA 201

int letra(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char minuscula(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int compararPalavras(char *a, char *b) {
    while (*a && *b) {
        if (*a != *b) {
            return *a - *b;
        }
        a++;
        b++;
    }
    return *a - *b;
}

int unicaPalavra(char dicionario[][TAMANHO_MAX_PALAVRA], int qtd, char *palavra) {
    for (int i = 0; i < qtd; i++) {
        int comparacao = compararPalavras(dicionario[i], palavra);
        if (comparacao == 0) {
            return 0; 
        }
    }
    return 1;
}

void ordenasPalavras(char dicionario[][TAMANHO_MAX_PALAVRA], int qtd) {
    char temp[TAMANHO_MAX_PALAVRA];
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = i + 1; j < qtd; j++) {
            if (compararPalavras(dicionario[i], dicionario[j]) > 0) {
                int k = 0;
                while (dicionario[i][k] || dicionario[j][k]) {
                    temp[k] = dicionario[i][k];
                    dicionario[i][k] = dicionario[j][k];
                    dicionario[j][k] = temp[k];
                    k++;
                }
            }
        }
    }
}

int main() {
    char linha[201];
    char palavra[TAMANHO_MAX_PALAVRA];
    char dicionario[MAX_PALAVRAS][TAMANHO_MAX_PALAVRA];
    int qtd_palavras = 0;

    while (fgets(linha, sizeof(linha), stdin)) {
        int i = 0, posicao_palavra = 0;

        while (linha[i] != '\0') {
            if (letra(linha[i])) {
                palavra[posicao_palavra++] = minuscula(linha[i]);
            } else {
                if (posicao_palavra > 0) {
                    palavra[posicao_palavra] = '\0';
                    if (unicaPalavra(dicionario, qtd_palavras, palavra)) {
                        int j = 0;
                        while (palavra[j]) {
                            dicionario[qtd_palavras][j] = palavra[j];
                            j++;
                        }
                        dicionario[qtd_palavras][j] = '\0';
                        qtd_palavras++;
                    }
                    posicao_palavra = 0; 
                }
            }
            i++;
        }
        if (posicao_palavra > 0) {
            palavra[posicao_palavra] = '\0';
            if (unicaPalavra(dicionario, qtd_palavras, palavra)) {
                int j = 0;
                while (palavra[j]) {
                    dicionario[qtd_palavras][j] = palavra[j];
                    j++;
                }
                dicionario[qtd_palavras][j] = '\0';
                qtd_palavras++;
            }
        }
    }

    ordenasPalavras(dicionario, qtd_palavras);

    for (int i = 0; i < qtd_palavras; i++) {
        printf("%s\n", dicionario[i]);
    }

    return 0;
}

