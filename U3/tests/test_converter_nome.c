#include <string.h>
#include <stdlib.h>
#include "converter_nome.h"
#include "unity/unity.h"

void setUp() {}
void tearDown() {}

void test_nome_para_hexadecimal() {
	char* resultado = nome_para_hexadecimal("abc");
	TEST_ASSERT_NOT_NULL(resultado);
	TEST_ASSERT_EQUAL_STRING("61 62 63", resultado);
	free(resultado);

	resultado = nome_para_hexadecimal("Test");
	TEST_ASSERT_NOT_NULL(resultado);
	TEST_ASSERT_EQUAL_STRING("54 65 73 74", resultado);
	free(resultado);
}

void test_nome_para_binario() {
	char* resultado = nome_para_binario("abc");
	TEST_ASSERT_NOT_NULL(resultado);
	TEST_ASSERT_EQUAL_STRING("01100001 01100010 01100011", resultado);
	free(resultado);

	resultado = nome_para_binario("Test");
	TEST_ASSERT_NOT_NULL(resultado);
	TEST_ASSERT_EQUAL_STRING("01010100 01100101 01110011 01110100", resultado);
	free(resultado);
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_nome_para_hexadecimal);
	RUN_TEST(test_nome_para_binario);
	return UNITY_END();
}
