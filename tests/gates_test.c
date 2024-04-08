#include "unity.h"

#include <stdbool.h>

#include "gates.h"

void setUp(void) {}

void tearDown(void) {}

void test_nand_gate(void) {
	TEST_ASSERT_TRUE(nand_gate(false, false));
	TEST_ASSERT_TRUE(nand_gate(false, true));
	TEST_ASSERT_TRUE(nand_gate(true, false));
	TEST_ASSERT_FALSE(nand_gate(true, true));
}

void test_and_gate(void) {
	TEST_ASSERT_FALSE(and_gate(false, false));
	TEST_ASSERT_FALSE(and_gate(false, true));
	TEST_ASSERT_FALSE(and_gate(true, false));
	TEST_ASSERT_TRUE(and_gate(true, true));
}

void test_or_gate(void) {
	TEST_ASSERT_FALSE(or_gate(false, false));
	TEST_ASSERT_TRUE(or_gate(false, true));
	TEST_ASSERT_TRUE(or_gate(true, false));
	TEST_ASSERT_TRUE(or_gate(true, true));
}

void test_not_gate(void) {
	TEST_ASSERT_TRUE(not_gate(false));
	TEST_ASSERT_FALSE(not_gate(true));
}

void test_xor_gate(void) {
	TEST_ASSERT_FALSE(xor_gate(false, false));
	TEST_ASSERT_TRUE(xor_gate(true, false));
	TEST_ASSERT_TRUE(xor_gate(false, true));
	TEST_ASSERT_FALSE(xor_gate(true, true));
}

void test_nor_gate(void) {
	TEST_ASSERT_TRUE(nor_gate(false, false));
	TEST_ASSERT_FALSE(nor_gate(true, false));
	TEST_ASSERT_FALSE(nor_gate(false, true));
	TEST_ASSERT_FALSE(nor_gate(true, true));
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
