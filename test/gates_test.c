#include "unity.h"
#include "../include/gates.h"

void test_nand_gate(void) {
	TEST_ASSERT_EQUAL(1, nand_gate(0, 0));
}

int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_nand_gate);

	return UNITY_END();
}
