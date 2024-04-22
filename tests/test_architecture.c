#include "unity.h"
#include "von_neumann.h"

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
