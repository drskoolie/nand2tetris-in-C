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
	TEST_ASSERT_FALSE(and_gate(false, false));
	TEST_ASSERT_TRUE(and_gate(false, true));
	TEST_ASSERT_TRUE(and_gate(true, false));
	TEST_ASSERT_TRUE(and_gate(true, true));
}

int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_nand_gate);
	RUN_TEST(test_and_gate);

	return UNITY_END();
}
