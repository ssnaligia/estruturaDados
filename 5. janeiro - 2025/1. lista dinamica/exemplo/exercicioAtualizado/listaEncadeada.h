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
int insereInicio(Lista* inicio, elemento aluno);
int insereFinal(Lista* inicio, elemento aluno);
int insereOrdenado(Lista* inicio, elemento aluno);

void imprimeLista(Lista* inicio);
int quantidadeElemento(Lista* inicio);

int removeInicio(Lista* inicio);
int removeFinal(Lista* inicio);
int removeMatricula(Lista* inicio, elemento aluno);
void apagaLista(Lista* inicio);

int consultaMatricula(Lista* inicio, int mat, elemento *aluno);
int consultaPosicao(Lista* inicio, int pos, elemento *aluno);

