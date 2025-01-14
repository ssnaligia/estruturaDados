#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"

Lista* criaLista(){//igual LSE
    Lista* list = (Lista*) malloc(sizeof(Lista));
    if(list != NULL)//criou corretamente
        *list = NULL; //ponteiro list est� vazio - aponta para NULL
    return list;
}

int tamLista(Lista* inicio){ //igual LSE
    if(inicio == NULL)
        return 0;
    int cont = 0;
    noLista* no = *inicio;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int listaCheia(Lista* inicio){ //s� acontecer� se n�o houver espa�o na mem�ria
    return 0; //nunca estar� cheia, retornar� sempre ZERO
}

int listaVazia(Lista* inicio){//igual LE
    if(inicio == NULL)//verifica se a cabe�a existe (lista v�lida)
        return 1;
    if(*inicio == NULL)//verifica se o conte�do dela (p/ quem aponta) � NULL
        return 1;
    return 0;
}

int consultaPosicao(Lista* inicio, int pos, struct elemento *aluno){//IGUAL LSE
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

int consultaMatricula(Lista* inicio, int mat, struct elemento *aluno){//IGUAL LSE
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

int insereFinal(Lista* inicio, struct elemento aluno){
    if(inicio == NULL)
        return 0;
    noLista *no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;
    no->prox = NULL;
    if((*inicio) == NULL){//lista vazia: insere in�cio
    	no->ant = NULL;//ATUALIZA ant DO novoNO
        *inicio = no;
    }else{
        noLista *aux = *inicio;
        while(aux->prox != NULL)
            aux = aux->prox;

        aux->prox = no;
        no->ant = aux;//ATUALIZA ant DO novoNO
    }
    return 1;
}

int insereInicio(Lista* inicio, struct elemento aluno){
    if(inicio == NULL)//n�o alocada
        return 0;
    noLista* no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;
    no->prox = (*inicio);
    no->ant = NULL; //--> PRIMEIRO ELEMENTO DA LISTA

	if(*inicio != NULL)		  //LISTA N�O ESTAVA VAZIA -> ant de quem inicio
		(*inicio)->ant = no; //aponta, passa a apontar para o novoNo

    *inicio = no;//atualiza in�cio
    return 1;
}

int insereOrdenada(Lista* inicio, struct elemento aluno){
    if(inicio == NULL)
        return 0;
    noLista *no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;

    if((*inicio) == NULL){//lista vazia: insere in�cio
        no->prox = NULL;
        no->ant = NULL;
        *inicio = no;
        return 1;
    }
    else{ //lista n�o vazia - procura onde inserir
        noLista *anterior, *atual = *inicio;
        while(atual != NULL && atual->dado.matricula < aluno.matricula){
            anterior = atual;
            atual = atual->prox;
        }
        if(atual == *inicio){//n�o entrou no while - insere in�cio
        	no->ant = NULL; //ATUALIZO ant DO novoNo (SER� O 1�)
            (*inicio)->ant = no; //ant DO N� QUE, ANTES ERA O 1�, APONTA PARA O novoNo
			no->prox = (*inicio);//PROX DO novoNo APONTA PARA ONDE O IN�CIO EST� APONTANDO
            *inicio = no;//atualiza in�cio
        }else{ //insere no meio ou fim
            no->prox = anterior->prox;
            no->ant = anterior;
            anterior->prox = no;
            if (atual != NULL)
            	atual->ant = no;
        }
        return 1;
    }
}

int removeMatricula(Lista* inicio, int mat){
    if(inicio == NULL)
        return 0;
    if((*inicio) == NULL)//lista vazia
        return 0;
    noLista *no = *inicio;
    while(no != NULL && no->dado.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)//n�o encontrado
        return 0;

    if(no->ant == NULL)//remover o primeiro?
        *inicio = no->prox;
    else
        no->ant->prox = no->prox;

	if (no->prox != NULL)
		no->prox->ant = no->ant;

    free(no);
    return 1;
}

int removeInicio(Lista* inicio){
    if(inicio == NULL)
        return 0;
    if((*inicio) == NULL)//lista vazia
        return 0;

    noLista *no = *inicio;
    *inicio = no->prox;

	if (no->prox != NULL)//TINHA MAIS DE 1 ELEMENTO NA LISTA
    	no->prox->ant = NULL; //valor do ponteiro "ant" que
							 //� apontado pelo campo "prox"
    						//de quem o "n�" aponta
    free(no);
    return 1;
}

int removeFinal(Lista* inicio){
    if(inicio == NULL)
        return 0;
    if((*inicio) == NULL)//lista vazia
        return 0;

    noLista *no = *inicio;
    while(no->prox != NULL){
        no = no->prox;
    }

    if(no->ant == NULL)//remover o primeiro (e �nico)?
        *inicio = no->prox;
    else
        no->ant->prox = no->prox;
    free(no);
    return 1;
}

void imprimeLista(Lista* inicio){//IGUAL LSE
    printf("\n\n------ DADOS NA LISTA \n");

    noLista* no = *inicio;

    if(no == NULL){
        printf("LISTA VAZIA! \n");
        return;
    }

    while(no != NULL){
        printf("\tMatricula: %d Nome: %s Notas: N1 = %4.2f; N2 = %4.2f N3 = %4.2f \n",no->dado.matricula, no->dado.nome, no->dado.n1,
                                no->dado.n2, no->dado.n3);
        no = no->prox;
    }
    printf("-------------------------------\n");
}

void apagaLista(Lista* inicio){//IGUAL LSE
    if(inicio != NULL){
        noLista* no;
        while((*inicio) != NULL){ 		 //retira cada n� at� encontrar fim da lista (NULL)
            no = *inicio; 				//no aux recebe o in�cio da lista ("1�..." elemento)
            *inicio = (*inicio)->prox; //in�cio da lista passa a apontar p/ "2�..." elemento
            free(no); 				  //libero mem�ria do "1�..." elemento da lista
        }
        free(inicio); //libero cabe�a da lista
    }
}
