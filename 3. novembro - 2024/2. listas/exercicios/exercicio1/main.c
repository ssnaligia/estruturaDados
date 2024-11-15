#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> 
#include "funcionario.h"
#define qtde 50

int main(){
    struct Funcionario vetFuncionario[qtde] = {
						 {"123", "Lucas", "Carro"},
                         {"456", "Beatriz", "Patinete"},
                         {"789", "Mariana", "Monociclo"},
                         {"963", "Junior", "Bicicleta"},
                         {"741", "Carlos", "Moto"}
	};

    Lista* list = criaLista(); 

    for(int i = 0; i < 5; i++) 
        insereFuncionario(list, vetFuncionario[i]);

    imprimeLista(list);

    printf("\n\n");
    struct Funcionario funcionarioEncontrado;

	char numeroCPF[25];
    printf("Digite o número do CPF a ser localizado: "); 
    scanf("%s", numeroCPF);
    int achou = consultaCPF(list, numeroCPF, &funcionarioEncontrado);
    if (achou == 1){
		printf("\n\n Dados do Funcionário");
		printf("\n-------------------------------");
	    printf("\n CPF: %s",funcionarioEncontrado.cpf);
	    printf("\n Nome: %s",funcionarioEncontrado.nome);
	    printf("\n Veículo: %s",funcionarioEncontrado.veiculo);
	    printf("\n-------------------------------");
    }
    else{
    	printf("\n\n FUNCIONÁRIO NÃO ENCONTRADO!");
	}

	apagaLista(list);
    return(0);
}