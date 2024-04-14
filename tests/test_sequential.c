#include "unity.h"
#include "sequential.h"

void setUp(void) {}

void tearDown(void) {}

void test_dff(void)
{
	int16_t in = 0b1;
	int16_t clock = 0b0;
	int16_t out = 0b0;

	TEST_ASSERT_EQUAL_INT(0, 0);
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_dff);

	return UNITY_END();
}
