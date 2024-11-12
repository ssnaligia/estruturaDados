#ifndef LISTASEQUENCIAL_H_INCLUDED
#define LISTASEQUENCIAL_H_INCLUDED
#endif 
#define MAX 5

struct aluno{
    int matricula;
    char nome[40];
    float n1, n2, n3;
}; 

typedef struct lista Lista;

Lista* criaLista();

int insereFinal(Lista* list, struct aluno al);

int insereInicio(Lista* list, struct aluno al);

int insereOrdenada(Lista* list, struct aluno al);

int removeMatricula(Lista* list, int mat);

int removeInicio(Lista* list);

int removeFinal(Lista* list);

int consultaPosicao(Lista* list, int pos, struct aluno *estudante);

int consultaMatricula(Lista* list, int nroMat, struct aluno *estudante);

int tamLista(Lista* list);

int listaCheia(Lista* list);

int listaVazia(Lista* list);

void imprimeLista(Lista* list);

void apagaLista(Lista* list);



