#include "unity.h"
#include "architecture.h"

void setUp(void) {}

void tearDown(void) {}

void test_cpu_address_instruction(void)
{
	memory_t ram;
	registers_t regs;

	initialize_memory(&ram, 100);
	initialize_registers(&regs);

	TEST_ASSERT_EQUAL_INT(0, get_register_A(&regs));
	cpu(0b1, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(1, get_register_A(&regs));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_mnem0_dest001(void)
{
	memory_t ram;
	registers_t regs;

	initialize_memory(&ram, 128);
	initialize_registers(&regs);

	TEST_ASSERT_EQUAL_INT(0, 1);

	destroy_memory(&ram);
	destroy_registers(&regs);
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_cpu_address_instruction);
	RUN_TEST(test_cpu_mnem0_dest001);

	return UNITY_END();
}
