#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "converter_nome.h"

int main() {
	char nome[100];

	printf("Digite um nome: ");
	if (fgets(nome, sizeof(nome), stdin) == NULL){
		fprintf(stderr, "Erro ao ler o nome.\n");
		return 1;
	}

	size_t len = strlen(nome);
	if (nome[len - 1] == '\n') {
		nome[len - 1] = '\0';
	}
	
	char *nome_binario = nome_para_binario(nome);
	char *nome_hexadecimal = nome_para_hexadecimal(nome);

	if (!nome_binario || !nome_hexadecimal) {
		fprintf(stderr, "Erro ao converter o nome. \n");
		free(nome_binario);
		free(nome_hexadecimal);
		return 1;
	}

	printf("O nome \"%s\" em binário fica: \n%s\n", nome, nome_binario);
	printf("O nome \"%s\" em hexadecimal fica: \n%s\n", nome, nome_hexadecimal);

	free(nome_binario);
	free(nome_hexadecimal);

	return 0;
}
