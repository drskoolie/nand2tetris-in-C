#include "unity.h"
#include "gates.h"

void setUp(void) {}

void tearDown(void) {}

void test_nand(void)
{
	uint16_t in0 = 0b1010;
	uint16_t in1 = 0b1100;

	uint16_t out = nand(in0, in1);

	TEST_ASSERT_EQUAL_INT(0b1111111111110111, out);
}

void test_and(void)
{
	uint16_t in0 = 0b1010;
	uint16_t in1 = 0b1100;

	uint16_t out = and(in0, in1);

	TEST_ASSERT_EQUAL_INT(0b1000, out);

}


int main(void) {
	UNITY_BEGIN();
	
	RUN_TEST(test_nand);
	RUN_TEST(test_and);

	return UNITY_END();
}
