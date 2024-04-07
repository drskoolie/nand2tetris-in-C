#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void test_nand_gate(void) {
	TEST_ASSERT_EQUAL_INT(1, 2);
}

int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_nand_gate);

	return UNITY_END();
}
