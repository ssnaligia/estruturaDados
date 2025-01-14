#ifndef LISTADUPLAMENTEENCADEADA_H_INCLUDED
   #define LISTADUPLAMENTEENCADEADA_H_INCLUDED
#endif // LISTADUPLAMENTEENCADEADA_H_INCLUDED

typedef struct elemento{
    int matricula;
    char nome[40];
    float n1, n2, n3;
};

struct tipoNo{
	struct tipoNo *ant;
    struct elemento dado;
    struct tipoNo *prox;
};

typedef struct tipoNo noLista;

typedef struct tipoNo *Lista;

Lista* criaLista();
void apagaLista(Lista* inicio);
int insereFinal(Lista* inicio, struct elemento aluno);
int insereInicio(Lista* inicio, struct elemento aluno);
int insereOrdenada(Lista* inicio, struct elemento aluno);
int removeMatricula(Lista* inicio, int mat);
int removeInicio(Lista* inicio);
int removeFinal(Lista* inicio);
int tamLista(Lista* inicio);
int listaVazia(Lista* inicio);
int listaCheia(Lista* inicio);
void imprimeLista(Lista* inicio);
int consultaMatricula(Lista* inicio, int mat, struct elemento *aluno);
int consultaPosicao(Lista* inicio, int pos, struct elemento *aluno);
