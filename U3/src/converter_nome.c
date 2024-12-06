#include "converter_nome.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* nome_para_hexadecimal(const char* nome){
	size_t len = strlen(nome);
	char* resultado = (char*)malloc(len * 3);
	if (!resultado) return NULL;

	for (size_t i = 0; i < len; i++){
		sprintf(resultado + i * 3, "%02X ", (unsigned char)nome[i]);
	}
	resultado[len * 3 - 1] = '\0';
	return resultado;
}

char* nome_para_binario(const char* nome){
	(void)nome;
	return "ok";
}
