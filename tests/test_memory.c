#include "unity.h"
#include "memory.h"

void setUp(void) {}

void tearDown(void) {}

void test_initialize_memory()
{
	memory reg;

	initialize_memory(&reg, 1);

	TEST_ASSERT_EQUAL_INT(0, 0);
	destroy_memory(&reg);
}

void test_set_memory()
{
	memory reg;

	initialize_memory(&reg, 1);

	TEST_ASSERT_EQUAL_INT(0, 0);
	destroy_memory(&reg);
}

void test_get_memory()
{
	TEST_ASSERT_EQUAL_INT(0, 0);
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_initialize_memory);
	RUN_TEST(test_set_memory);
	RUN_TEST(test_get_memory);

	return UNITY_END();
}
