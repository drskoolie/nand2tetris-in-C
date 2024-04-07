#include "unity.h"

#include <stdbool.h>
#include "gates.h"

void setUp(void) {}

void tearDown(void) {}

void test_nand_gate(void) {
	TEST_ASSERT_FALSE(nand_gate(false, false));
}

int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_nand_gate);

	return UNITY_END();
}
