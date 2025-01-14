#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.c"

#define qtde 3

int main(){
    struct elemento vetAlunos[qtde] = {
						{3,"Lucas",8.2,7.5,7.8},
                        {4,"Beatriz",6.5,8.3,8.8},
                        {1,"Mariana",9.1,7.8,7.5}
	};

    Lista *inicio = criaLista();

    int i;

    printf(" --> Tamanho atual da lista: %d\n", tamLista(inicio));

    for(i=0; i < qtde; i++){
    	printf("\n.....Inserindo elemento na posicao: %d", i+1);
        insereFinal(inicio, vetAlunos[i]);
	}
    imprimeLista(inicio);
    printf("\n --> Tamanho atual da lista: %d \n",tamLista(inicio));

	for(i=0; i < qtde; i++){
    	printf("\n.....Removendo elemento da posicao: 1");
        removeInicio(inicio);
    }
    imprimeLista(inicio);
    printf("\n --> Tamanho atual da lista: %d\n\n\n",tamLista(inicio));

    apagaLista(inicio);
    return 0;
}
