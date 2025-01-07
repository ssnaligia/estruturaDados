#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

Lista* criaLista(){
    Lista* list = (Lista*) malloc(sizeof(Lista));
						//reserva espaço para o primeiro nó da lista
						// list == ponteiro para estrutura com 2 campos (Lista)
    if(list != NULL)//criou corretamente
        *list = NULL; //ponteiro list está vazio - aponta para NULL
    return list;
}

int tamLista(Lista* inicio){
    if(inicio == NULL)
        return 0;
    int cont = 0;
    noLista* no = *inicio;  //cria no aux (no),
							//que apontará, inicialmente,
							//para onde inicio aponta
    						//na sequencia, correrá por
							//todos os elementos do encadeamento (prox)
							//até encontrar NULL.
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int listaVazia(Lista* inicio){
    if(inicio == NULL)//verifica se a cabeça existe (lista válida)
        return 1;
    if(*inicio == NULL)//verifica se o conteudo dela (p/ quem aponta) é NULL
        return 1;
    return 0;
}

int insereInicio(Lista* inicio, elemento aluno){
    if(inicio == NULL)  
        return 0;

    noLista *no; 
    no = (noLista*) malloc(sizeof(noLista));  
    if(no == NULL)  
        return 0;

    no->dado = aluno; 
    no->prox = *inicio;  

    *inicio = no;  

    return 1;  
}

int insereFinal(Lista* inicio, elemento aluno){
    if(inicio == NULL)
        return 0;
    noLista *no; //define ponteiro no do tipo noLista
    no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;
    no->prox = NULL;
    if((*inicio) == NULL){//lista vazia: insere inicio
        *inicio = no;
    }else{
        noLista *aux;
        aux = *inicio;
        while(aux->prox != NULL){
            aux = aux->prox; //
        }
        aux->prox = no;
    }
    return 1;
}

int consultaPosicao(Lista* inicio, int pos, elemento *aluno){
    if(inicio == NULL || pos <= 0)
        return 0;
    noLista *no = *inicio;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *aluno = no->dado;
        return 1;
    }
}

int consultaMatricula(Lista* inicio, int mat, elemento *aluno){
    if(inicio == NULL)
        return 0;
    noLista *no = *inicio;
    while(no != NULL && no->dado.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *aluno = no->dado;
        return 1;
    }
}

int removeInicio(Lista* inicio){
    if(inicio == NULL)
        return 0;
    if((*inicio) == NULL)//lista vazia
        return 0;

    noLista *no = *inicio;
    *inicio = no->prox;
    free(no);
    return 1;
}

int removeFinal(Lista* inicio) {
    if (inicio == NULL || *inicio == NULL)
        return 0;

    noLista *no = *inicio;

    if (no->prox == NULL) { //se o primeiro nó for o ultimo..
        free(no); //libera o único nó
        *inicio = NULL; //e deixa a lista vazia
        return 1;
    }

    while (no->prox != NULL && no->prox->prox != NULL) {
        no = no->prox; //penultimo estará no penúltimo nó e o último nó será removido
    }

    free(no->prox);
    no->prox = NULL;

    return 1;
}

void imprimeLista(Lista* inicio){
    if(inicio == NULL)
        return;
    noLista* no = *inicio;
    while(no != NULL){
        printf("\tMatricula: %d\n",no->dado.matricula);
        printf("\tNome: %s\n",no->dado.nome);
        printf("\tNotas: N1 = %4.2f; N2 = %4.2f N3 = %4.2f\n",
								no->dado.n1,
                                no->dado.n2,
                                no->dado.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

void apagaLista(Lista* inicio){
    if(inicio != NULL){
        noLista* no;
        while((*inicio) != NULL){ 		 //retira cada nó até encontrar fim da lista (NULL)
            no = *inicio; 				//no aux recebe o início da lista ("1o..." elemento)
            *inicio = (*inicio)->prox; //inicio da lista passa a apontar p/ "2o..." elemento
            free(no); 				  //libero memória do "1o..." elemento da lista
        }
        free(inicio); //libero cabeça da lista
    }
}
