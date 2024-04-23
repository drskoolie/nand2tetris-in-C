#include "unity.h"
#include "binary.h"
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
	int16_t instruction_bits;

	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b001, 0b0);

	initialize_memory(&ram, 128);
	initialize_registers(&regs);

	cpu(instruction_bits, 0, &ram, &regs);

	TEST_ASSERT_EQUAL_INT(1, get_memory(&ram, 0));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_mnem0_dest010(void)
{
	memory_t ram;
	registers_t regs;
	int16_t instruction_bits;

	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b010, 0b0);

	initialize_memory(&ram, 128);
	initialize_registers(&regs);

	cpu(instruction_bits, 0, &ram, &regs);

	TEST_ASSERT_EQUAL_INT(1, get_register_D(&regs));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_cpu_address_instruction);
	RUN_TEST(test_cpu_mnem0_dest001);
	RUN_TEST(test_cpu_mnem0_dest010);

	return UNITY_END();
}
