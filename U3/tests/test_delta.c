#include "unity.h"
#include "../src/delta.h"

void setUp(void) {
}

void tearDown(void){
}

void test_delta_positivo(void) {
  double resultado = calcular_delta(1,3,2);
  TEST_ASSERT_EQUAL_DOUBLE(1.0, resultado);
}

void test_delta_zero(void) {
  double resultado = calcular_delta(1,2,1);
  TEST_ASSERT_EQUAL_DOUBLE(0.0, resultado);
}

void test_delta_negativo(void) {
  double resultado = calcular_delta(1,1,1);
  TEST_ASSERT_EQUAL_DOUBLE(-3.0, resultado);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_delta_positivo);
  RUN_TEST(test_delta_zero);
  RUN_TEST(test_delta_negativo);
  return UNITY_END();
}
