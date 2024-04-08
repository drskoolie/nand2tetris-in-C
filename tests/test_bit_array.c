#include "unity.h"
#include "bit_array.h"
#include "gates.h"

void setUp(void) {}

void tearDown(void) {}

void test_bit_array_to_int(void)
{
	TEST_ASSERT_EQUAL_INT(1, 1);
}

int main(void) {
	UNITY_BEGIN();
	
	RUN_TEST(test_bit_array_to_int);

	return UNITY_END();
}
