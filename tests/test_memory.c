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

	TEST_ASSERT_EQUAL_INT(0, get_register_A(&regs));
	TEST_ASSERT_EQUAL_INT(0, get_register_D(&regs));
	TEST_ASSERT_EQUAL_INT(0, get_register_M(&regs));
	TEST_ASSERT_EQUAL_INT(0, get_register_PC(&regs));

	destroy_registers(&regs);
}

void test_set_register_A()
{
	registers_t regs;

	initialize_registers(&regs);
	set_register_A(&regs, 10);
	TEST_ASSERT_EQUAL_INT(10, get_register_A(&regs));

	destroy_registers(&regs);
}

void test_set_register_D()
{
	registers_t regs;

	initialize_registers(&regs);
	set_register_D(&regs, -100);
	TEST_ASSERT_EQUAL_INT(-100, get_register_D(&regs));

	destroy_registers(&regs);
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_initialize_memory);
	RUN_TEST(test_set_memory);
	RUN_TEST(test_destroy_memory);
	RUN_TEST(test_initialize_registers);
	RUN_TEST(test_set_register_A);
	RUN_TEST(test_set_register_D);

	return UNITY_END();
}
