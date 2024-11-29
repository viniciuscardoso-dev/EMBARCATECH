#include "unity/unity.h"
#include "../src/delta.h"

void setUp(void) {
}

void tearDown(void){
}

void test_delta_positivo(void) {
  TEST_ASSERT_EQUAL_DOUBLE(1.0, calcular_delta(1,3,2));
}

void test_delta_zero(void) {
  TEST_ASSERT_EQUAL_DOUBLE(0.0, calcular_delta(1,2,1));
}

void test_delta_negativo(void) {
  TEST_ASSERT_EQUAL_DOUBLE(-3.0, calcular_delta(1,1,1));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_delta_positivo);
  RUN_TEST(test_delta_zero);
  RUN_TEST(test_delta_negativo);
  return UNITY_END();
}
