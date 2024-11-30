#include "unity/unity.h"
#include "inverter_numero.h"

void setUp(void) {}
void tearDown(void) {}

void test_inverter_numero_valido(void) {
	TEST_ASSERT_EQUAL_INT(321, inverter_numero(123));
	TEST_ASSERT_EQUAL_INT(927, inverter_numero(729));
	TEST_ASSERT_EQUAL_INT(200, inverter_numero(002));
}

void test_inverter_numero_fora_do_intervalo(void) {
	TEST_ASSERT_EQUAL_INT(-1, inverter_numero(99));
	TEST_ASSERT_EQUAL_INT(-1, inverter_numero(1000));
	TEST_ASSERT_EQUAL_INT(-1, inverter_numero(-100));
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_inverter_numero_valido);
	RUN_TEST(test_inverter_numero_fora_do_intervalo);
	return UNITY_END();
}
