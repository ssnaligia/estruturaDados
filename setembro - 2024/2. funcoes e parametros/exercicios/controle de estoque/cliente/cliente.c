#include "cliente.h"
#define MAX_CLIENTES 8

typedef struct {
    char nome[50];
    char cpf[12]; 
    char endereco[100];
    char telefone[15];
    char dataNascimento[11];
} Cliente;

Cliente clientes[MAX_CLIENTES];
int numClientes = 0;

void cadastroCliente() {
    if (numClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    Cliente novoCliente;
    printf("Digite o nome: ");
    scanf(" %[^\n]", novoCliente.nome);
    printf("Digite o CPF: ");
    scanf("%s", novoCliente.cpf);
    
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, novoCliente.cpf) == 0) {
            printf("Cliente já cadastrado com esse CPF.\n");
            return;
        }
    }

    printf("Digite o endereço: ");
    scanf(" %[^\n]", novoCliente.endereco);
    printf("Digite o telefone: ");
    scanf("%s", novoCliente.telefone);
    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    scanf("%s", novoCliente.dataNascimento);

    clientes[numClientes++] = novoCliente;

    printf("Cliente cadastrado com sucesso!\n");
}