#include "unity.h"
#include "architecture.h"

void setUp(void) {}

void tearDown(void) {}

void test_cpu(void)
{
	TEST_ASSERT_EQUAL_INT(0, 0);
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_cpu);

	return UNITY_END();
}
