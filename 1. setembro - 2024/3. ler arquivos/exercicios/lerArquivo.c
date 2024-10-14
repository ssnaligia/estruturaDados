#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TAM_LINHA 100
#define MAX_ALUNOS 20

typedef struct {
    char nome[80];
    char prontuario[12];
} Aluno;

void removerNovaLinha(char *linha) {
    //essa função tira essa parte extra para que fiquem só as informações que são necessárias
    linha[strcspn(linha, "\n")] = 0; 
}

void lerLinha(char *linha, Aluno *aluno) {
    removerNovaLinha(linha);  

    //separa o primeiro token (nome)
    char *token = strtok(linha, ";");
    if (token != NULL) {
        strcpy(aluno->nome, token);  //copia o nome para a struct
    }

    token = strtok(NULL, ";"); // é usada para dividir uma string em partes menores (tokens) com base em um delimitador, que, neste caso, é o ponto e vírgula

    if (token != NULL) { 
        strcpy(aluno->prontuario, token);  
    }
}

int main() {
    FILE *arquivo;
    char linha[TAM_LINHA];
    Aluno vetorAluno[MAX_ALUNOS];
    int contador = 0, min = 0, max = 20;

    srand(time(NULL));

    int alunoSorteado = rand() % (max - min + 1) + min;

    arquivo = fopen("/home/aluno/Downloads/dados.csv", "r");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo\n");
        return 0;
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (contador < MAX_ALUNOS) {
            lerLinha(linha, &vetorAluno[contador]);  
            contador++;
        } else {
            printf("Número máximo de alunos excedido.\n");
            break;
        }
    }

    fclose(arquivo);

    printf("\n\nAluno Sorteado (%d): \n", alunoSorteado + 1);

    for (int i = 0; i < contador; i++) {
        if(i == alunoSorteado) {
            printf("Nome: %s | Prontuário: %s\n\n", vetorAluno[i].nome, vetorAluno[i].prontuario);
        }
    }

    return 0;
}
