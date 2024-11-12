#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED
#endif 
#define MAX 50

struct Funcionario {
    char cpf[25];
    char nome[40];
    char veiculo[50];
}; 

typedef struct lista Lista;

Lista* criaLista();

int insereFuncionario(Lista* list, struct Funcionario funcionario);

int  consultaCPF(Lista* list, char* numeroCPF, struct Funcionario *funcio);

int tamLista(Lista* list);

int listaCheia(Lista* list);

int listaVazia(Lista* list);

void imprimeLista(Lista* list);

void apagaLista(Lista* list);



