#include "area_circunferencia.h"
#include <math.h>

double calcular_area_circunferencia(double raio) {
	if (raio < 0) {
		return -1;
	}
	return raio * raio * M_PI;
}
