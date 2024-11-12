#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.c"
#define qtde 5

int main(){
    struct aluno vetAlunos[qtde] = {
						 {3,"Lucas",8.2,7.5,7.8},
                         {4,"Beatriz",6.5,8.3,8.8},
                         {1,"Mariana",9.1,7.8,7.5},
                         {9,"Junior",7.6,8.1,6.4},
                         {7,"Carlos",7.6,8.1,6.4}
	};

    Lista* list = criaLista(); //Lista* list --> ponteiro para a lista

    for(int i=0; i < qtde; i++)
        insereOrdenada(list, vetAlunos[i]);

    imprimeLista(list);

    printf("\n\n");
    struct aluno alunoEncontrado;

	int nroMat;
    printf("Digite o numero de matricula a ser localizado: "); 
    scanf("%d", &nroMat);
    int achou = consultaMatricula(list, nroMat, &alunoEncontrado); //consulta pelo nroMat. Devolve (ref) dados do aluno.
    if (achou == 1){
		printf("\n\n Dados do Aluno");
		printf("\n-------------------------------");
	    printf("\n Matricula: %d",alunoEncontrado.matricula);
	    printf("\n Nome: %s",alunoEncontrado.nome);
	    printf("\n Notas: N1 = %.2f; N2 = %.2f e N3 = %.2f",alunoEncontrado.n1, alunoEncontrado.n2, alunoEncontrado.n3);
	    printf("\n-------------------------------");
    }
    else{
    	printf("\n\n ALUNO NAO ENCONTRADO");
	}

	apagaLista(list);
    return(0);
}


