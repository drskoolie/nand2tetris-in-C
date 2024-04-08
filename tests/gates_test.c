#include "unity.h"

#include "gates.h"

void setUp(void) {}

void tearDown(void) {}

void test_nand_n()
{
	TEST_ASSERT_EQUAL_INT(1, 1);
}



int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_nand_n);

	return UNITY_END();
}
