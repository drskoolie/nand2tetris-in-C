#include "unity.h"
#include "memory.h"

void setUp(void) {}

void tearDown(void) {}

void test_initialize_memory(void)
{
	memory_t reg;

	initialize_memory(&reg, 1);

	TEST_ASSERT_EQUAL_INT(0, get_memory(&reg, 0));

	destroy_memory(&reg);
}

void test_set_memory(void)
{
	memory_t reg;

	initialize_memory(&reg, 1);
	set_memory(&reg, 0, 10);

	TEST_ASSERT_EQUAL_INT(10, get_memory(&reg, 0));

	destroy_memory(&reg);
}

void test_destroy_memory(void)
{
	memory_t reg;

	initialize_memory(&reg, 1);

	TEST_ASSERT_NOT_NULL(reg.data);
	destroy_memory(&reg);
	TEST_ASSERT_NULL(reg.data);

}

void test_initialize_registers(void)
{
	registers_t regs;

	initialize_registers(&regs);

	TEST_ASSERT_EQUAL_INT(0, get_register_A(&regs));
	TEST_ASSERT_EQUAL_INT(0, get_register_D(&regs));
	TEST_ASSERT_EQUAL_INT(0, get_register_PC(&regs));

	destroy_registers(&regs);
}

void test_set_register_A(void)
{
	registers_t regs;

	initialize_registers(&regs);
	set_register_A(&regs, 10);
	TEST_ASSERT_EQUAL_INT(10, get_register_A(&regs));

	destroy_registers(&regs);
}

void test_set_register_D(void)
{
	registers_t regs;

	initialize_registers(&regs);
	set_register_D(&regs, -100);
	TEST_ASSERT_EQUAL_INT(-100, get_register_D(&regs));

	destroy_registers(&regs);
}

void test_set_register_PC(void)
{
	registers_t regs;

	initialize_registers(&regs);
	set_register_PC(&regs, 55);
	TEST_ASSERT_EQUAL_INT(55, get_register_PC(&regs));

	destroy_registers(&regs);
}

void test_get_register_M(void)
{
	memory_t ram;
	registers_t regs;

	int16_t address = 15;
	int16_t value = 10;
	
	initialize_registers(&regs);
	initialize_memory(&ram, 128);

	set_memory(&ram, address, value);
	set_register_A(&regs, address);
	TEST_ASSERT_EQUAL_INT(value, get_register_M(&regs, &ram));

	destroy_registers(&regs);
	destroy_memory(&ram);
}

void test_set_register_M(void)
{
	memory_t ram;
	registers_t regs;

	int16_t address = 15;
	int16_t value = 10;
	
	initialize_registers(&regs);
	initialize_memory(&ram, 128);

	set_register_A(&regs, address);
	set_register_M(&regs, &ram, value);
	TEST_ASSERT_EQUAL_INT(value, get_memory(&ram, address));

	destroy_registers(&regs);
	destroy_memory(&ram);
}

void test_inc_register_PC(void)
{
	registers_t regs;

	initialize_registers(&regs);

	TEST_ASSERT_EQUAL_INT(0, get_register_PC(&regs));
	inc_register_PC(&regs);
	TEST_ASSERT_EQUAL_INT(1, get_register_PC(&regs));

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
	RUN_TEST(test_set_register_PC);
	RUN_TEST(test_get_register_M);
	RUN_TEST(test_set_register_M);
	RUN_TEST(test_inc_register_PC);

	return UNITY_END();
}
