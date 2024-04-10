#include "unity.h"
#include "arithmetic.h"

void setUp(void) {}

void tearDown(void) {}

void test_half_adder_sum(void)
{
	uint16_t a = 0b0;
	uint16_t b = 0b0;

	TEST_ASSERT_EQUAL_INT(0, half_adder_sum(a, b));
}

int main(void)
{
	UNITY_BEGIN();
	
	RUN_TEST(test_half_adder_sum);

	return UNITY_END();
}
