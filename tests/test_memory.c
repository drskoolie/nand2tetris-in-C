#include "unity.h"
#include "memory.h"

void setUp(void) {}

void tearDown(void) {}

void test_initialize_memory()
{
	memory_t reg;

	initialize_memory(&reg, 1);

	TEST_ASSERT_EQUAL_INT(0, get_memory(&reg, 0));

	destroy_memory(&reg);
}

void test_set_memory()
{
	memory_t reg;

	initialize_memory(&reg, 1);
	set_memory(&reg, 0, 10);

	TEST_ASSERT_EQUAL_INT(10, get_memory(&reg, 0));

	destroy_memory(&reg);
}

void test_destroy_memory()
{
	memory_t reg;

	initialize_memory(&reg, 1);

	TEST_ASSERT_NOT_NULL(reg.data);
	destroy_memory(&reg);
	TEST_ASSERT_NULL(reg.data);

}

void test_initialize_registers()
{
	registers_t regs;

	initialize_registers(&regs);

	TEST_ASSERT_EQUAL_INT(0, regs.A->data);

	destroy_registers(&regs);
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_initialize_memory);
	RUN_TEST(test_set_memory);
	RUN_TEST(test_destroy_memory);
	RUN_TEST(test_initialize_registers);

	return UNITY_END();
}
