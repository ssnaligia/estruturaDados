#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> 
#include "funcionario.h" 

struct lista{ 
    int prox;
    struct Funcionario func[MAX];
};

Lista* criaLista(){
    Lista *list; 
    list = (Lista*) malloc(sizeof(struct lista)); 
    if(list != NULL)
        list->prox = 0; 
    return list;
}

int insereFuncionario(Lista* list, struct Funcionario funcionario){
    if(list == NULL || list->prox == MAX)
        return 0;
    list->func[list->prox] = funcionario;
    list->prox++;
    return 1;
}

int tamLista(Lista* list){
    if(list == NULL)
        return -1;
    else
        return list->prox; 
}

int listaCheia(Lista* list){
    if(list == NULL)
        return -1;
    return (list->prox == MAX); 
}

int listaVazia(Lista* list){
    if(list == NULL)
        return -1;
    return (list->prox == 0);
}

int consultaCPF(Lista* list, char* numeroCPF, struct Funcionario *funcio) {
    if(list == NULL)
        return 0;
    int i = 0;
    while (i < list->prox && strcmp(list->func[i].cpf, numeroCPF) != 0)
        i++;
    if(i == list->prox)
        return 0;

    *funcio = list->func[i];
    return 1;
}

void imprimeLista(Lista* list){
    if(list == NULL)
        return;
    int i;
    printf("\n\n DADOS DOS FUNCIONÁRIOS\n");
	printf("\n-------------------------------\n\n");
    for(i=0; i< list->prox; i++){
		printf("\nCPF: %s\n",list->func[i].cpf);
        printf("\nNome: %s\n",list->func[i].nome);
        printf("\nVeículo: %s\n",list->func[i].veiculo);																		
        printf("\n-------------------------------");
    }
}

void apagaLista(Lista* list){
    free(list);
}
