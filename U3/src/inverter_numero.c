#include "inverter_numero.h"

int inverter_numero(int numero) {
	if (numero < 100 || numero > 999) {
		return -1;
	}

	int centena = numero / 100;
	int dezena = (numero / 10) % 10;
	int unidade = numero % 10;

	return unidade * 100 + dezena * 10 + centena;
}
