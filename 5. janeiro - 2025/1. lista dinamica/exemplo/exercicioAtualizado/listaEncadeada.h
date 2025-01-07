#ifndef LISTAENCADEADA_H_INCLUDED
   #define LISTAENCADEADA_H_INCLUDED
#endif 

typedef struct {    
    int matricula;
    char nome[40];
    float n1, n2, n3;
} elemento;

struct tipoNo{
    elemento dado;
    struct tipoNo *prox;
};

typedef struct tipoNo noLista;

typedef struct tipoNo *Lista; //defino tipo
							 //Lista == ponteiro para
							 //estrutura com dois campos

Lista* criaLista();
int tamLista(Lista* inicio);
int listaVazia(Lista* inicio);
int insereFinal(Lista* inicio, elemento aluno);

void imprimeLista(Lista* inicio);

int removeInicio(Lista* inicio);
void apagaLista(Lista* inicio);

int consultaMatricula(Lista* inicio, int mat, elemento *aluno);
int consultaPosicao(Lista* inicio, int pos, elemento *aluno);

