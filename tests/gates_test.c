#include "unity.h"

#include <stdbool.h>

#include "gates.h"

void setUp(void) {}

void tearDown(void) {}

void test_nand_gate(void) {
	TEST_ASSERT_EQUAL_INT(1, nand_gate(0, 0));
	TEST_ASSERT_EQUAL_INT(1, nand_gate(0, 1));
	TEST_ASSERT_EQUAL_INT(1, nand_gate(1, 0));
	TEST_ASSERT_EQUAL_INT(0, nand_gate(1, 1));
}

void test_and_gate(void) {
	TEST_ASSERT_EQUAL_INT(0, and_gate(0, 0));
	TEST_ASSERT_EQUAL_INT(0, and_gate(0, 1));
	TEST_ASSERT_EQUAL_INT(0, and_gate(1, 0));
	TEST_ASSERT_EQUAL_INT(1, and_gate(1, 1));
}

void test_or_gate(void) {
	TEST_ASSERT_EQUAL_INT(0, or_gate(0, 0));
	TEST_ASSERT_EQUAL_INT(0, or_gate(0, 1));
	TEST_ASSERT_EQUAL_INT(0, or_gate(1, 0));
	TEST_ASSERT_EQUAL_INT(0, or_gate(1, 1));
}

void test_not_gate(void) {
	TEST_ASSERT_EQUAL_INT(0, not_gate(0));
	TEST_ASSERT_EQUAL_INT(0, not_gate(1));
}

void test_xor_gate(void) {
	TEST_ASSERT_EQUAL_INT(0, xor_gate(0, 0));
	TEST_ASSERT_EQUAL_INT(0, xor_gate(0, 1));
	TEST_ASSERT_EQUAL_INT(0, xor_gate(1, 0));
	TEST_ASSERT_EQUAL_INT(0, xor_gate(1, 1));
}

void test_nor_gate(void) {
	TEST_ASSERT_EQUAL_INT(0, nor_gate(0, 0));
	TEST_ASSERT_EQUAL_INT(0, nor_gate(0, 1));
	TEST_ASSERT_EQUAL_INT(0, nor_gate(1, 0));
	TEST_ASSERT_EQUAL_INT(0, nor_gate(1, 1));
}

int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_nand_gate);
	RUN_TEST(test_and_gate);
	RUN_TEST(test_or_gate);
	RUN_TEST(test_not_gate);
	RUN_TEST(test_xor_gate);
	RUN_TEST(test_nor_gate);

	return UNITY_END();
}
