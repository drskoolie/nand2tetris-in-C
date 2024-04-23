#include "architecture.h"
#include "arithmetic.h"
#include "memory.h"

void cpu(int16_t instruction_bits, int16_t reset, memory_t *ram, registers_t *regs)
{
	// Instruction Capturing
	int16_t type_of_instruction;
	int16_t mnem_instruction; // Mnemonic Instruction bit
	int16_t comp_instruction;
	int16_t dest_instruction;
	int16_t jump_instruction;

	int16_t x_alu;
	int16_t y_alu;

	type_of_instruction = instruction_bits >> 15;
	mnem_instruction = (instruction_bits & 0b0001000000000000) >> 12;
	comp_instruction = (instruction_bits & 0b0000111111000000) >> 6;
	dest_instruction = (instruction_bits & 0b0000000000111000) >> 3;
	jump_instruction = instruction_bits & 0b0000000000000111;

	//Address Instruction (sets A register)
	if (type_of_instruction == 0) {
		set_register_A(regs, instruction_bits);
	}

	else if (type_of_instruction == 1) {
		x_alu = get_register_D(regs);
		if (mnem_instruction == 1) {
			y_alu = get_register_M(regs);

		}
		else if (mnem_instruction == 0){
			y_alu = get_register_A(regs);
		}
	}
}
