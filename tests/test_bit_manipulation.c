#include "unity.h"
#include "bit_manipulation.h"

void setUp(void) {}

void tearDown(void) {}

void test_repeat_lsb(void)
{
	TEST_ASSERT_EQUAL_INT(0, repeat_lsb(0));
	TEST_ASSERT_EQUAL_INT(0b1111111111111111, repeat_lsb(0b1));
}

void test_comparater(void)
{
	TEST_ASSERT_EQUAL_INT(0, comparater(0, 1));
	TEST_ASSERT_EQUAL_INT(0b1, comparater(0, 0));
	TEST_ASSERT_EQUAL_INT(0b1, comparater(0b1101, 0b1101));
	TEST_ASSERT_EQUAL_INT(0b0, comparater(0b0101, 0b1101));
}

int main(void) 
{
	UNITY_BEGIN();
	
	RUN_TEST(test_repeat_lsb);
	RUN_TEST(test_comparater);

	return UNITY_END();
}
