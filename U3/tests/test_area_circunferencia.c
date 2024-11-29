#include "unity/unity.h"
#include "area_circunferencia.h"

void setUp() {}
void tearDown() {}

void test_area_valida() {
	TEST_ASSERT_DOUBLE_WITHIN(0.01, 12.57, calcular_area_circunferencia(2.0));
}

void test_raio_zero() {
	TEST_ASSERT_DOUBLE_WITHIN(0.0, calcular_area_circunferencia(0.0));
}

void test_raio_negativo() {
	TEST_ASSERT_DOUBLE_WITHIN(-1.0, calcular_area_circunferencia(-3.0));
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_area_valida);
	RUN_TEST(test_raio_zero);
	RUN_TEST(test_raio_negativo);
	return UNITY_END();
}
