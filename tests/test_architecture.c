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

void test_cpu_mnem0_dest000(void)
{
	memory_t ram;
	registers_t regs;
	int16_t instruction_bits;

	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b000, 0b0);

	initialize_memory(&ram, 128);
	initialize_registers(&regs);

	cpu(instruction_bits, 0, &ram, &regs);

	TEST_ASSERT_EQUAL_INT(0, get_register_A(&regs));
	TEST_ASSERT_EQUAL_INT(0, get_register_D(&regs));
	TEST_ASSERT_EQUAL_INT(0, get_memory(&ram, 0));

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

	TEST_ASSERT_EQUAL_INT(0, get_register_A(&regs));
	TEST_ASSERT_EQUAL_INT(0, get_register_D(&regs));
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

	TEST_ASSERT_EQUAL_INT(0, get_register_A(&regs));
	TEST_ASSERT_EQUAL_INT(1, get_register_D(&regs));
	TEST_ASSERT_EQUAL_INT(0, get_memory(&ram, 0));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_mnem0_dest011(void)
{
	memory_t ram;
	registers_t regs;
	int16_t instruction_bits;

	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b011, 0b0);

	initialize_memory(&ram, 128);
	initialize_registers(&regs);

	cpu(instruction_bits, 0, &ram, &regs);

	TEST_ASSERT_EQUAL_INT(0, get_register_A(&regs));
	TEST_ASSERT_EQUAL_INT(1, get_register_D(&regs));
	TEST_ASSERT_EQUAL_INT(1, get_memory(&ram, 0));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_mnem0_dest100(void)
{
	memory_t ram;
	registers_t regs;
	int16_t instruction_bits;

	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b100, 0b0);

	initialize_memory(&ram, 128);
	initialize_registers(&regs);

	cpu(instruction_bits, 0, &ram, &regs);

	TEST_ASSERT_EQUAL_INT(1, get_register_A(&regs));
	TEST_ASSERT_EQUAL_INT(0, get_register_D(&regs));
	TEST_ASSERT_EQUAL_INT(0, get_memory(&ram, 0));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_mnem0_dest101(void)
{
	memory_t ram;
	registers_t regs;
	int16_t instruction_bits;

	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b101, 0b0);

	initialize_memory(&ram, 128);
	initialize_registers(&regs);

	cpu(instruction_bits, 0, &ram, &regs);

	TEST_ASSERT_EQUAL_INT(1, get_register_A(&regs));
	TEST_ASSERT_EQUAL_INT(0, get_register_D(&regs));
	TEST_ASSERT_EQUAL_INT(1, get_memory(&ram, 0));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_mnem0_dest110(void)
{
	memory_t ram;
	registers_t regs;
	int16_t instruction_bits;

	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b110, 0b0);

	initialize_memory(&ram, 128);
	initialize_registers(&regs);

	cpu(instruction_bits, 0, &ram, &regs);

	TEST_ASSERT_EQUAL_INT(1, get_register_A(&regs));
	TEST_ASSERT_EQUAL_INT(1, get_register_D(&regs));
	TEST_ASSERT_EQUAL_INT(0, get_memory(&ram, 0));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_mnem0_dest111(void)
{
	memory_t ram;
	registers_t regs;
	int16_t instruction_bits;

	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b111, 0b0);

	initialize_memory(&ram, 128);
	initialize_registers(&regs);

	cpu(instruction_bits, 0, &ram, &regs);

	TEST_ASSERT_EQUAL_INT(1, get_register_A(&regs));
	TEST_ASSERT_EQUAL_INT(1, get_register_D(&regs));
	TEST_ASSERT_EQUAL_INT(1, get_memory(&ram, 0));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_mnem1_dest111(void)
{
	memory_t ram;
	registers_t regs;
	int16_t instruction_bits;

	int16_t address = 10;
	int16_t value = 50;

	instruction_bits = set_instruction_bits(0b1, 0b1, 0b110111, 0b111, 0b0);

	initialize_memory(&ram, 128);
	initialize_registers(&regs);

	set_memory(&ram, address, value);
	set_register_A(&regs, address);

	cpu(instruction_bits, 0, &ram, &regs);

	TEST_ASSERT_EQUAL_INT(value + 1, get_register_A(&regs));
	TEST_ASSERT_EQUAL_INT(value + 1, get_register_D(&regs));
	TEST_ASSERT_EQUAL_INT(value + 1, get_memory(&ram, address));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_jump000(void)
{
	// No jumping should occur here
	int16_t value = 27;
	int16_t instruction_bits;

	memory_t ram;
	registers_t regs;

	initialize_memory(&ram, 256);
	initialize_registers(&regs);

	// Set A register to value
	instruction_bits = value;
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(1, get_register_PC(&regs));

	// Output of ALU is -1, thus no jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111010, 0b000, 0b000);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(2, get_register_PC(&regs));

	// Output of ALU is +0, thus no jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b101010, 0b000, 0b000);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(3, get_register_PC(&regs));

	// Output of ALU is +1, thus no jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b000, 0b000);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(4, get_register_PC(&regs));


	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_jump001(void)
{
	// Jump if output of ALU is >0
	int16_t instruction_bits;
	int16_t value = 23;

	memory_t ram;
	registers_t regs;

	initialize_memory(&ram, 256);
	initialize_registers(&regs);

	// Set A register to value
	instruction_bits = value;
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(1, get_register_PC(&regs));

	// Output of ALU is -1, thus no jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111010, 0b000, 0b001);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(2, get_register_PC(&regs));

	// Output of ALU is +0, thus no jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b101010, 0b000, 0b001);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(3, get_register_PC(&regs));

	// Output of ALU is +1, thus yes jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b000, 0b001);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(value, get_register_PC(&regs));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_jump010(void)
{
	// Jump if output of ALU is = 0
	int16_t instruction_bits;
	int16_t value = 23;

	memory_t ram;
	registers_t regs;

	initialize_memory(&ram, 256);
	initialize_registers(&regs);

	// Set A register to value
	instruction_bits = value;
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(1, get_register_PC(&regs));

	// Output of ALU is +1, thus no jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b000, 0b010);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(2, get_register_PC(&regs));

	// Output of ALU is -1, thus no jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111010, 0b000, 0b010);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(3, get_register_PC(&regs));

	// Output of ALU is +0, thus yes jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b101010, 0b000, 0b010);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(value, get_register_PC(&regs));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_jump011(void)
{
	// Jump if output of ALU is >= 0
	int16_t instruction_bits;
	int16_t value = 23;

	memory_t ram;
	registers_t regs;

	initialize_memory(&ram, 256);
	initialize_registers(&regs);

	// Set A register to value
	instruction_bits = value;
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(1, get_register_PC(&regs));

	// Output of ALU is +1, thus yes jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b000, 0b011);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(value, get_register_PC(&regs));

	// Output of ALU is -1, thus no jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111010, 0b000, 0b011);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(value+1, get_register_PC(&regs));

	// Output of ALU is +0, thus yes jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b101010, 0b000, 0b011);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(value, get_register_PC(&regs));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_jump100(void)
{
	// Jump if output of ALU is <0
	int16_t instruction_bits;
	int16_t value = 23;

	memory_t ram;
	registers_t regs;

	initialize_memory(&ram, 256);
	initialize_registers(&regs);

	// Set A register to value
	instruction_bits = value;
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(1, get_register_PC(&regs));

	// Output of ALU is +0, thus no jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b101010, 0b000, 0b100);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(2, get_register_PC(&regs));

	// Output of ALU is +1, thus no jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b000, 0b100);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(3, get_register_PC(&regs));

	// Output of ALU is -1, thus yes jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111010, 0b000, 0b100);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(value, get_register_PC(&regs));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_jump101(void)
{
	// Jump if output of ALU is != 0 (JNE)
	int16_t instruction_bits;
	int16_t value = 23;

	memory_t ram;
	registers_t regs;

	initialize_memory(&ram, 256);
	initialize_registers(&regs);

	// Set A register to value
	instruction_bits = value;
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(1, get_register_PC(&regs));

	// Output of ALU is +0, thus no jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b101010, 0b000, 0b101);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(2, get_register_PC(&regs));

	// Output of ALU is +1, thus yes jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b000, 0b101);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(value, get_register_PC(&regs));

	// Output of ALU is -1, thus yes jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111010, 0b000, 0b101);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(value, get_register_PC(&regs));

	destroy_memory(&ram);
	destroy_registers(&regs);
}

void test_cpu_jump110(void)
{
	// Jump if output of ALU is <= 0 (JLE)
	int16_t instruction_bits;
	int16_t value = 23;

	memory_t ram;
	registers_t regs;

	initialize_memory(&ram, 256);
	initialize_registers(&regs);

	// Set A register to value
	instruction_bits = value;
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(1, get_register_PC(&regs));

	// Output of ALU is +0, thus yes jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b101010, 0b000, 0b110);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(value, get_register_PC(&regs));

	// Output of ALU is +1, thus no jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111111, 0b000, 0b110);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(value+1, get_register_PC(&regs));

	// Output of ALU is -1, thus yes jump
	instruction_bits = set_instruction_bits(0b1, 0b0, 0b111010, 0b000, 0b110);
	cpu(instruction_bits, 0, &ram, &regs);
	TEST_ASSERT_EQUAL_INT(value, get_register_PC(&regs));

	destroy_memory(&ram);
	destroy_registers(&regs);
}



int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_cpu_address_instruction);

	RUN_TEST(test_cpu_mnem0_dest000);
	RUN_TEST(test_cpu_mnem0_dest001);
	RUN_TEST(test_cpu_mnem0_dest010);
	RUN_TEST(test_cpu_mnem0_dest011);
	RUN_TEST(test_cpu_mnem0_dest100);
	RUN_TEST(test_cpu_mnem0_dest101);
	RUN_TEST(test_cpu_mnem0_dest110);
	RUN_TEST(test_cpu_mnem0_dest111);
	RUN_TEST(test_cpu_mnem1_dest111);

	RUN_TEST(test_cpu_jump000);
	RUN_TEST(test_cpu_jump001);
	RUN_TEST(test_cpu_jump010);
	RUN_TEST(test_cpu_jump011);
	RUN_TEST(test_cpu_jump100);
	RUN_TEST(test_cpu_jump101);
	RUN_TEST(test_cpu_jump110);

	return UNITY_END();
}
